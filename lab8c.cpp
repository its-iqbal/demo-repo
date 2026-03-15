#include <iostream>
#include <cmath>
#include <GL/freeglut.h>

const double PI = 3.14159265358979323846;

void DrawLine(int x1, int y1, int x2, int y2) {
    glBegin(GL_LINES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glEnd();
}

void DrawRectangle(int x, int y, int width, int height) {
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x + width, y);
    glVertex2i(x + width, y + height);
    glVertex2i(x, y + height);
    glEnd();
}

void DrawCircle(int cx, int cy, int radius) {
    int n = 100;
    glBegin(GL_POLYGON); 
    for (int i = 0; i < n; i++) {
        double theta = i * (2.0 * PI / n); 
        double x = radius * cos(theta);
        double y = radius * sin(theta);
        glVertex2d(cx + x, cy + y);
    }
    glEnd();
}

void DrawBhoot(int x, int y) {
    glColor3f(0.8f, 0.8f, 0.85f); 
    DrawCircle(x, y, 50);
    DrawRectangle(x - 50, y, 100, 100);

    glColor3f(1.0f, 0.0f, 0.0f); 

    DrawLine(x - 35, y - 25, x - 5, y - 15);
    DrawLine(x + 5, y - 15, x + 35, y - 25);

    DrawCircle(x - 20, y - 10, 6);
    DrawCircle(x + 20, y - 10, 6); 
    
    DrawLine(x - 25, y + 20, x - 15, y + 30);
    DrawLine(x - 15, y + 30, x - 5, y + 20);
    DrawLine(x - 5, y + 20, x + 5, y + 30);
    DrawLine(x + 5, y + 30, x + 15, y + 20);
    DrawLine(x + 15, y + 20, x + 25, y + 30);

    glColor3f(0.8f, 0.8f, 0.85f); 
    int bottomY = y + 100;
    int frillTipY = y + 130;
    
    DrawLine(x - 50, bottomY, x - 25, frillTipY);
    DrawLine(x - 25, frillTipY, x, bottomY);      
    DrawLine(x, bottomY, x + 25, frillTipY);     
    DrawLine(x + 25, frillTipY, x + 50, bottomY); 
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    DrawBhoot(250, 250);
    glFlush();
}

void init() {
    glClearColor(0.1f, 0.0f, 0.1f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 500.0, 0.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("My Horrible Bhoot");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}