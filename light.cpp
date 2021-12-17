#include <iostream>
#include <GL/glut.h>

using namespace std;

int rY = 0, rX = 0, rZ = 0;

float WinWid = 800, WinHei = 430;

bool check = false;

GLfloat light0_position[] = { 100.0, 100.0, 100.0, 0.0 };

void rotX() 
{
	rX += 5;
}
void rotY() 
{
	if (!check) 
	{
		if (light0_position[1] > -100 && light0_position[2] > -100) 
		{
			light0_position[1] -= 5;
			light0_position[2] -= 5;
		}
		else 
		{
			check = true;
		}
	}
	else 
	{
		if (light0_position[1] < 100 && light0_position[2] < 100) 
		{
			light0_position[1] += 5;
			light0_position[2] += 5;
		}
		else 
		{
			check = false;
		}
	}
}
void rotZ() 
{
	rZ += 5;
}
void key(int key, int x, int y) 
{
	switch (key)
	{
	case 27: break;
	case 100: rotX();  break;
	case 102: rotY();  break;
	case 103: rotZ();  break;
	}
}

void init() 
{
	glClearColor(1, 1, 1, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glEnable(GL_LIGHTING);
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glOrtho(-WinWid / 2, WinWid / 2, -WinHei / 2, WinHei / 2, -200.0, 200.0);
	glMatrixMode(GL_MODELVIEW);
}

void draw() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	GLfloat material_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse);
	GLfloat light0_diffuse[] = { 1, 1, 1 };
	glEnable(GL_LIGHT0);	
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
	glTranslatef(0, 100, 0);
	glRotatef(rX, 1.0, 0.0, 0.0);
	glRotatef(rY, 0.0, 1.0, 0.0);
	glRotatef(rZ, 0.0, 0.0, 1.0);
	glColor3f(0, 0, 0);
	glutSolidSphere(100, 64, 64);
	glDisable(GL_LIGHT0);
	glPopMatrix();
	glutSwapBuffers();
}


int main(int argc, char** argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WinWid, WinHei);
	glutInitWindowPosition(400, 150);
	glutCreateWindow("GHANA");
	glutDisplayFunc(draw);
	glutSpecialFunc(key);
	glutIdleFunc(draw);
	init();
	glutMainLoop();
}
