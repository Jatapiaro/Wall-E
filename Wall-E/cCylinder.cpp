#include "cCylinder.h"

Cylinder::Cylinder()
{
	/*pos[0]  = position[0];
	pos[1]  = position[1];
	pos[2]  = position[2];

	size[0] = _size[0];
	size[1] = _size[1];
	size[2] = _size[2];*/

#include "cylinderData.h"
}

Cylinder::~Cylinder( void )
{

}

void Cylinder::draw( void )
{
	glPushMatrix();
	{
		//glTranslatef(pos[0], pos[1], pos[2]);
		//glScalef(size[0], size[1], size[2]);
        
        glScalef(1, 3, 1);

		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, cyl_vertices);
		//glEnableClientState(GL_COLOR_ARRAY);
		//glColorPointer(3, GL_FLOAT, 0, cyl_colors);
		glEnableClientState(GL_NORMAL_ARRAY);
		glNormalPointer(GL_FLOAT, 0, cyl_normals);

		glDrawElements(GL_TRIANGLES, 240, GL_UNSIGNED_BYTE, cyl_v_index);

		glDisableClientState(GL_VERTEX_ARRAY);
		//glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
	}
	glPopMatrix();
}
