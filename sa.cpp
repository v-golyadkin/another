#include <iostream>
#include <GL/glut.h>
float WinWid = 900, WinHei = 600;


void init() {
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-WinWid / 2, WinWid / 2, -WinHei / 2, WinHei / 2, -200.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
}


void draw() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.203921568627451f, 0.4980392156862745f, 0.2392156862745098f);
    glRectf(450,180, -450, 300);
    glColor3f(0.203921568627451f, 0.4980392156862745f, 0.2392156862745098f);
    glRectf(450, -180, -450, -300);
    glColor3f(0.7,0.03,0.1);
    glRectf(450, 120, -450, -120);

    glColor3f(0.9294117647058824f, 0.7882352941176471f, 0.0901960784313725f);

    glBegin(GL_POLYGON);

    glVertex2f(30, 30);
    glVertex2f(126, 30);
    glVertex2f(52, -20);
    glVertex2f(80, -106);
    glVertex2f(0, -56);
    glVertex2f(-80, -106);
    glVertex2f(-52, -20);
    glVertex2f(-126, 30);
    glVertex2f(-30, 30);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(-0, 112);
    glVertex2f(30, 30);
    glVertex2f(-30, 30);
    glEnd();



    glutSwapBuffers();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WinWid, WinHei);
    glutInitWindowPosition(400, 150);
    glutCreateWindow("Suriname");
    glutDisplayFunc(draw);
    init();

    glutMainLoop();
}
