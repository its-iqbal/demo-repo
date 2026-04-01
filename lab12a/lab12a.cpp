#include <GL/glut.h>
#include "pixMap.h"
#include <mmsystem.h>

#define IMAGES 5
RGBApixmap pix[IMAGES]; 

enum State { STANDING = 0, RUNNING1 = 1, RUNNING2 = 2, RUNNING3 = 3, JUMPING = 4, DIE };
enum ModeType { STAY, RUN, JUMP, DEAD };

State state = STANDING;
ModeType mode = STAY;

float pos_X = 0.0f;
float pos_Y = 0.0f;

void changePosition(float dx, float dy) {
    pos_X += dx;
    pos_Y += dy;
}

void setPosition(float x, float y) {
    pos_X = x;
    pos_Y = y;
}

void changeMode(ModeType m) {
    if (mode == m) return;
        
    switch(m) {
        case STAY: state = STANDING; break;
        case RUN:  state = RUNNING1; break;
        case JUMP: state = JUMPING; break;
    }
    mode = m;
}

void run() {

    switch (state) {
        case RUNNING1: state = RUNNING2; break;
        case RUNNING2: state = RUNNING3; break;
        case RUNNING3: state = RUNNING1; break;
        default: state = RUNNING1; break; 
    }
}

void render() {
    switch (mode) {
        case STAY:
            glRasterPos2f(pos_X, pos_Y);
            pix[0].mDraw();
            break;
            
        case RUN:
            run(); 
            glRasterPos2f(pos_X, pos_Y);
            pix[state].mDraw();
            break;
            
        case JUMP:
            glRasterPos2f(pos_X, pos_Y);
            pix[4].mDraw();
            break;
    }
}

void myInit(void) {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glViewport(0, 0, 640, 480);
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    pix[0].readBMPFile("images/MarioStanding.bmp", 1);
    pix[1].readBMPFile("images/MarioRun1.bmp", 1);
    pix[2].readBMPFile("images/MarioRun2.bmp", 1);
    pix[3].readBMPFile("images/MarioRun3.bmp", 1);
    pix[4].readBMPFile("images/MarioRun4.bmp", 1);

    for (int i = 0; i < IMAGES; i++) {
        pix[i].setChromaKey(192, 192, 192);
    }

    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_EQUAL, 1.0);

    changeMode(STAY);

    PlaySound("sounds/backmusic.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    render(); 
    
    glFlush();
}

void pressKeySpecial(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            changePosition(-20, 0);
            changeMode(RUN);
            break;
            
        case GLUT_KEY_RIGHT:
            changePosition(20, 0);
            changeMode(RUN);
            break;
            
        case GLUT_KEY_UP:
            if (pos_Y < 50) {
                changePosition(0, 50); 
                changeMode(JUMP);
            }
            break;
    }
    glutPostRedisplay();
}

void releaseKeySpecial(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:

            break;
            
        case GLUT_KEY_RIGHT:

        break;
            
        case GLUT_KEY_UP:
            if (pos_Y != 0) {
                setPosition(pos_X, 0); 
                changeMode(STAY);
            }
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Sprite Animation Demo");

    myInit();

    glutDisplayFunc(display);
    glutSpecialFunc(pressKeySpecial);
    glutSpecialUpFunc(releaseKeySpecial);

    glutMainLoop();
    return 0;
}