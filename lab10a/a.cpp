#include <GL/freeglut.h>
#include <iostream>
#include <math.h>

#include "RGBA.h"

int screenWidth = 640;
int screenHeight = 480;

RGBApixmap pix[6];

void drawPolygon(int n, float radius, float cx, float cy, float startAngle) {
    float angle = startAngle;
    float angleInc = 2.0f * 3.14159f / n;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < n; i++) {
        glVertex2f(cx + radius * cos(angle), cy + radius * sin(angle));
        angle += angleInc;
    }
    glEnd();
}

void myInit() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_EQUAL, 1.0); 

    pix[0].setChromaKey(0, 0.0, 0.0);
    pix[0].readBMPFile("bg.bmp", 1);
    
    // Load Mario standing
    pix[1].readBMPFile("marioStanding.bmp", 1);
    
    // Load Ladder
    pix[2].readBMPFile("ladder.bmp", 1);
}

void display() {

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // ==========================================================
    // VIEWPORT 1: Left Half of the Screen (GEOMETRY)
    // ==========================================================
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, 320, 0, 480); 
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glViewport(0, 0, 320, 480); 
    
    glColor3f(1.0f, 0.0f, 0.0f);
    drawPolygon(5, 100, 160, 240, 0); 


    // ==========================================================
    // VIEWPORT 2: Right Half of the Screen (IMAGES)
    // ==========================================================
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, 320, 0, 480); 
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glViewport(320, 0, 320, 480);
    
    
    glRasterPos2f(0, 0); 
    pix[0].mDraw(); 
    
    glRasterPos2f(200, 0); 
    pix[2].mDraw();
    
    glRasterPos2f(100, 50); 
    pix[1].mDraw();

    glFlush(); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Q4: Viewports - Geometry vs Images");
    
    myInit();
    
    glutDisplayFunc(display);
    
    glutMainLoop();
    return 0;
}