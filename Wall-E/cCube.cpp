#include "cCube.h"

Cube::Cube()
{
	/*pos[0] = position[0];
	pos[1] = position[1];
	pos[2] = position[2];

	size[0] = _size[0];
	size[1] = _size[1];
	size[2] = _size[2];*/

	// vertex 1
	vertices[0][0] = -1.0;
	vertices[0][1] = -1.0;
	vertices[0][2] = -1.0;
	// vertex 2
	vertices[1][0] = 1.0;
	vertices[1][1] = -1.0;
	vertices[1][2] = -1.0;
	// vertex 3
	vertices[2][0] = 1.0;
	vertices[2][1] = 1.0;
	vertices[2][2] = -1.0;
	// vertex 4
	vertices[3][0] = -1.0;
	vertices[3][1] = 1.0;
	vertices[3][2] = -1.0;
	// vertex 5
	vertices[4][0] = -1.0;
	vertices[4][1] = -1.0;
	vertices[4][2] = 1.0;
	// vertex 6
	vertices[5][0] = 1.0;
	vertices[5][1] = -1.0;
	vertices[5][2] = 1.0;
	//vertex 7
	vertices[6][0] = 1.0;
	vertices[6][1] = 1.0;
	vertices[6][2] = 1.0;
	// vertex 8
	vertices[7][0] = -1.0;
	vertices[7][1] = 1.0;
	vertices[7][2] = 1.0;

	// color vertex 1
	colors[0][0] = 0.0;
	colors[0][1] = 0.0;
	colors[0][2] = 0.0;
	// color vertex 2
	colors[1][0] = 1.0;
	colors[1][1] = 0.0;
	colors[1][2] = 0.0;
	// color vertex 3
	colors[2][0] = 1.0;
	colors[2][1] = 1.0;
	colors[2][2] = 0.0;
	// color vertex 4
	colors[3][0] = 0.0;
	colors[3][1] = 1.0;
	colors[3][2] = 0.0;
	// color vertex 5
	colors[4][0] = 0.0;
	colors[4][1] = 0.0;
	colors[4][2] = 1.0;
	// color vertex 6
	colors[5][0] = 1.0;
	colors[5][1] = 0.0;
	colors[5][2] = 1.0;
	//color vertex 7
	colors[6][0] = 1.0;
	colors[6][1] = 1.0;
	colors[6][2] = 1.0;
	// color vertex 8
	colors[7][0] = 0.0;
	colors[7][1] = 1.0;
	colors[7][2] = 1.0;

	// The indices will tell OpenGL how to connect the vertices
	unsigned char indicesCube[24] = {	0,3,2,1,
										2,3,7,6,
										0,4,7,3,
										1,2,6,5,
										4,5,6,7,
										0,1,5,4  };

	// moving the indices to index array
	int i;
	for( i=0; i < 24; i++ )
	{
		index[i] = indicesCube[i];
	}
}

Cube::~Cube( void )
{

}

void Cube::draw( void )
{
	glPushMatrix();
	{
		//glTranslatef(pos[0], pos[1], pos[2]);
		//glScalef(size[0], size[1], size[2]);
        glScalef(0.5f, 0.5f, 0.5f);
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, vertices);
		//glEnableClientState(GL_COLOR_ARRAY);
		//glColorPointer(3, GL_FLOAT, 0, colors);
		glEnableClientState(GL_NORMAL_ARRAY);
		glNormalPointer(GL_FLOAT, 0, normals);
		glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, index);
		glDisableClientState(GL_VERTEX_ARRAY);
		//glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
	}
	glPopMatrix();
}
