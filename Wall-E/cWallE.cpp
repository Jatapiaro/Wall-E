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
    mat_orange_spec[0] = 0.0f;
    mat_orange_spec[1] = 0.0f;
    mat_orange_spec[2] = 0.0f;
    mat_orange_spec[3] = 1.0f;
    
    mat_orange_ambi = new float[4];
    mat_orange_ambi[0] = 22.5f/255.0f;
    mat_orange_ambi[1] = 15.0f/255.0f;
    mat_orange_ambi[2] = 4.8f/255.0f;
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
    
    mat_brown_spec[0] = 0.0f;
    mat_brown_spec[1] = 0.0f;
    mat_brown_spec[2] = 0.0f;
    mat_brown_spec[3] = 1.0f;
    
    mat_brown_shin[0] = 0.2179872;
    
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
    
    mat_eyes_spec[0] = 0.0f;
    mat_eyes_spec[1] = 0.0f;
    mat_eyes_spec[2] = 0.0f;
    mat_eyes_spec[3] = 1.0f;
    
    mat_eyes_shin[0] = 0.6f;
    
    lx = -0.5;
    ly = 0.25;
    lz = 0.17;
    
    frames = 0;
    brazoAngle = brazoAngle2 = 20.0f;
    pos = 1.3f;
    pos2 = 4.2f;
    
    hide = 0.70;
    appear = false;
    cabezaLoca = false;
    
    cabezAngle = doorAng = 0.0f;
    cabezaFlag = 0;
    bodyAngle = 90;
}



WallE::~WallE(){
    delete cubs;
    delete cyls;
}

void WallE::update(){
    /*
     Anim
     */
    if(appear && pos<4.2 && cabezaFlag<5){
        pos+=0.01f;
    }else if(appear && pos>4.2 && cabezaFlag<5){
        cabezaLoca = true;
    }
    
    if(cabezaLoca){
        if(cabezaFlag == 0 || cabezaFlag == 2){
            cabezAngle-=3;
            if(cabezAngle<=-120){
                if(cabezaFlag == 0){
                    cabezaFlag = 1;
                }else{
                    cabezaFlag = 3;
                }
            }
        }else if(cabezaFlag == 1){
            cabezAngle+=3;
            if(cabezAngle>=-90){
                cabezaFlag = 2;
            }
        }
    }
    
    if(cabezaFlag == 3){
        if(bodyAngle>=50){
            bodyAngle-=1;
        }else{
            cabezaFlag = 4;
        }
    }
    if(cabezaFlag == 4){
        if(bodyAngle<=90){
            bodyAngle+=1;
        }
        if(cabezAngle<=-90){
            cabezAngle+=1;
        }else{
            cabezaFlag = 5;
        }
    }
    
    if(cabezaFlag == 5){
        if(hide>=-0.3){
            hide -= 0.01f;
        }else{
            cabezaFlag = 6;
        }
        pos2-=0.003f;
    }
    
}

void setMaterial(float *diff, float *spec, float *ambient, float *shin){
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shin);
}

