#include <iostream>
#include <GL/glut.h>

using namespace std;

void myDisplay(void)
{

    glClearColor(0.9f, 0.9f, 0.9f, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(5, 3);
    glVertex2f(15, 3);
    glVertex2f(15, 13);
    glVertex2f(5, 13);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(7, 9);
    glVertex2f(9, 9);
    glVertex2f(9, 11);
    glVertex2f(7, 11);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(11, 9);
    glVertex2f(13, 9);
    glVertex2f(13, 11);
    glVertex2f(11, 11);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(7, 6);
    glVertex2f(8, 6);
    glVertex2f(8, 7);
    glVertex2f(7, 7);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(8, 5);
    glVertex2f(12, 5);
    glVertex2f(12, 6);
    glVertex2f(8, 6);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(12, 6);
    glVertex2f(13, 6);
    glVertex2f(13, 7);
    glVertex2f(12, 7);
    glEnd();

    glFlush();
}

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 20.0, 0.0, 15.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Smiley Face - M Iqbal Roll No. 5653022");

    init();
    glutDisplayFunc(myDisplay);

    glutMainLoop();
    return 0;
}