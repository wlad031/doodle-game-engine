#version 410 core

struct VertexType{
    vec3 Position;
    vec2 TexCoord;
    vec3 Normal;
    vec3 Tangent;
    vec3 Bitangent;
};

in VertexType Vertex;

out vec4 Color;

void main() {
    vec4 f = vec4(Vertex.TexCoord * 0.001, 0, 0) + vec4(Vertex.Normal * 0.001, 0) + vec4(Vertex.Tangent * 0.001, 0) + vec4(Vertex.Bitangent * 0.001, 0);

    Color = vec4(1.0,0.0,0.0,1.0) + f * 0.0001;
}
