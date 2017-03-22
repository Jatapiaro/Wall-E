#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include "freeglut.h"
#endif

#include <stdio.h>
#include "cCube.h"
#include "cCylinder.h"

#define NUM_CUBE 6
#define NUM_CYLINDER 1

class Luxo{
public:
    Luxo();
    ~Luxo();
    
    void draw();
    void update();
    
    static enum CUBES_L{
        FIRSTLEG,SECONDLEG,THIRDLEG,NECK,NECK2,FACE
    };
    
    Cube **cubs;
    Cylinder *cyl;
    
    float *mat_metal_diff;
    float *mat_metal_spec;
    float *mat_metal_ambi;
    float *mat_metal_shin;
    
};
