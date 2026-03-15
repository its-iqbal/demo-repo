#include <iostream>
#include <cmath>
#include <GL/glut.h>

const double PI = 3.14159265358979323846;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.8f, 1.0f);

    int n = 8;        
    float R = 0.3f;   
    float cx = 0.4f;   //to set the desired x position of polygon
    float cy = 0.3f;   //to set the desired y position of polygon

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < n; i++) {

        float theta = 2.0f * PI * i / n; 
        
        float x = cx + R * cos(theta);
        float y = cy + R * sin(theta);
        
        glVertex2f(x, y);
    }
    glEnd();
    
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Polygon at Desired Position");
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    
    glutMainLoop();
    return 0;
}