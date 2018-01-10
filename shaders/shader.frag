#version 410 core

#define GAMMA 2.2

#define DIRECT_LIGHT 0
#define POINT_LIGHT  1
#define SPOT_LIGHT   2

struct MaterialType {
    sampler2D Texture;
    sampler2D NormalMap;
    vec4 Ambient;
    vec4 Diffuse;
    vec4 Specular;
    vec4 Emission;
    float Shininess;
};

struct CameraType {
    vec3 NormalPosition;
};

struct VertexType {
    vec3 Position;
    vec2 TexCoord;
    vec3 Normal;
    vec3 Tangent;
    vec3 Bitangent;
};

struct LightType {
    uint Type;
    vec3 Position;
    vec4 Ambient;
    vec4 Diffuse;
    vec4 Specular;
    float ConstantAttenuation;
    float LinearAttenuation;
    float QuadraticAttenuation;
    vec3 SpotDirection;
    float SpotCutoff;
    float SpotExponent;
};

in CameraType Camera;
in VertexType Vertex;

uniform LightType Light;
uniform MaterialType Material;

out vec4 Color;

vec3 calcBumpedNormal();
float calcPointAttenuation(
        float constantAttenuation,
        float linearAttenuation,
        float quadraticAttenuation,
        float d
);
float calcSpotAttenuation(
        vec3 spotDirection,
        vec3 lightDirection,
        float spotCutoff,
        float d
);

vec4 applyDirectLight();
vec4 applyPointLight();
vec4 applySpotLight();

void main() {
    vec4 lightColor;

    if (Light.Type == DIRECT_LIGHT) {
        lightColor = applyDirectLight();
    } else if (Light.Type == POINT_LIGHT) {
        lightColor = applyPointLight();
    } else if (Light.Type == SPOT_LIGHT) {
        lightColor = applySpotLight();
    } else {
        lightColor = vec4(0);
    }

    vec4 textureColor = texture(Material.Texture, vec2(Vertex.TexCoord.s, 1.0 - Vertex.TexCoord.t));
    vec4 emission = Material.Emission;

    Color = vec4(1.0, 0.0, 0.0, 1.0)*0.5 + 1e-5 * textureColor + 0.5 * lightColor + emission;
}

vec3 calcBumpedNormal() {
    vec3 normal = normalize(Vertex.Normal);

    vec3 tangent = normalize(Vertex.Tangent);
    tangent = normalize(tangent - dot(tangent, normal) * normal);
    vec3 bitangent = normalize(Vertex.Bitangent);
    bitangent = normalize(bitangent - dot(bitangent, normal) * normal);

    vec3 bumpMapNormal = texture(Material.NormalMap, vec2(Vertex.TexCoord.s, 1.0 - Vertex.TexCoord.t)).xyz;
    bumpMapNormal = 2.0 * bumpMapNormal - vec3(1.0, 1.0, 1.0);

    mat3 tbnMatrix = mat3(tangent, bitangent, normal);

    vec3 newNormal = tbnMatrix * bumpMapNormal;
    newNormal = normalize(newNormal);

    return newNormal;
}

float calcPointAttenuation(
        float constantAttenuation,
        float linearAttenuation,
        float quadraticAttenuation,
        float d
) {
    return 1.0f / (constantAttenuation
                 + linearAttenuation    * d
                 + quadraticAttenuation * d * d);
}

float calcSpotAttenuation(
        vec3 spotDirection,
        vec3 lightDirection,
        float spotCutoff,
        float d
) {
    float spotAngleCos = dot(normalize(spotDirection), normalize(lightDirection));
    if (spotAngleCos > spotCutoff) {
        return 1.0 - 1.0 * (1.0 - spotAngleCos) / (1.0 - spotCutoff);
    }
    return 0.0;
}

