#include "cLuxo.h"

Luxo::Luxo()
{
    cubs = new Cube*[NUM_CUBE];
    cyl = new Cylinder();
    for(int i=0;i<NUM_CUBE;i++){
        cubs[i] = new Cube();
    }
    mat_metal_ambi = new float[4];
    mat_metal_diff = new float[4];
    mat_metal_spec = new float[4];
    mat_metal_shin = new float[1];
    
    mat_metal_ambi[0] = 0.25f;
    mat_metal_ambi[1] = 0.25f;
    mat_metal_ambi[2] = 0.25f;
    mat_metal_ambi[3] = 1.0f;
    
    mat_metal_diff[0] = 0.4f;
    mat_metal_diff[1] = 0.4f;
    mat_metal_diff[2] = 0.4f;
    mat_metal_diff[3] = 1.0f;
    
    mat_metal_spec[0] = 0.0f;
    mat_metal_spec[1] = 0.0f;
    mat_metal_spec[2] = 0.0f;
    mat_metal_spec[3] = 1.0f;
    mat_metal_shin[0] = 0.6f;
}

Luxo::~Luxo(){
    delete cubs;
    delete cyl;
}

void setMaterial2(float *diff, float *spec, float *ambient, float *shin){
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shin);
}

void Luxo::draw()
{
    glPushMatrix();
    {
        glPushMatrix();
        {
            glTranslated(0,-2,-1);
            setMaterial2(mat_metal_diff, mat_metal_spec, mat_metal_ambi, mat_metal_shin);
            glRotated(0, 0, 0, 1);
            glScaled(1, 0.1, 1);
            cyl -> draw();
        }
        glPopMatrix();
        
        glPushMatrix();
        {
            glTranslated(0,-1.85,-1);
            setMaterial2(mat_metal_diff, mat_metal_spec, mat_metal_ambi, mat_metal_shin);
            glRotated(90, 0, 0, 1);
            glScaled(0.2, 0.10, 0.12);
            cubs[FIRSTLEG] -> draw();
        }
        glPopMatrix();
        
        glPushMatrix();
        {
            glTranslated(-0.13,-1.60,-1);
            setMaterial2(mat_metal_diff, mat_metal_spec, mat_metal_ambi, mat_metal_shin);
            glRotated(-51, 0, 0, 1);
            glScaled(0.5, 0.05, 0.12);
            cubs[SECONDLEG] -> draw();
        }
        glPopMatrix();
        
        glPushMatrix();
        {
            glTranslated(0.05,-1.7,-1);
            setMaterial2(mat_metal_diff, mat_metal_spec, mat_metal_ambi, mat_metal_shin);
            glRotated(40, 0, 0, 1);
            glScaled(0.15, 0.05, 0.12);
            cubs[SECONDLEG_AUX] -> draw();
        }
        glPopMatrix();
        
        glPushMatrix();
        {
            glTranslated(0,-1.50,-1);
            setMaterial2(mat_metal_diff, mat_metal_spec, mat_metal_ambi, mat_metal_shin);
            glRotated(120, 0, 0, 1);
            glScaled(0.37, 0.05, 0.12);
            cubs[SECONDLEG_AUX2] -> draw();
        }
        glPopMatrix();
        
        glPushMatrix();
        {
            glTranslated(-0.16,-1.35,-1);
            setMaterial2(mat_metal_diff, mat_metal_spec, mat_metal_ambi, mat_metal_shin);
            glRotated(30, 0, 0, 1);
            glScaled(0.2, 0.05, 0.12);
            cubs[SECONDLEG_AUX3] -> draw();
        }
        glPopMatrix();
        
        glPushMatrix();
        {
            glTranslated(-0.14,-1.08,-1);
            setMaterial2(mat_metal_diff, mat_metal_spec, mat_metal_ambi, mat_metal_shin);
            glRotated(70, 0, 0, 1);
            glScaled(0.8, 0.05, 0.12);
            cubs[THIRDLEG] -> draw();
        }
        glPopMatrix();
        
        glPushMatrix();
        {
            glTranslated(0.0,-1.08,-1);
            setMaterial2(mat_metal_diff, mat_metal_spec, mat_metal_ambi, mat_metal_shin);
            glRotated(70, 0, 0, 1);
            glScaled(0.5, 0.05, 0.12);
            cubs[THIRDLEG_AUX] -> draw();
        }
        glPopMatrix();
        
        glPushMatrix();
        {
            glTranslated(0.05,-0.75,-1);
            setMaterial2(mat_metal_diff, mat_metal_spec, mat_metal_ambi, mat_metal_shin);
            glRotated(-65, 0, 0, 1);
            glScaled(0.20, 0.05, 0.12);
            cubs[THIRDLEG_AUX] -> draw();
        }
        glPopMatrix();
        
        
        glPushMatrix(); //Neck
        {
            glPushMatrix();
            {
                glTranslated(0.0,-0.60,-1);
                setMaterial2(mat_metal_diff, mat_metal_spec, mat_metal_ambi, mat_metal_shin);
                glRotated(90, 0, 0, 1);
                glScaled(0.3, 0.05, 0.12);
                cubs[NECK] -> draw();
            }
            glPopMatrix();
            
            glPushMatrix();
            {
                glTranslated(-0.05,-0.30,-1);
                setMaterial2(mat_metal_diff, mat_metal_spec, mat_metal_ambi, mat_metal_shin);
                glRotated(0, 0, 0, 1);
                glScaled(0.3, 0.3, 0.3);
                cubs[NECK] -> draw();
            }
            glPopMatrix();
            
            glPushMatrix();
            {
                glTranslated(0.2,-0.30,-1);
                setMaterial2(mat_metal_diff, mat_metal_spec, mat_metal_ambi, mat_metal_shin);
                glRotated(0, 0, 0, 1);
                glScaled(0.5, 0.5, 0.5);
                cubs[NECK2] -> draw();
            }
            glPopMatrix();
            
            glPushMatrix();
            {
                glTranslated(0.5,-0.30,-1);
                setMaterial2(mat_metal_diff, mat_metal_spec, mat_metal_ambi, mat_metal_shin);
                glRotated(90, 0, 0, 1);
                glScaled(0.6, 0.1, 0.6);
                cyl -> draw();
            }
            glPopMatrix();
            
        }
        glPopMatrix();
        
    }
    glPopMatrix();
}

