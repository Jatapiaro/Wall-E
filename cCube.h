#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
	#include <GLUT/glut.h>
#else
	#include "freeglut.h"
#endif

#ifndef __CUBE
#define __CUBE

class Cube 
{
public:
    Cube ();
	~Cube (void);
	

	void draw (void);

private:
	float			vertices[8][3];
	float			colors[8][3];
	float			normals[8][3];
	unsigned char	index[24];
	//float			pos[3];
	//float			size[3];
	float			delta;
};

#endif
