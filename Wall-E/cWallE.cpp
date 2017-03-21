#include "cWallE.h"

WallE::WallE(){
  
    // Reserve RAM for NUM_CUBE
    cubs = new Cube*[NUM_CUBES];
    cyls = new Cylinder*[NUM_CYLINDERS];
    int i;
    for(i=0; i<NUM_CUBES;i++){
        cubs[i] = new Cube();
    }
    for(i = 0;i<NUM_CYLINDERS;i++){
        cyls[i] = new Cylinder();
    }
    
    mat_orange_diff = new float[4];
    mat_orange_diff[0] = 255.0f/255.0f;
    mat_orange_diff[1] = 150.0f/255.0f;
    mat_orange_diff[2] = 48.0f/255.0f;
    mat_orange_diff[3] = 1.0f;
    
    mat_orange_spec = new float[4];
    mat_orange_spec[0] = 0.1f;
    mat_orange_spec[1] = 0.1f;
    mat_orange_spec[2] = 0.1f;
    mat_orange_spec[3] = 1.0f;
    
    mat_orange_ambi = new float[4];
    mat_orange_ambi[0] = 0.1f;
    mat_orange_ambi[1] = 0.1f;
    mat_orange_ambi[2] = 0.1f;
    mat_orange_ambi[3] = 1.0f;
    
    mat_orange_shin = new float[1];
    mat_orange_shin[0] = 50.0f;
    
    
    mat_brown_diff = new float[4];
    mat_brown_spec = new float[4];
    mat_brown_ambi = new float[4];
    mat_brown_shin = new float[4];
    
    mat_brown_diff[0] = 0.780392f;
    mat_brown_diff[1] = 0.568627f;
    mat_brown_diff[2] = 0.113725f;
    mat_brown_diff[3] = 1.0f;
    
    mat_brown_ambi[0] = 0.329412f;
    mat_brown_ambi[1] = 0.223529f;
    mat_brown_ambi[2] = 0.027451f;
    mat_brown_ambi[3] = 1.0f;
    
    mat_brown_spec[0] = 0.992157f;
    mat_brown_spec[1] = 0.941176f;
    mat_brown_spec[2] = 0.807843f;
    mat_brown_spec[3] = 1.0f;
    
    mat_brown_shin[0] = 0.2179872;
    
    mat_metal_ambi = new float[4];
    mat_metal_diff = new float[4];
    mat_metal_spec = new float[4];
    mat_metal_shin = new float[1];

    mat_metal_ambi[0] = 0.25f;
    mat_metal_ambi[1] = 0.20725f;
    mat_metal_ambi[2] = 0.20725f;
    mat_metal_ambi[3] = 1.0f;
    
    mat_metal_diff[0] = 1.0f;
    mat_metal_diff[1] = 0.829f;
    mat_metal_diff[2] = 0.829f;
    mat_metal_diff[3] = 1.0f;
    
    mat_metal_spec[0] = 0.296648f;
    mat_metal_spec[1] = 0.296648f;
    mat_metal_spec[2] = 0.296648f;
    mat_metal_spec[3] = 1.0f;
    
    mat_metal_shin[0] = 0.88f;
    
    mat_eyes_ambi = new float[4];
    mat_eyes_diff = new float[4];
    mat_eyes_spec = new float[4];
    mat_eyes_shin = new float[1];
    
    mat_eyes_ambi[0] = 0.1745f;
    mat_eyes_ambi[1] = 0.01175f;
    mat_eyes_ambi[2] = 0.01175f;
    mat_eyes_ambi[3] = 1.0f;
    
    mat_eyes_diff[0] = 0.61424f;
    mat_eyes_diff[1] = 0.04136f;
    mat_eyes_diff[2] = 0.04136f;
    mat_eyes_diff[3] = 1.0f;
    
    mat_eyes_spec[0] = 0.727811f;
    mat_eyes_spec[1] = 0.626959f;
    mat_eyes_spec[2] = 0.626959f;
    mat_eyes_spec[3] = 1.0f;
    
    mat_eyes_shin[0] = 0.6f;
    
}



WallE::~WallE(){
    delete cubs;
    delete cyls;
}

void WallE::update(){
    /*
     Anim
     */
}

void setMaterial(float *diff, float *spec, float *ambient, float *shin){
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shin);
}