void WallE::draw(){
    

    if(cabezaFlag<5){
        glTranslatef(pos, -1.5, 1);
    }else{
        glTranslatef(pos2, -1.5, 1);
    }
    glRotated(bodyAngle, 0, 1, 0);
    /*if(cabezaFlag == 3){
        
    }else{
        glRotated(90, 0, 1, 0);
    }*/
    glPushMatrix(); //WALLE
    {
        glPushMatrix(); //Body
        {
            glScaled(1.0f, 0.8f, 1.0f);
            //glRotated(-90, 0, 1, 0);
            setMaterial(mat_orange_diff,
                        mat_orange_spec, mat_orange_ambi, mat_orange_shin);
            cubs[BODY] -> draw();
            
            glPushMatrix(); //LBIG
            {
                glTranslated(-0.6, -0.6, -0.2);
                setMaterial(mat_brown_diff, mat_brown_diff, mat_brown_ambi, mat_brown_shin);
                glRotated(-90, 0, 0, 1);
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
            

            glPushMatrix();
            {
                if(cabezaFlag!=5){
                    glRotated(brazoAngle, 1, 0, 0);
                }else{
                    if(brazoAngle>-30){
                        brazoAngle-=0.5;
                    }
                    glRotated(brazoAngle, 1, 0, 0);
                }
                glPushMatrix(); //LARM
                {
                    glTranslatef(lx, ly, lz);
                    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
                    glTranslatef(lx, -ly, -lz+0.1);
                    setMaterial(mat_brown_diff, mat_brown_diff, mat_brown_ambi, mat_brown_shin);
                    //glRotated(0, 0, 0, 1);
                    glScaled(1.2, 0.20, 0.12);
                    cubs[LARM] -> draw();
                }
                glPopMatrix();
                
                glPushMatrix(); //LWRIST
                {
                    glTranslatef(-1, 0.25f, 0.17);
                    glRotated(90.0f, 0.0f, 1.0f, 0.0f);
                    glTranslatef(-1, -0.25, -0.17+0.6);
                    //glTranslated(-1.0, 0.25, 0.17);
                    setMaterial(mat_metal_diff, mat_metal_spec, mat_metal_ambi, mat_metal_shin);
                    glRotated(90, 0, 0, 1);
                    glScalef(.15, .25, .15);
                    cyls[LWRIST] -> draw();
                }
                glPopMatrix();
                
                glPushMatrix(); //LHAND
                {
                    glTranslatef(-1.35, 0.25, 0.17);
                    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
                    glTranslatef(-1.35, -0.25, -0.17+0.95);
                    //glTranslated(-1.35, 0.25, 0.17);
                    setMaterial(mat_metal_diff, mat_metal_spec, mat_metal_ambi, mat_metal_shin);
                    glRotated(90, 0, 0, 1);
                    glScaled(0.4, 0.4, 0.1);
                    cubs[LHAND] -> draw();
                }
                glPopMatrix();
                
            }
            glPopMatrix();
            
            glPushMatrix();
            {
                if(cabezaFlag<5){
                    glRotated(brazoAngle, 1, 0, 0);
                }else{
                    if(brazoAngle2>-20){
                        brazoAngle2-=0.5;
                    }
                    glRotated(brazoAngle2, 1, 0, 0);
                }
                glPushMatrix(); //RARM
                {
                    glTranslatef(0.5, 0.25, 0.17);
                    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
                    glTranslatef(-0.5, -0.25, 0.17-0.1);
                    setMaterial(mat_brown_diff, mat_brown_diff, mat_brown_ambi, mat_brown_shin);
                    glRotated(0, 0, 0, 1);
                    glScaled(1.2, 0.20, 0.12);
                    cubs[RARM] -> draw();
                }
                glPopMatrix();
                
                glPushMatrix(); //RWRIST
                {
                    glTranslatef(1.0, 0.25, 0.17);
                    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
                    glTranslatef(-1, -0.25, 0.17-0.6);
                    setMaterial(mat_metal_diff, mat_metal_spec, mat_metal_ambi, mat_metal_shin);
                    glRotated(90, 0, 0, 1);
                    glScalef(.15, .25, .15);
                    cyls[LWRIST] -> draw();
                }
                glPopMatrix();
                
                glPushMatrix(); //RHAND
                {
                    glTranslatef(1.35, 0.25, 0.17);
                    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
                    glTranslatef(-1.35, -0.25, 0.17-0.95);
                    setMaterial(mat_metal_diff, mat_metal_spec, mat_metal_ambi, mat_metal_shin);
                    glRotated(90, 0, 0, 1);
                    glScaled(0.4, 0.4, 0.1);
                    cubs[LHAND] -> draw();
                }
                glPopMatrix();
            }
            glPopMatrix();
            
            glPushMatrix(); //DOOR
            {
                glTranslated(0, -0.25, 0.55);
                setMaterial(mat_brown_diff, mat_brown_diff, mat_brown_ambi, mat_brown_shin);
                if(cabezaFlag<5){
                    glRotated(0, 0, 0, 1);
                }else{
                    glRotatef(doorAng, 1, 0, 0);
                    if(doorAng<135){
                        doorAng+=1.5;
                    }
                }
                glScaled(1.0f, 0.5, 0.1f);
                cubs[DOOR] -> draw();
            }
            glPopMatrix();
            
            
            glPushMatrix();
            {
                if(cabezaLoca){
                    glRotated(cabezAngle, 0, 1, 0);
                    if(cabezaFlag<5){
                        glRotated(25, 1, 0, 0);
                    }else{
                        glTranslatef(0.0, hide-0.7, 0.0);
                    }
                }
                glPushMatrix(); //NECK1
                {
                    glRotated(45, 0, 1, 0);
                    glTranslated(0.0, 0.7, 0.0);
                    setMaterial(mat_brown_diff, mat_brown_diff, mat_brown_ambi, mat_brown_shin);
                    glRotated(0, 0, 0, 1);
                    glScalef(0.2, 0.25, 0.2);
                    cyls[NECK1] -> draw();
                }
                glPopMatrix();
                
                glPushMatrix(); //NECK2
                {
                    glTranslated(0.0, 0.95, 0.0);
                    setMaterial(mat_metal_diff, mat_metal_spec, mat_metal_ambi, mat_metal_shin);
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
                    //setMaterial(mat_metal_diff, mat_metal_spec, mat_metal_ambi, mat_metal_shin);
                    setMaterial(mat_brown_diff, mat_brown_diff, mat_brown_ambi, mat_brown_shin);
                    glRotated(90, 90, 0, 1);
                    glScalef(0.2, 0.1, 0.2);
                    cyls[NOSE] -> draw();
                }
                glPopMatrix();
                
                glPushMatrix(); //LFACE_CYL
                {
                    glTranslated(-0.25, 1.275, -0.17);
                    setMaterial(mat_metal_diff, mat_metal_spec, mat_metal_ambi, mat_metal_shin);
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
                    setMaterial(mat_metal_diff, mat_metal_spec, mat_metal_ambi, mat_metal_shin);
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
    glPopMatrix();
}































