#include <iostream>
#include <GL/glut.h>
using namespace std;
float WinWid = 900, WinHei = 600;
int rY = 0, rZ = 0, rX = 0;
int PI = 3.14;

//Additional methods
void init() {

    glClearColor(0, 0, 1, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-WinWid / 2, WinWid / 2, -WinHei / 2, WinHei / 2, -8000.0, 8000.0);
    glMatrixMode(GL_MODELVIEW);
}

void rotY() {
    rY += -5;
}
void rotX() {
    rX += 5;
}
void rotZ() {
    rZ += 5;
}
void key(int key, int x, int y) {
    switch (key)
    {
    case 27:      break;
    case 100: rotX();   break;
    case 102: rotY();  break;
    case 103: rotZ();  break;
    }

}


//Methods
void drawCylinder(GLfloat radius,
    GLfloat height,
    GLubyte R,
    GLubyte G,
    GLubyte B)
{
    GLfloat x = 0.0;
    GLfloat y = 0.0;
    GLfloat angle = 0.0;
    GLfloat angle_stepsize = 0.1;

    /* Draw the tube */
    glColor3ub(R - 40, G - 40, B - 40);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while (angle < 2 * PI) {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, height);
        glVertex3f(x, y, 0.0);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glVertex3f(radius, 0.0, 0.0);
    glEnd();

    /* Draw the circle on top of cylinder */
    glColor3ub(R, G, B);
    glBegin(GL_POLYGON);
    angle = 0.0;
    while (angle < 2 * PI) {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, height);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glEnd();
}


void draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_LIGHT0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -3.0);
    glRotatef(rY, 0, 1.0, 0);
    glRotatef(rX, 1.0, 0, 0);
    glRotatef(rZ, 0, 0, 1.0);

    //Голова
    glColor3f(0.5, 0.0, 0.1);
    glTranslatef(0, 120, 0);
    glutSolidSphere(40, 25, 25);
    glTranslatef(0, 0, 0);

    //Уши
    glColor3f(0, 0, 0);
    glTranslatef(30, 25, 0);
    glutSolidSphere(15, 20, 20);
    glTranslatef(-30, -25, 0);

    glTranslatef(-30, 25, 0);
    glutSolidSphere(15, 20, 20);
    glTranslatef(0, 0, 0);


    //Тело
    glColor3f(0.5, 0.0, 0.1);
    glTranslatef(30, -100, 0);
    glutSolidSphere(50, 40, 30);
    glTranslatef(-30, 100, 0);

 

    //Лапы
    glColor3f(0, 0, 0);
    glTranslatef(80, -80, 0);
    glutSolidSphere(15, 25, 25);
    glTranslatef(-80, 80, 0);

    glTranslatef(-20, -80, 0);
    glutSolidSphere(15, 25, 25);
    glTranslatef(80, 80, 0);

    glColor3f(0, 0, 0);
    glTranslatef(-60, -150, 0);
    glutSolidSphere(20, 25, 25);
    glTranslatef(60, 150, 0);

    glTranslatef(0, -150, 0);
    glutSolidSphere(20, 25, 25);
    glTranslatef(0, 150, 0);

    //Глаза
    glColor3f(1, 1, 1);
    glTranslatef(-20, -15, 30);
    glutSolidSphere(10, 25, 25);
    glTranslatef(20, 15, -30);

    glTranslatef(-40, -15, 30);
    glutSolidSphere(10, 25, 25);
    glTranslatef(40, 15, -30);

    //Рот
    glColor3f(1, 1, 1);
    glTranslatef(-30, -35, 25);
    glutSolidSphere(15, 25, 20);
    glTranslatef(30, 35, -25);

    //Нос
    glColor3f(0, 0, 0);
    glTranslatef(-30, -32, 40);
    glutSolidSphere(5, 25, 25);



    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WinWid, WinHei);
    glutInitWindowPosition(400, 150);
    glutCreateWindow("VINI PYH");
    init();
    glutDisplayFunc(draw);
    glutSpecialFunc(key);
    glutIdleFunc(draw);

    glutMainLoop();
}
