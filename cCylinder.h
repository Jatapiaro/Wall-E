#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
	#include <GLUT/glut.h>
#else
	#include "freeglut.h"
#endif

#ifndef CYLINDER
#define CYLINDER

class Cylinder
{
public:
					Cylinder	();
					~Cylinder	( void					);

	void			draw		( void					);

public:
	//float			pos[3];
	//float			size[3];
	float			cyl_vertices[42][3];
	float			cyl_normals[42][3];
	float			cyl_colors[42][3];
	unsigned char	cyl_v_index[240];
};

#endif