vec4 applyDirectLight() {
    vec4 surfaceToCamera = vec4(normalize(Camera.NormalPosition - Vertex.Position), 1.0);
    vec3 normal = calcBumpedNormal();

    vec4 ambient;
    vec4 diffuse;
    vec4 specular;

    vec3 surfaceToLight = normalize(Light.Position.xyz);

    // Calculate ambient
    ambient = Light.Ambient * Material.Ambient;

    // Calculate diffuse
    float diffuseCoefficient = max(0.0, dot(normal, surfaceToLight));
    diffuse = diffuseCoefficient * Material.Diffuse * Light.Diffuse;
    diffuse = pow(diffuse, vec4(GAMMA));

    // Calculate specular
    float specularCoefficient = 0.0;
    if (diffuseCoefficient > 0.0) {
        specularCoefficient = max(0.0, dot(vec3(surfaceToCamera),
                                           reflect(-surfaceToLight, normal)));
    }
    specularCoefficient = pow(specularCoefficient, Material.Shininess);
    specular = specularCoefficient * Material.Specular * Light.Specular;

    return ambient + diffuse + specular;
}

vec4 applyPointLight() {
    vec4 surfaceToCamera = vec4(normalize(Camera.NormalPosition - Vertex.Position), 1.0);
    vec3 normal = calcBumpedNormal();

    vec4 ambient;
    vec4 diffuse;
    vec4 specular;

    vec3 lightDirection = normalize(Vertex.Position - Light.Position.xyz);
    float distance = length(Vertex.Position - Light.Position.xyz);

    // Calculate ambient
    ambient = Light.Ambient * Material.Ambient;

    // Calculate diffuse
    float diffuseCoefficient = max(0.0, dot(normal, -lightDirection));
    diffuse = diffuseCoefficient * Material.Diffuse * Light.Diffuse;
    diffuse = pow(diffuse, vec4(GAMMA));

    // Calculate specular
    float specularCoefficient = 0.0;
    if (diffuseCoefficient > 0.0) {
        specularCoefficient = max(0.0, dot(vec3(surfaceToCamera),
                                           reflect(-lightDirection, normal)));
    }
    specularCoefficient = pow(specularCoefficient, Material.Shininess);
    specular = specularCoefficient * Material.Specular * Light.Specular;

    float pointAttenuation = calcPointAttenuation(
            Light.ConstantAttenuation,
            Light.LinearAttenuation,
            Light.QuadraticAttenuation,
            distance
    );

    return pointAttenuation * (ambient + diffuse + specular);
}

vec4 applySpotLight() {
    vec4 surfaceToCamera = vec4(normalize(Camera.NormalPosition - Vertex.Position), 1.0);
    vec3 normal = calcBumpedNormal();

    vec4 ambient;
    vec4 diffuse;
    vec4 specular;

    vec3 lightDirection = normalize(Vertex.Position - Light.Position.xyz);
    float distance = length(Vertex.Position - Light.Position.xyz);

    // Calculate ambient
    ambient = Light.Ambient * Material.Ambient;

    // Calculate diffuse
    float diffuseCoefficient = max(0.0, dot(normal, -lightDirection));
    diffuse = diffuseCoefficient * Material.Diffuse * Light.Diffuse;
    diffuse = pow(diffuse, vec4(GAMMA));

    // Calculate specular
    float specularCoefficient = 0.0;
    if (diffuseCoefficient > 0.0) {
        specularCoefficient = max(0.0, dot(vec3(surfaceToCamera),
                                           reflect(-lightDirection, normal)));
    }
    specularCoefficient = pow(specularCoefficient, Material.Shininess);
    specular = specularCoefficient * Material.Specular * Light.Specular;

    float pointAttenuation = calcPointAttenuation(
            Light.ConstantAttenuation,
            Light.LinearAttenuation,
            Light.QuadraticAttenuation,
            distance
     );
    float spotAttenuation = calcSpotAttenuation(
            Light.SpotDirection,
            lightDirection,
            radians(Light.SpotCutoff),
            distance
    );

    return (ambient + pointAttenuation * spotAttenuation * (diffuse + specular) * Light.SpotExponent);
}