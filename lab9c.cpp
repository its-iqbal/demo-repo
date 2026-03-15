#include <iostream>
#include <cmath>
#include <GL/glut.h>

const double PI = 3.14159265358979323846;

// Function 1
void drawPolygon(int n, float R, float cx, float cy) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < n; i++) {

        float theta = 2.0f * PI * i / n; 
        
        float x = cx + R * cos(theta);
        float y = cy + R * sin(theta);
        
        glVertex2f(x, y);
    }
    glEnd();
}

// Function 2
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(0.0f, 0.8f, 1.0f);
    drawPolygon(8, 0.3f, 0.4f, 0.5f);
    
    glColor3f(1.0f, 0.5f, 0.0f);
    drawPolygon(5, 0.2f, -0.6f, -0.4f);

    glFlush();
}

// Function 3
void initGraphics() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Polygons via Functions");
    
    initGraphics();
    
    glutDisplayFunc(display);
    
    glutMainLoop();
    return 0;
}