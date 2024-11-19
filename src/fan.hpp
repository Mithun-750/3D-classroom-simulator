#ifndef FAN_HPP
#define FAN_HPP

#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include <math.h>

#define DEF_D 5

class Fan {
private:
    float rotationAngle = 0.0f;
    bool isOn = false;

public:
    void drawFan() {
        glTranslatef(0, 5, -5.0);
        glScalef(5, 5, 5);

        // Ceiling mount (distinctive lighter color)
        glPushMatrix();
        glColor3f(0.7f, 0.7f, 0.7f);  // Light gray mount for contrast
        glTranslatef(0, -1.0, 0);
        glScalef(0.1, 0.3, 0.1);
        glutSolidCylinder(1.0, 1.0, 20, 20);
        glPopMatrix();

        // Rotating fan assembly
        glPushMatrix();
        glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);

        // Center hub
        glPushMatrix();
        glColor3f(0.75f, 0.75f, 0.75f);  // Silver hub
        glTranslatef(0, -1.3, 0);
        glutSolidSphere(0.15, 20, 20);
        glPopMatrix();

        // Fan blades (longer and darker)
        for(int i = 0; i < 4; i++) {
            glPushMatrix();
            glRotatef(i * 90, 0, 1, 0);
            glColor3f(0.6f, 0.7f, 0.8f);  // Steel blue blades
            glTranslatef(0.8, -1.3, 0);  // Moved further out for longer blades
            glScalef(1.6, 0.05, 0.2);    // Increased length
            glutSolidCube(1.0);
            glPopMatrix();
        }

        glPopMatrix();
    }

    void rotateFan() {
        if (isOn) {
            rotationAngle += 1.0f;
            if (rotationAngle > 360.0f) rotationAngle -= 360.0f;
        }
    }

    void toggleFan() { isOn = !isOn; }
    bool getState() const { return isOn; }
};

#endif
