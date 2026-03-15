#include <GL/glut.h>
#include <cmath>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glLineWidth(3.0f);           
    glColor3f(0.0f, 1.0f, 1.0f); 

    float radius = 0.6f;
    float cx = 0.0f, cy = 0.0f;
    const float PI = 3.1415926f;

    glBegin(GL_LINE_LOOP); 
    for (int i = 0; i <= 360; i++) {
        float theta = i * PI / 180.0f;
        float x = cx + radius * cos(theta);
        float y = cy + radius * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();

    glFlush();
}

void init() {
   
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("GLUT Circle Drawing");
    
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}