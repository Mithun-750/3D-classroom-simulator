#ifndef TABLE_HPP
#define TABLE_HPP

#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include <cmath>

class Table {
private:
    void drawModernLeg(float x, float z) {
        glPushMatrix();
        glTranslatef(x, -1.4f, z);
        
        // Main leg - rectangular prism
        glBegin(GL_QUADS);
        
        // Front
        glVertex3f(-0.2f, -1.4f, 0.2f);
        glVertex3f(0.2f, -1.4f, 0.2f);
        glVertex3f(0.2f, 1.4f, 0.2f);
        glVertex3f(-0.2f, 1.4f, 0.2f);

        // Back
        glVertex3f(-0.2f, -1.4f, -0.2f);
        glVertex3f(0.2f, -1.4f, -0.2f);
        glVertex3f(0.2f, 1.4f, -0.2f);
        glVertex3f(-0.2f, 1.4f, -0.2f);

        // Left
        glVertex3f(-0.2f, -1.4f, -0.2f);
        glVertex3f(-0.2f, -1.4f, 0.2f);
        glVertex3f(-0.2f, 1.4f, 0.2f);
        glVertex3f(-0.2f, 1.4f, -0.2f);

        // Right
        glVertex3f(0.2f, -1.4f, -0.2f);
        glVertex3f(0.2f, -1.4f, 0.2f);
        glVertex3f(0.2f, 1.4f, 0.2f);
        glVertex3f(0.2f, 1.4f, -0.2f);
        glEnd();
        
        glPopMatrix();
    }

public:
    void drawTable() {
        // Table top
        glBegin(GL_QUADS);
        glColor3f(0.5f, 0.2f, 0.1f);  // Mahogany color

        // Top face
        glVertex3f(-4.0f, 0.2f, 2.0f);
        glVertex3f(2.0f, 0.2f, 2.0f);
        glVertex3f(2.0f, 0.2f, -2.0f);
        glVertex3f(-4.0f, 0.2f, -2.0f);

        // Bottom face
        glVertex3f(-4.0f, -0.2f, 2.0f);
        glVertex3f(2.0f, -0.2f, 2.0f);
        glVertex3f(2.0f, -0.2f, -2.0f);
        glVertex3f(-4.0f, -0.2f, -2.0f);

        // Front face
        glVertex3f(-4.0f, -0.2f, 2.0f);
        glVertex3f(2.0f, -0.2f, 2.0f);
        glVertex3f(2.0f, 0.2f, 2.0f);
        glVertex3f(-4.0f, 0.2f, 2.0f);

        // Back face
        glVertex3f(-4.0f, -0.2f, -2.0f);
        glVertex3f(2.0f, -0.2f, -2.0f);
        glVertex3f(2.0f, 0.2f, -2.0f);
        glVertex3f(-4.0f, 0.2f, -2.0f);

        // Left face
        glVertex3f(-4.0f, -0.2f, -2.0f);
        glVertex3f(-4.0f, -0.2f, 2.0f);
        glVertex3f(-4.0f, 0.2f, 2.0f);
        glVertex3f(-4.0f, 0.2f, -2.0f);

        // Right face
        glVertex3f(2.0f, -0.2f, -2.0f);
        glVertex3f(2.0f, -0.2f, 2.0f);
        glVertex3f(2.0f, 0.2f, 2.0f);
        glVertex3f(2.0f, 0.2f, -2.0f);
        glEnd();

        // Table legs
        glColor3f(1.0f, 1.0f, 1.0f);  // Original golden brown color

        // Front right leg
        drawModernLeg(1.6f, 1.6f);

        // Front left leg
        drawModernLeg(-3.6f, 1.6f);

        // Back right leg
        drawModernLeg(1.6f, -1.6f);

        // Back left leg
        drawModernLeg(-3.6f, -1.6f);
    }
};

#endif
