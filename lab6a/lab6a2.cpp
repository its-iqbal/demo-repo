#include <GL/glut.h>
#include <cmath>

void draw() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 1.0f, 1.0f); 

    glBegin(GL_LINE_STRIP);
    for (float x = -1.0; x <= 1.0; x += 0.01) {
        float y = sin(x * 3.14159); 
        glVertex2f(x, y); 
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Simple Sin Wave");
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}