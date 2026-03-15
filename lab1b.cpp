#include <iostream>
#include <fstream>
#include <string>
#include <GL/glut.h>

using namespace std;

void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.9f, 0.9f, 0.9f, 0.0);

    glColor3f(0.0f, 0.0f, 1.0f); 
    glBegin(GL_POLYGON);
        glVertex2f(2, 1);
        glVertex2f(12, 1);
        glVertex2f(14, 3);
        glVertex2f(1, 3); 
    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f); 
    glBegin(GL_TRIANGLES);
        glVertex2f(2, 4);
        glVertex2f(6, 9);
        glVertex2f(6, 4);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f); 
    glBegin(GL_TRIANGLES);
        glVertex2f(12, 4);
        glVertex2f(7, 4);
        glVertex2f(7, 11);
    glEnd();
    
    glFlush();
}

void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 20.0, 0.0, 15.0); 
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(30, 30);
    glutCreateWindow("HT First OGL Program");
    
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}