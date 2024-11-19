#ifndef CHAIR_HPP
#define CHAIR_HPP

#include <GL/glut.h>
#include <GL/freeglut_ext.h>

class Chair {
public:
    void drawChair() {
        // Rich brown color scheme
        float seatColor[] = {0.8f, 0.1f, 0.1f};      // Cherry red
        float backrestColor[] = {0.6f, 0.0f, 0.0f}; // Burgundy
        float legColor[] = {0.4f, 0.2f, 0.1f};     // Dark oak

        // Seat
        glColor3fv(seatColor);
        glPushMatrix();
        glTranslatef(0.0f, -1.0f, 0.0f);
        glScalef(1.8f, 0.1f, 1.8f);
        glutSolidCube(2.0);
        glPopMatrix();

        // Backrest
        glColor3fv(backrestColor);
        glPushMatrix();
        glTranslatef(0.0f, 1.0f, -1.6f);
        glScalef(1.8f, 2.0f, 0.1f);
        glutSolidCube(2.0);
        glPopMatrix();

        // Legs
        glColor3fv(legColor);
        
        // Front-left leg
        glPushMatrix();
        glTranslatef(-1.5f, -2.0f, 1.5f);
        glScalef(0.1f, 1.0f, 0.1f);
        glutSolidCube(2.0);
        glPopMatrix();

        // Front-right leg
        glPushMatrix();
        glTranslatef(1.5f, -2.0f, 1.5f);
        glScalef(0.1f, 1.0f, 0.1f);
        glutSolidCube(2.0);
        glPopMatrix();

        // Back-left leg
        glPushMatrix();
        glTranslatef(-1.5f, -2.0f, -1.5f);
        glScalef(0.1f, 1.0f, 0.1f);
        glutSolidCube(2.0);
        glPopMatrix();

        // Back-right leg
        glPushMatrix();
        glTranslatef(1.5f, -2.0f, -1.5f);
        glScalef(0.1f, 1.0f, 0.1f);
        glutSolidCube(2.0);
        glPopMatrix();
    }
};

#endif
