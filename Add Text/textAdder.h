#include <GL/glut.h>
#include <string>
#include <string>
#include<windows.h>
void drawText(std::string text, int posX, int posY, float scale, int fontWeight, float colorR, float colorG, float colorB) {
    glPushMatrix();
    glTranslatef(posX, posY, 0);
    glScalef(scale, scale, scale);
    glLineWidth(fontWeight);
    glColor3f(colorR, colorG, colorB);

    for (char &c : text) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, c); 
    }

    glPopMatrix();
}

