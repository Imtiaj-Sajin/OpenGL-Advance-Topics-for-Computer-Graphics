#include <GL/glut.h>
#include <string>
#include"textAdder.h"

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    staticText("sssstasdtast", 300, 340, 0.2, 2, 0.3, 0.3,0.3); 
    morphedText("qasdfasdf asdfasdf", 600, 540, 0.2, 2, 0.3, 0.3,0.3); 
    glFlush();
}

void update(int value) {
    
    // Update animation time
    morphSpeed += 0.2;

    // Call display function to redraw the screen
    glutPostRedisplay();

    // Set timer for the next update
    glutTimerFunc(100, update, 0);
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0, 1920, 0, 1080);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("Text Morphing Animation");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0); 
    glutMainLoop();
    return 0;
}
