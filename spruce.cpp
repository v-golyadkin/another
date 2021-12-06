#include<GL/glut.h>
#include<iostream>
float WinWid = 900, WinHei = 600;

int rY = 0;
int rZ = 0;
int rX = 0;

void init() {

    glClearColor(1, 1, 1, 1);
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
void draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -3.0);
    glRotatef(rY, 0, 1.0, 0);
    glRotatef(rX, 1.0, 0, 0);
    glRotatef(rZ, 0, 0, 1.0);


    //Ствол
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-25, -50, 0);
    glVertex3f(25, -50, 0);
    glVertex3f(25, 0, 0);
    glVertex3f(-25, 0, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-25, -50, 0);
    glVertex3f(-25, -50, 50);
    glVertex3f(-25, 0, 50);
    glVertex3f(-25, 0, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(25, -50, 0);
    glVertex3f(25, -50, 50);
    glVertex3f(25, 0, 50);
    glVertex3f(25, 0, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-25, -50, 50);
    glVertex3f(25, -50, 50);
    glVertex3f(25, 0, 50);
    glVertex3f(-25, 0, 50);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-25, -50, 0);
    glVertex3f(25, -50, 0);
    glVertex3f(25, -50, 50);
    glVertex3f(-25, -50, 50);
    glEnd();

    //Елка

    glColor3f(0, 1, 1);
    
    glBegin(GL_POLYGON);
    glVertex3f(-100, 0, -50);
    glVertex3f(100, 0, -50);
    glVertex3f(0, 0, 150);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(-100, 0, -50);
    glVertex3f(100, 0, -50);
    glVertex3f(0, 250, 0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(0, 250, 0);
    glVertex3f(100, 0, -50);
    glVertex3f(0, 0, 150);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-100, 0, -50);
    glVertex3f(0, 250, 0);
    glVertex3f(0, 0, 150);
    glEnd();

    glutSwapBuffers();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WinWid, WinHei);
    glutInitWindowPosition(400, 150);
    glutCreateWindow("TRUCK");
    init();
    glutDisplayFunc(draw);
    glutSpecialFunc(key);
    glutIdleFunc(draw);

    glutMainLoop();
}
