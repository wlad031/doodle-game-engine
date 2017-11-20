#include "OpenGlObject.h"

#include <glbinding/gl/gl.h>

namespace systems {
namespace rendering {
namespace engine {
namespace opengl {

OpenGlObject::OpenGlObject(
        const std::shared_ptr<
                systems::rendering::scene::components::MeshEntry
        >& meshEntry
) {

    _nVertices      = meshEntry->getNVertices();
    _nFaces         = meshEntry->getNFaces();
    _nElements      = meshEntry->getNElements();
    _hasVertices    = meshEntry->hasVertices();
    _hasTexCoords   = meshEntry->hasTexCoords();
    _hasNormals     = meshEntry->hasNormals();
    _hasTgsAndBitgs = meshEntry->hasTgsAndBitgs();
    _hasIndices     = meshEntry->hasIndices();

    gl::glGenVertexArrays(1, &_vao);
    gl::glBindVertexArray(_vao);

    if (_hasVertices) {
        gl::glGenBuffers(1, &_vbo[Buffers::VERTEX_BUFFER]);
        gl::glBindBuffer(gl::GL_ARRAY_BUFFER, _vbo[Buffers::VERTEX_BUFFER]);
        gl::glBufferData(
                gl::GL_ARRAY_BUFFER, 3 * _nVertices * sizeof(float),
                &(meshEntry->getVertices()[0]), gl::GL_STATIC_DRAW
        );
        gl::glBindBuffer(gl::GL_ARRAY_BUFFER, 0);
    }

    if (_hasTexCoords) {
        gl::glGenBuffers(1, &_vbo[Buffers::TEXCOORD_BUFFER]);
        gl::glBindBuffer(gl::GL_ARRAY_BUFFER, _vbo[Buffers::TEXCOORD_BUFFER]);
        gl::glBufferData(
                gl::GL_ARRAY_BUFFER, 2 * _nVertices * sizeof(float),
                &(meshEntry->getTexCoords()[0]), gl::GL_STATIC_DRAW
        );
        gl::glBindBuffer(gl::GL_ARRAY_BUFFER, 0);
    }

    if (_hasNormals) {
        gl::glGenBuffers(1, &_vbo[Buffers::NORMAL_BUFFER]);
        gl::glBindBuffer(gl::GL_ARRAY_BUFFER, _vbo[Buffers::NORMAL_BUFFER]);
        gl::glBufferData(
                gl::GL_ARRAY_BUFFER, 3 * _nVertices * sizeof(float),
                &(meshEntry->getNormals()[0]), gl::GL_STATIC_DRAW
        );
        gl::glBindBuffer(gl::GL_ARRAY_BUFFER, 0);
    }

    if (_hasTgsAndBitgs) {
        gl::glGenBuffers(1, &_vbo[Buffers::TANGENT_BUFFER]);
        gl::glBindBuffer(gl::GL_ARRAY_BUFFER, _vbo[Buffers::TANGENT_BUFFER]);
        gl::glBufferData(
                gl::GL_ARRAY_BUFFER, 3 * _nVertices * sizeof(float),
                &(meshEntry->getTgs()[0]), gl::GL_STATIC_DRAW
        );
        gl::glBindBuffer(gl::GL_ARRAY_BUFFER, 0);

        gl::glGenBuffers(1, &_vbo[Buffers::BITANGENT_BUFFER]);
        gl::glBindBuffer(gl::GL_ARRAY_BUFFER, _vbo[Buffers::BITANGENT_BUFFER]);
        gl::glBufferData(
                gl::GL_ARRAY_BUFFER, 3 * _nVertices * sizeof(float),
                &(meshEntry->getBitgs()[0]), gl::GL_STATIC_DRAW
        );
        gl::glBindBuffer(gl::GL_ARRAY_BUFFER, 0);
    }

    if (_hasIndices) {
        gl::glGenBuffers(1, &_vbo[Buffers::INDEX_BUFFER]);
        gl::glBindBuffer(
                gl::GL_ELEMENT_ARRAY_BUFFER,
                _vbo[Buffers::INDEX_BUFFER]
        );
        gl::glBufferData(
                gl::GL_ELEMENT_ARRAY_BUFFER, 3 * _nFaces * sizeof(uint),
                &(meshEntry->getIndices()[0]), gl::GL_STATIC_DRAW
        );
        gl::glBindBuffer(gl::GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    gl::glBindVertexArray(0);
}

void OpenGlObject::render(
        const std::shared_ptr<
                systems::rendering::engine::opengl::OpenGlProgram
        >& shaderProgram
) {
    unsigned int positionAttributeId  = 0;
    unsigned int texCoordAttributeId  = 0;
    unsigned int normalAttributeId    = 0;
    unsigned int tangentAttributeId   = 0;
    unsigned int bitangentAttributeId = 0;

    if (_hasVertices)
        positionAttributeId = shaderProgram->getAttributeId("Position");
    if (_hasTexCoords)
        texCoordAttributeId = shaderProgram->getAttributeId("TexCoord");
    if (_hasNormals)
        normalAttributeId   = shaderProgram->getAttributeId("Normal");
    if (_hasTgsAndBitgs) {
        tangentAttributeId   = shaderProgram->getAttributeId("Tangent");
        bitangentAttributeId = shaderProgram->getAttributeId("Bitangent");
    }

    gl::glBindVertexArray(_vao);

    if (_hasVertices) {
        gl::glEnableVertexAttribArray(positionAttributeId);
        gl::glBindBuffer(gl::GL_ARRAY_BUFFER, _vbo[Buffers::VERTEX_BUFFER]);
        gl::glVertexAttribPointer(
                positionAttributeId,
                3,
                gl::GL_FLOAT,
                gl::GL_FALSE,
                0,
                nullptr
        );
    }

    if (_hasTexCoords) {
        gl::glEnableVertexAttribArray(texCoordAttributeId);
        gl::glBindBuffer(gl::GL_ARRAY_BUFFER, _vbo[Buffers::TEXCOORD_BUFFER]);
        gl::glVertexAttribPointer(
                texCoordAttributeId,
                2,
                gl::GL_FLOAT,
                gl::GL_FALSE,
                0,
                nullptr
        );
    }

    if (_hasNormals) {
        gl::glEnableVertexAttribArray(normalAttributeId);
        gl::glBindBuffer(gl::GL_ARRAY_BUFFER, _vbo[Buffers::NORMAL_BUFFER]);
        gl::glVertexAttribPointer(
                normalAttributeId,
                3,
                gl::GL_FLOAT,
                gl::GL_TRUE,
                0,
                nullptr
        );
    }

    if (_hasTgsAndBitgs) {
        gl::glEnableVertexAttribArray(tangentAttributeId);
        gl::glBindBuffer(gl::GL_ARRAY_BUFFER, _vbo[Buffers::TANGENT_BUFFER]);
        gl::glVertexAttribPointer(
                tangentAttributeId,
                3,
                gl::GL_FLOAT,
                gl::GL_TRUE,
                0,
                nullptr
        );

        gl::glEnableVertexAttribArray(bitangentAttributeId);
        gl::glBindBuffer(gl::GL_ARRAY_BUFFER, _vbo[Buffers::BITANGENT_BUFFER]);
        gl::glVertexAttribPointer(
                bitangentAttributeId,
                3,
                gl::GL_FLOAT,
                gl::GL_TRUE,
                0,
                nullptr
        );
    }

    if (_hasIndices)
        gl::glBindBuffer(
                gl::GL_ELEMENT_ARRAY_BUFFER,
                _vbo[Buffers::INDEX_BUFFER]
        );

    gl::glDrawElements(
            gl::GL_TRIANGLES,
            _nElements,
            gl::GL_UNSIGNED_INT,
            nullptr
    );

    gl::glBindBuffer(gl::GL_ARRAY_BUFFER, 0);

    if (_hasVertices) gl::glDisableVertexAttribArray(positionAttributeId);
    if (_hasTexCoords) gl::glDisableVertexAttribArray(texCoordAttributeId);
    if (_hasNormals) gl::glDisableVertexAttribArray(normalAttributeId);
    if (_hasTgsAndBitgs) {
        gl::glDisableVertexAttribArray(tangentAttributeId);
        gl::glDisableVertexAttribArray(bitangentAttributeId);
    }
    if (_hasIndices) gl::glBindBuffer(gl::GL_ELEMENT_ARRAY_BUFFER, 0);

    gl::glBindVertexArray(0);
}

}  // namespace opengl
}  // namespace engine
}  // namespace rendering
}  // namespace systems
