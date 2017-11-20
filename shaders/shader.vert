#version 410 core

struct MatrixType{
    mat4 Model;
    mat4 View;
    mat4 Projection;
};

struct VertexType{
    vec3 Position;
    vec2 TexCoord;
    vec3 Normal;
    vec3 Tangent;
    vec3 Bitangent;
};

layout(location = 1) in vec3 Position;
layout(location = 2) in vec2 TexCoord;
layout(location = 3) in vec3 Normal;
layout(location = 4) in vec3 Tangent;
layout(location = 5) in vec3 Bitangent;

uniform MatrixType Matrix;

out VertexType Vertex;

void main() {
    mat4 mvpMatrix = Matrix.Projection * Matrix.View * Matrix.Model;
    mat3 glNormalMatrix = transpose(inverse(mat3(Matrix.View)));

    vec4 position = Matrix.Model * vec4(Position, 1.0);
    vec4 normal = Matrix.Model * vec4(Normal, 0.0);
    vec4 tangent = Matrix.Model * vec4(Tangent, 0.0);
    vec4 bitangent = Matrix.Model * vec4(Bitangent, 0.0);

    Vertex.Position = position.xyz;
    Vertex.TexCoord = TexCoord;
    Vertex.Normal = normalize(normal.xyz);
    Vertex.Tangent = normalize(tangent.xyz);
    Vertex.Bitangent = normalize(bitangent.xyz);

    gl_Position = vec4(Position, 1.0);
}