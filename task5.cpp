#include <iostream>
#include <GL/glut.h>
using namespace std;

float WinWid = 900, WinHei = 600;
double PI = 3.14159265359;
int rX = 0, rY = 0, rZ = 0;
double R = 0.0, G = 0.0, B = 0.0;
//GLfloat light0_position[] = { 500.0, 500.0, 500.0, 0.0 };
void init()
{
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-WinWid / 2, WinWid / 2, -WinHei / 2, WinHei / 2, -8000.0, 8000.0);
    glMatrixMode(GL_MODELVIEW);
}

void rotY() {
    rY += 5;
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
    case 27: break;
    case 100: rotX();  break;
    case 102: rotY();  break;
    case 103: rotZ();  break;
    }

}

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

    /** Draw the tube */
    glColor3ub(R - 10, G - 10, B - 10);
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

    /** Draw the circle on top of cylinder */
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

    glColor3ub(R, G, B);
    glBegin(GL_POLYGON);
    angle = 0.0;
    while (angle < 2 * PI) {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, 0);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    double aspect = (double)viewport[2] / (double)viewport[3];
    gluPerspective(60, aspect, 1, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // move back a bit
    glTranslatef(0, 0, -45);

    glPushMatrix();
    glTranslatef(0, 0, 0);

    GLfloat ambient_light[] = { 0.0f, 0.0f, 0.2f, 1.0f };
    GLfloat diffuse_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat specular_light[] = { R, G, B, 1.0f };
    GLfloat position_light[] = { 0.0f, 1.0f, 0.0f, 1.0f };

    //glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position_light);

    // Material
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    GLfloat mat_ambient[] = { 1.0f, 0.5f, 0.31f, 0.0 };
    GLfloat mat_diffuse[] = { 1.0f, 0.5f, 0.31f, 0.0 };
    GLfloat mat_specular[] = { 0.5f, 0.5f, 0.5f, 0.0};
    GLfloat mat_shininess[] = { 256.0 };
    //GLfloat mat_emission[] = { 1.0, 1.0, 1.0, 1.0 };

    glColor3f(1.0, 0.5, 0.0);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glRotatef(rX, 0.0, 1.0, 0);
    glRotatef(rY, 0.0, 0, 1.0);
    glRotatef(rZ, 1.0, 0, 0);
    drawCylinder(5, 20, 100, 255, 200);
    
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
}

void timer(int extra)
{
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("cylinder");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(key);
    glutTimerFunc(0, timer, 0);

    init();

    glutMainLoop();
    return 0;
}
