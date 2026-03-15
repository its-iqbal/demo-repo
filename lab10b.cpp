#include <GL/freeglut.h>
#include <stdio.h>

enum levels { INTRO, LEVEL1, LEVEL2 } level;
float WL, WR, WB, WT;

void renderBitmapString(float x, float y, void *font, const char *string) {
    const char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void introScreen() {
    glColor3f(1.0f, 1.0f, 1.0f);
    char buf[100] = {0};
    
    sprintf(buf, "::::::::::: Week 10!:::::::::::: ");
    renderBitmapString(-80, 40, GLUT_BITMAP_TIMES_ROMAN_24, buf);
    
    glColor3f(1.0f, 1.0f, 0.0f);
    sprintf(buf, "Press 'S' to start LEVEL 1");
    renderBitmapString(-60, 0, GLUT_BITMAP_HELVETICA_18, buf);
}

void level1Screen() {
    glColor3f(0.0f, 0.5f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-50, -50);
        glVertex2f(50, -50);
        glVertex2f(50, 50);
        glVertex2f(-50, 50);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    renderBitmapString(-40, 0, GLUT_BITMAP_TIMES_ROMAN_24, "Welcome to Level 1!");
}

void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    switch (level) {
        case INTRO:
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluOrtho2D(WL, WR, WB, WT);
            
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            
            introScreen();
            break;
            
        case LEVEL1:
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluOrtho2D(WL, WR, WB, WT);
            
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            
            level1Screen();
            break;
    }

    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    if ((key == 's' || key == 'S') && level == INTRO) {
        level = LEVEL1;
        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    glutInitWindowSize(640, 480);
    glutCreateWindow("This is Intro Screen");
    
    level = INTRO;
    WL = -100; WR = 100; WB = -100; WT = 100;
    
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(keyboard);
    
    glutMainLoop();
    return 0;
}