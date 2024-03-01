#include <GL/glut.h>
#include <string>
#include <string>
#include<windows.h>
#include <cmath>



///////////////
std::string originalText = "asdf$!";
std::string targetText = "Welcome!";
float animationDuration = 5.0; 
float morphSpeed = 0.0; 

std::string calculateMorphedText(float time) {
    float t = std::min(1.0f, std::max(0.0f, time / animationDuration)); // Normalize time between 0 and 1
    std::string morphedText;

    for (size_t i = 0; i < originalText.size() && i < targetText.size(); ++i) {
        float c1 = originalText[i];
        float c2 = targetText[i];
        float morphedChar = c1 * (1.0 - t) + c2 * t;
        morphedText += static_cast<char>(morphedChar);
    }

    return morphedText;
}


void morphedText(std::string text, int posX, int posY, float scale, int fontWeight, float colorR, float colorG, float colorB) {
    targetText=text;

    std::string morphedText = calculateMorphedText(morphSpeed);

    glPushMatrix();
    glTranslatef(posX, posY, 0); 
    glScalef(scale, scale, scale);
    glLineWidth(fontWeight); 
    glColor3f(colorR, colorG, colorB); 

    // Render each character of the morphed text
    for (char &c : morphedText) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, c); //GLUT's stroke font to render text
    }

    glPopMatrix();
}

/////

// Function to animate the text



//////

void staticText(std::string text, int posX, int posY, float scale, int fontWeight, float colorR, float colorG, float colorB) {
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

//////////////
