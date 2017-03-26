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

#define NUM_CUBES 8
#define NUM_CYLINDERS 18

class WallE{
public:
    WallE();
    ~WallE();
    
    void draw();
    void update();
    
    static enum CUBES_E{
        BODY,LARM,RARM,LHAND,RHAND,
        DOOR,LFACE_CUBE,RFACE_CUBE
    };
    
    static enum CYLINDERS_E{
        LBIG,LSMALL1,LSMALL2,LSMALL3,RBIG,RSMALL1,
        RSMALL2,RSMALL3,LWRIST,RWRIST,NECK1,NECK2,NECK3,
        NOSE,LFACE_CYL,LEYE,RFACE_CYL,REYE
    };
    
    Cube **cubs; //Array of cubes (double pointer)
    Cylinder **cyls;
    
    float *mat_orange_diff;
    float *mat_orange_spec;
    float *mat_orange_ambi;
    float *mat_orange_shin;
    
    float *mat_brown_diff;
    float *mat_brown_spec;
    float *mat_brown_ambi;
    float *mat_brown_shin;
    
    float *mat_metal_diff;
    float *mat_metal_spec;
    float *mat_metal_ambi;
    float *mat_metal_shin;
    
    float *mat_eyes_diff;
    float *mat_eyes_spec;
    float *mat_eyes_ambi;
    float *mat_eyes_shin;
    
    float lx,ly,lz;
    
    float cabezAngle;
    float bodyAngle;
    float hide;
    int cabezaFlag;
    float brazoAngle,brazoAngle2,doorAng;
    
    float pos,pos2;
    
    int frames;
    
    bool appear,cabezaLoca;
    
};