void WallE::draw(){
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glPushMatrix(); //WALLE
    {
        glPushMatrix(); //Body
        {
            glScaled(1.0f, 0.8f, 1.0f);
            setMaterial(mat_orange_diff,
                        mat_orange_spec, mat_orange_ambi, mat_orange_shin);
            cubs[BODY] -> draw();
            
            glPushMatrix(); //LBIG
            {
                glTranslated(-0.6, -0.6, -0.2);
                setMaterial(mat_brown_diff, mat_brown_diff, mat_brown_ambi, mat_brown_shin);
                glRotated(90, 0, 0, 1);
                glScaled(0.4, 0.16, 0.4);
                cyls[LBIG] -> draw();
            }
            glPopMatrix();
            
            glPushMatrix(); //LSMALL1
            {
                glTranslated(-0.6, -0.2, -0.2);
                setMaterial(mat_brown_diff, mat_brown_diff, mat_brown_ambi, mat_brown_shin);
                glRotated(90, 0, 0, 1);
                glScaled(0.2, 0.2, 0.2);
                cyls[LSMALL1] -> draw();
            }
            glPopMatrix();
            
            
            glPushMatrix(); //LSMALL2
            {
                glTranslated(-0.6, -0.4, 0.1);
                setMaterial(mat_brown_diff, mat_brown_diff, mat_brown_ambi, mat_brown_shin);
                glRotated(90, 0, 0, 1);
                glScaled(0.2, 0.2, 0.2);
                cyls[LSMALL2] -> draw();
            }
            glPopMatrix();
            
            
            glPushMatrix(); //LSMALL3
            {
                glTranslated(-0.6, -0.7, 0.3);
                setMaterial(mat_brown_diff, mat_brown_diff, mat_brown_ambi, mat_brown_shin);
                glRotated(90, 0, 0, 1);
                glScaled(0.3, 0.2, 0.3);
                cyls[LSMALL3] -> draw();
            }
            glPopMatrix();
            
            
            glPushMatrix(); //RBIG
            {
                glTranslated(0.6, -0.6, -0.2);
                setMaterial(mat_brown_diff, mat_brown_diff, mat_brown_ambi, mat_brown_shin);
                glRotated(90, 0, 0, 1);
                glScaled(0.4, 0.16, 0.4);
                cyls[RBIG] -> draw();
            }
            glPopMatrix();
            
            
            glPushMatrix(); //RSMALL1
            {
                glTranslated(0.6, -0.2, -0.2);
                setMaterial(mat_brown_diff, mat_brown_diff, mat_brown_ambi, mat_brown_shin);
                glRotated(90, 0, 0, 1);
                glScaled(0.2, 0.2, 0.2);
                cyls[RSMALL1] -> draw();
            }
            glPopMatrix();
            
            
            glPushMatrix(); //RSMALL2
            {
                glTranslated(0.6, -0.4, 0.1);
                setMaterial(mat_brown_diff, mat_brown_diff, mat_brown_ambi, mat_brown_shin);
                glRotated(90, 0, 0, 1);
                glScaled(0.2, 0.2, 0.2);
                cyls[RSMALL2] -> draw();
            }
            glPopMatrix();
            
            
            glPushMatrix(); //RSMALL3
            {
                glTranslated(0.6, -0.7, 0.3);
                setMaterial(mat_brown_diff, mat_brown_diff, mat_brown_ambi, mat_brown_shin);
                glRotated(90, 0, 0, 1);
                glScaled(0.3, 0.2, 0.3);
                cyls[RSMALL3] -> draw();
            }
            glPopMatrix();
                        
            
            glPushMatrix(); //LARM
            {
                glTranslated(-0.5, 0.25, 0.17);
                setMaterial(mat_brown_diff, mat_brown_diff, mat_brown_ambi, mat_brown_shin);
                glRotated(0, 0, 0, 1);
                glScaled(1.2, 0.20, 0.12);
                cubs[LARM] -> draw();
            }
            glPopMatrix();
            
            glPushMatrix(); //LWRIST
            {
                glTranslated(-1.0, 0.25, 0.17);
                setMaterial(mat_metal_shin, mat_metal_diff, mat_metal_ambi, mat_metal_shin);
                glRotated(90, 0, 0, 1);
                glScalef(.15, .25, .15);
                cyls[LWRIST] -> draw();
            }
            glPopMatrix();
            
            glPushMatrix(); //LHAND
            {
                glTranslated(-1.35, 0.25, 0.17);
                setMaterial(mat_metal_shin, mat_metal_diff, mat_metal_ambi, mat_metal_shin);
                glRotated(90, 0, 0, 1);
                glScaled(0.4, 0.4, 0.1);
                cubs[LHAND] -> draw();
            }
            glPopMatrix();
            
            
            
            glPushMatrix(); //RARM
            {
                glTranslated(0.5, 0.25, 0.17);
                setMaterial(mat_brown_diff, mat_brown_diff, mat_brown_ambi, mat_brown_shin);
                glRotated(0, 0, 0, 1);
                glScaled(1.2, 0.20, 0.12);
                cubs[RARM] -> draw();
            }
            glPopMatrix();
            
            glPushMatrix(); //RWRIST
            {
                glTranslated(1.0, 0.25, 0.17);
                setMaterial(mat_metal_shin, mat_metal_diff, mat_metal_ambi, mat_metal_shin);
                glRotated(90, 0, 0, 1);
                glScalef(.15, .25, .15);
                cyls[LWRIST] -> draw();
            }
            glPopMatrix();
            
            glPushMatrix(); //RHAND
            {
                glTranslated(1.35, 0.25, 0.17);
                setMaterial(mat_metal_shin, mat_metal_diff, mat_metal_ambi, mat_metal_shin);
                glRotated(90, 0, 0, 1);
                glScaled(0.4, 0.4, 0.1);
                cubs[LHAND] -> draw();
            }
            glPopMatrix();
            
            
            glPushMatrix(); //DOOR
            {
                glTranslated(0, -0.25, 0.55);
                setMaterial(mat_brown_diff, mat_brown_diff, mat_brown_ambi, mat_brown_shin);
                glRotated(0, 0, 0, 1);
                glScaled(1.0f, 0.5, 0.1f);
                cubs[DOOR] -> draw();
            }
            glPopMatrix();
            
            glPushMatrix(); //NECK1
            {
                glTranslated(0.0, 0.70, 0.0);
                setMaterial(mat_brown_diff, mat_brown_diff, mat_brown_ambi, mat_brown_shin);
                glRotated(0, 0, 0, 1);
                glScalef(0.2, 0.25, 0.2);
                cyls[NECK1] -> draw();
            }
            glPopMatrix();
            
            glPushMatrix(); //NECK2
            {
                glTranslated(0.0, 0.95, 0.0);
                setMaterial(mat_metal_shin, mat_metal_diff, mat_metal_ambi, mat_metal_shin);
                glRotated(-90, 0, 0, 1);
                glScalef(0.15, 0.1, 0.15);
                cyls[NECK2] -> draw();
            }
            glPopMatrix();
            
            glPushMatrix(); //NECK3
            {
                glTranslated(0.0, 1.1, 0.0);
                setMaterial(mat_brown_diff, mat_brown_diff, mat_brown_ambi, mat_brown_shin);
                glRotated(0, 0, 0, 1);
                glScalef(0.2, 0.15, 0.2);
                cyls[NECK3] -> draw();
            }
            glPopMatrix();
            
            glPushMatrix(); //NOSE
            {
                glTranslated(0.0, 1.3, 0.0);
                //setMaterial(mat_metal_shin, mat_metal_diff, mat_metal_ambi, mat_metal_shin);
                setMaterial(mat_brown_diff, mat_brown_diff, mat_brown_ambi, mat_brown_shin);
                glRotated(90, 90, 0, 1);
                glScalef(0.2, 0.1, 0.2);
                cyls[NOSE] -> draw();
            }
            glPopMatrix();
            
            glPushMatrix(); //LFACE_CYL
            {
                glTranslated(-0.25, 1.275, -0.17);
                setMaterial(mat_metal_shin, mat_metal_diff, mat_metal_ambi, mat_metal_shin);
                //bsetMaterial(mat_brown_diff, mat_brown_diff, mat_brown_ambi, mat_brown_shin);
                glRotated(90, 90, 0, 1);
                glScalef(0.40, 0.35, 0.40);
                cyls[LFACE_CYL] -> draw();
            }
            glPopMatrix();
            
            
            glPushMatrix(); //LFACE_CUBE
            {
                glTranslated(-0.22, 1.3, -0.15);
                setMaterial(mat_brown_diff, mat_brown_diff, mat_brown_ambi, mat_brown_shin);
                glRotated(0, 0, 0, 1);
                glScalef(0.35, 0.35, 0.5);
                cubs[LFACE_CUBE] -> draw();
            }
            glPopMatrix();
            
            glPushMatrix(); //LEYE
            {
                glTranslated(-0.20, 1.3, -0.045);
                setMaterial(mat_eyes_shin, mat_eyes_diff, mat_eyes_ambi, mat_eyes_shin);
                glRotated(90, 90, 0, 1);
                glScalef(0.25, 0.20, 0.25);
                cyls[LEYE] -> draw();
            }
            glPopMatrix();
            
            
            
            glPushMatrix(); //LFACE_CYL
            {
                glTranslated(0.25, 1.275, -0.17);
                setMaterial(mat_metal_shin, mat_metal_diff, mat_metal_ambi, mat_metal_shin);
                //bsetMaterial(mat_brown_diff, mat_brown_diff, mat_brown_ambi, mat_brown_shin);
                glRotated(90, 90, 0, 1);
                glScalef(0.40, 0.35, 0.40);
                cyls[LFACE_CYL] -> draw();
            }
            glPopMatrix();
            
            
            glPushMatrix(); //LFACE_CUBE
            {
                glTranslated(0.22, 1.3, -0.15);
                setMaterial(mat_brown_diff, mat_brown_diff, mat_brown_ambi, mat_brown_shin);
                glRotated(0, 0, 0, 1);
                glScalef(0.35, 0.35, 0.5);
                cubs[LFACE_CUBE] -> draw();
            }
            glPopMatrix();
            
            glPushMatrix(); //LEYE
            {
                glTranslated(0.20, 1.3, -0.045);
                setMaterial(mat_eyes_shin, mat_eyes_diff, mat_eyes_ambi, mat_eyes_shin);
                glRotated(90, 90, 0, 1);
                glScalef(0.25, 0.20, 0.25);
                cyls[LEYE] -> draw();
            }
            glPopMatrix();
        
            
            
        }
        glPopMatrix();
    }
    glPopMatrix();
}































