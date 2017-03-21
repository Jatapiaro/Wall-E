#include <math.h>
#include <stdio.h>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include "freeglut.h"
#endif

#include "cWallE.h"
#include <stdlib.h>

int width, height;
float deltaX, deltaY;

WallE *walle;

void display( void )
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();
    glRotatef( deltaY, 1.0, 0.0, 0.0 );
    glRotatef( deltaX, 0.0, 1.0, 0.0 );
    
    walle->draw();
    
    glutSwapBuffers();
}

void idle( void )
{
    glutPostRedisplay();
}

void init( void )
{
    glEnable( GL_DEPTH_TEST );
    glShadeModel(GL_FLAT);
    glClearColor( 0.0, 0.0, 0.0, 1.0 );
    float pos[] = { 0.0, 0.0, 0.0 };
    float size[] = { 1, 1, 1 };
    walle = new WallE();
}

void reshape( int w, int h )
{
    width = w;
    height = h;
    glViewport( 0, 0, w, h );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    
    gluPerspective( 45, w / h * 1.0, 0.01, 20 );
    glTranslatef( 0, 0, -8 );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}

void keys( unsigned char key, int x, int y )
{
    switch( key )
    {
        case 'r':case 'R':
            glClearColor( 1.0, 0.0, 0.0, 1.0 );
            break;
        case 'b':case 'B':
            glClearColor( 0.0, 0.0, 1.0, 1.0 );
            break;
        case '0':
            glClearColor( 0.0, 0.0, 0.0, 1.0 );
            break;
        case 27:
            delete walle;
            exit(0);
        default:
            break;
    }
}

void mouse( int button, int state, int x, int y )
{
    
}

void move( int x, int y )
{
    static int lastX = 0, lastY = 0;
    deltaX += lastX - x;
    deltaY -= lastY - y;
    lastX = x;
    lastY = y;
}

int main( int argc, char** argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize( 512, 512 );
    glutInitWindowPosition( 600, 100 );
    glutCreateWindow( "Cube with Vertex Arrays" );
    
    glutReshapeFunc( reshape );
    glutKeyboardFunc( keys );
    glutMotionFunc( move );
    glutMouseFunc( mouse );
    
    init();
    glutDisplayFunc( display ); 
    glutIdleFunc( idle );
    glutMainLoop();
    return 0;
}
