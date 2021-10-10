#include "mesh.hpp"

#include <gl/glad.h>

Mesh::Mesh(std::vector<float> vertices, std::vector<int> indices, std::vector<float> texcoords) {
    
    glGenVertexArrays(1, &vao);

    glBindVertexArray(vao);

    // Vertices
    glGenBuffers(1, &vertices_id);
    glBindBuffer(GL_ARRAY_BUFFER, vertices_id);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof (float), vertices.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(0, 2, GL_FLOAT, 0, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Indices
    glGenBuffers(1, &index_id);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof (int), indices.data(), GL_STATIC_DRAW);

    indices_ct = indices.size();

    // Texture coordinates
    glGenBuffers(1, &texcoords_id);
    glBindBuffer(GL_ARRAY_BUFFER, texcoords_id);
        glBufferData(GL_ARRAY_BUFFER, texcoords.size() * sizeof (float), texcoords.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(1, 2, GL_FLOAT, 0, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}

void Mesh::draw() {

    glBindVertexArray(vao);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glDrawElements(GL_TRIANGLES, indices_ct, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    
}

Mesh::~Mesh() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &vertices_id);
    glDeleteBuffers(1, &index_id);
    glDeleteBuffers(1, &texcoords_id);
    glBindVertexArray(0);
    glDeleteVertexArrays(1, &vao);
}