// [1] LIBRARIES & GLOBAL VARIABLES
#include <windows.h>
#include <GL/freeglut.h> 
#include <iostream>
#include <math.h>
#include "RGBA.h" 

int screenWidth = 800;
int screenHeight = 600;
RGBApixmap bgImage; 

// [2] GEOMETRY LOGIC (Star Generation)
void drawStar(float x, float y, float radius) {
    glColor3f(0.85f, 0.72f, 0.15f); 
    glBegin(GL_POLYGON);
    for (int i = 0; i < 10; i++) {
        float r = (i % 2 == 0) ? radius : radius / 2.0f;
        float angle = i * 3.14159f / 5.0f;
        glVertex2f(x + r * sin(angle), y + r * cos(angle));
    }
    glEnd();
}

// [3] TYPOGRAPHY LOGIC (Text Rendering)
void renderText(float x, float y, void* font, const char* string) {
    glColor3f(0.2f, 0.3f, 0.2f); 
    glRasterPos2f(x, y);
    while (*string) {
        glutBitmapCharacter(font, *string++);
    }
}

// [4] ENVIRONMENT & ASSET INITIALIZATION
void myInit() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // Set 2D Orthographic Projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, screenWidth, 0, screenHeight);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Load Image and Audio
    bgImage.readBMPFile("eid_bg.bmp", 1); 
    PlaySound(TEXT("eid_audio.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
}

// [5] MAIN DISPLAY RENDERING PIPELINE
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Layer 1: Background Image
    glRasterPos2f(0, 0); 
    bgImage.mDraw(); 

    // Layer 2: Geometric Stars
    drawStar(600, 400, 18);
    drawStar(720, 380, 14);
    drawStar(500, 520, 16);
    drawStar(680, 280, 12);
    drawStar(420, 470, 15); 
    drawStar(750, 200, 10);

    // Layer 3: Text Overlays
    renderText(190, 350, GLUT_BITMAP_TIMES_ROMAN_24, "Eid Mubarak, Miss Humera Tariq!");
    renderText(190, 300, GLUT_BITMAP_HELVETICA_18, "Wishing you a blessed Eid");
    
    renderText(480, 100, GLUT_BITMAP_HELVETICA_18, "Regards: M. Iqbal");
    renderText(480, 70, GLUT_BITMAP_HELVETICA_18, "Roll No: B25110206030");

    glFlush(); 
}

// [6] MAIN EXECUTION LOOP
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Week 07 Mini Project - Eid Greeting Card");
    
    myInit();
    glutDisplayFunc(display);
    
    glutMainLoop();
    return 0;
}