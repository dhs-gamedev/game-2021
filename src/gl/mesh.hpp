/**
 * Create meshes to send data to OpenGL.
 */

#pragma once

#include <vector>

class Mesh {

private:
    unsigned vao, vertices_id, index_id, texcoords_id, indices_ct;

public:
    Mesh(std::vector<float> vertices, std::vector<int> indices, std::vector<float> texcoords);
    void draw();
    ~Mesh();

};