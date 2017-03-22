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

GLfloat*	mat0_specular; //<---------------------------------------Material 0 - specular
GLfloat*	mat0_diffuse; //<----------------------------------------Material 0 - diffuse
GLfloat*	mat0_shininess; //<--------------------------------------Material 0 - specular power
GLfloat*	light0_position; //<-------------------------------------Light 0    - location

void display( void )
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    // State machine: set active material:
    glMaterialfv( GL_FRONT,	 GL_DIFFUSE,   mat0_diffuse		);
    glMaterialfv( GL_FRONT,  GL_SPECULAR,  mat0_specular	);
    glMaterialfv( GL_FRONT,  GL_SHININESS, mat0_shininess	);
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
    glClearColor ( 0.0f, 0.0f, 0.0f, 0.0f ); //<---------------------Clear color
    glShadeModel ( GL_SMOOTH ); //<----------------------------------Smooth shading
    
    glEnable(GL_NORMALIZE);
    //->MATERIAL 0 BEGINS
    mat0_specular		= new GLfloat[4]; //<------------------------Reserve memory
    mat0_specular[0]	= 0.0f; //<----------------------------------S0r
    mat0_specular[1]	= 0.0f; //<----------------------------------S0g
    mat0_specular[2]	= 0.0f; //<----------------------------------S0b
    mat0_specular[3]	= 1.0f; //<----------------------------------S0a
    
    mat0_diffuse		= new GLfloat[4]; //<------------------------Reserve memory
    mat0_diffuse[0]		= 1.0f; //<----------------------------------D0r
    mat0_diffuse[1]		= 0.0f; //<----------------------------------D0g
    mat0_diffuse[2]		= 0.0f; //<----------------------------------D0b
    mat0_diffuse[3]		= 1.0f; //<----------------------------------D0a
    
    mat0_shininess		= new GLfloat[1]; //<------------------------Reserve memory
    mat0_shininess[0]	= 60.0f; //<---------------------------------Material 0 specular power
    //<-MATERIAL 0 ENDS
    
    //->LIGHT 0 BEGINS
    light0_position		= new GLfloat[4]; //<------------------------Reserve memory
    light0_position[0]	= 1.0f; //<----------------------------------L0x
    light0_position[1]	= 1.0f; //<----------------------------------L0y
    light0_position[2]	= 1.0f; //<----------------------------------L0z
    light0_position[3]	= 0.0f; //<----------------------------------L0w
    
    /*
     Important: light position is L0(lx,ly,lz,lw).
     -If lw = 0, configures a directional light, and parameters lx, ly y lz define its direction.
     -If lw = 1, configures a point light, and parameters lx, ly y lz define its location.
     */
    //<-LIGHT 0 ENDS
    
    // Locate LIGHT 0:
    glLightfv( GL_LIGHT0, GL_POSITION,  light0_position );
    // Enable lighting:
    glEnable( GL_LIGHTING );
    // Enable LIGHT 0:
    glEnable( GL_LIGHT0 );
    // Enable depth test (distinguish between near and far faces):
    glEnable( GL_DEPTH_TEST );
    // Assign initial rotation angle:
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
