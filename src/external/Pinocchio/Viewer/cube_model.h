#include <GL/gl.h>

static const GLint cube_point_count = 36;

// Vertice Positions
static const GLfloat cube_vp[cube_point_count * 3] = {
     1.0, -1.0, -1.0,
     1.0, -1.0,  1.0,
    -1.0, -1.0, -1.0,
     1.0,  1.0, -1.0,
    -1.0,  1.0, -1.0,
     1.0,  1.0,  1.0,
     1.0, -1.0, -1.0,
     1.0,  1.0, -1.0,
     1.0, -1.0,  1.0,
     1.0, -1.0,  1.0,
     1.0,  1.0,  1.0,
    -1.0, -1.0,  1.0,
    -1.0, -1.0,  1.0,
    -1.0,  1.0,  1.0,
    -1.0, -1.0, -1.0,
     1.0,  1.0, -1.0,
     1.0, -1.0, -1.0,
    -1.0,  1.0, -1.0,
     1.0, -1.0,  1.0,
    -1.0, -1.0,  1.0,
    -1.0, -1.0, -1.0,
    -1.0,  1.0, -1.0,
    -1.0,  1.0,  1.0,
     1.0,  1.0,  1.0,
     1.0,  1.0, -1.0,
     1.0,  1.0,  1.0,
     1.0, -1.0,  1.0,
     1.0,  1.0,  1.0,
    -1.0,  1.0,  1.0,
    -1.0, -1.0,  1.0,
    -1.0,  1.0,  1.0,
    -1.0,  1.0, -1.0,
    -1.0, -1.0, -1.0,
     1.0, -1.0, -1.0,
    -1.0, -1.0, -1.0,
    -1.0,  1.0, -1.0
};

// Textures
static const GLfloat cube_vt[cube_point_count * 2] = {
     0.0,  0.0,
     1.0,  0.0,
     0.0,  1.0,
     0.0,  0.0,
     1.0,  0.0,
     0.0,  1.0,
     0.0,  0.0,
     1.0,  0.0,
     0.0,  1.0,
     0.0,  0.0,
     1.0,  0.0,
     0.0,  1.0,
     0.0,  0.0,
     1.0,  0.0,
     0.0,  1.0,
     0.0,  0.0,
     1.0,  0.0,
     0.0,  1.0,
     1.0,  0.0,
     1.0,  1.0,
     0.0,  1.0,
     1.0,  0.0,
     1.0,  1.0,
     0.0,  1.0,
     1.0,  0.0,
     1.0,  1.0,
     0.0,  1.0,
     1.0,  0.0,
     1.0,  1.0,
     0.0,  1.0,
     1.0,  0.0,
     1.0,  1.0,
     0.0,  1.0,
     1.0,  0.0,
     1.0,  1.0,
     0.0,  1.0
};

// Normal Vectors
static const GLfloat cube_vn[cube_point_count * 3] = {
     0.0, -1.0,  0.0,
     0.0, -1.0,  0.0,
     0.0, -1.0,  0.0,
     0.0,  1.0,  0.0,
     0.0,  1.0,  0.0,
     0.0,  1.0,  0.0,
     1.0, -0.0,  0.0,
     1.0, -0.0,  0.0,
     1.0, -0.0,  0.0,
     0.0, -0.0,  1.0,
     0.0, -0.0,  1.0,
     0.0, -0.0,  1.0,
    -1.0, -0.0, -0.0,
    -1.0, -0.0, -0.0,
    -1.0, -0.0, -0.0,
     0.0,  0.0, -1.0,
     0.0,  0.0, -1.0,
     0.0,  0.0, -1.0,
     0.0, -1.0,  0.0,
     0.0, -1.0,  0.0,
     0.0, -1.0,  0.0,
     0.0,  1.0,  0.0,
     0.0,  1.0,  0.0,
     0.0,  1.0,  0.0,
     1.0,  0.0,  0.0,
     1.0,  0.0,  0.0,
     1.0,  0.0,  0.0,
     0.0, -0.0,  1.0,
     0.0, -0.0,  1.0,
     0.0, -0.0,  1.0,
    -1.0, -0.0, -0.0,
    -1.0, -0.0, -0.0,
    -1.0, -0.0, -0.0,
     0.0,  0.0, -1.0,
     0.0,  0.0, -1.0,
     0.0,  0.0, -1.0
};