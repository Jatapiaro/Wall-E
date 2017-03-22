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

#define NUM_CUBES 6
#define NUM_CYLINDERS 1

class Luxo{
public:
    Luxo();
    ~Luxo();
    
    void draw();
    void update();
    
    static enum CUBES_E{
        FIRSTLEG,SECONDLEG,THIRDLEG,NECK,NECK2,FACE
    };
    
    Cube **cubs;
    Cylinder *cyl;
    
    float *mat_metal_diff;
    float *mat_metal_spec;
    float *mat_metal_ambi;
    float *mat_metal_shin;
    
};
