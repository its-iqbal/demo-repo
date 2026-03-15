#include <iostream>
#include <cmath>
#include <GL/glut.h>

const double PI = 3.14159265358979323846;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 1.0f, 0.0f);

    int n = 6;      
    float R = 0.5f; 

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < n; i++) {

        float theta = 2.0f * PI * i / n; 
        
        float x = R * cos(theta);
        float y = R * sin(theta);
        
        glVertex2f(x, y);
    }
    glEnd();
    
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Polygon at Origin");
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    
    glutMainLoop();
    return 0;
}