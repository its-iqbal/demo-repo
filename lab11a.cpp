#include <GL/glut.h>

// Function 1
void renderBitmapScreen(float x, float y, void* font, char* string) {
    glRasterPos2f(x, y);
    for (char* c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

// Function 2
void print(int x, int y, char* string, void* font) {
    glRasterPos2i(x, y);
    int i = 0;
    while (string[i] != '\0') {
        glutBitmapCharacter(font, string[i]);
        i++;
    }
}

// Function 3
void drawString(const char* string) {
    for (int i = 0; string[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    // Calling Func 1
    // renderBitmapScreen(-0.8, 0.6, GLUT_BITMAP_9_BY_15, (char*)"Programming Fundamental");

    // Calling Func 2
    // print(-0.8, 0.6, (char*)"Programming Fundamental", GLUT_BITMAP_TIMES_ROMAN_24);

    // Calling Func 3
    glRasterPos2f(-0.8, -0.6); 
    drawString("Programming Fundamental");

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Three Functions");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}