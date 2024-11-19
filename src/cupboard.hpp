#ifndef CUPBOARD_HPP
#define CUPBOARD_HPP

#include <GL/glut.h>
#include <GL/freeglut_ext.h>

class Cupboard {
public:
    void drawCupboard() {
        glColor3f(0.6f, 0.4f, 0.3f);
        glBegin(GL_QUADS);

        // Back
        glVertex3f(-1.5f, 0.5f, -1.5f);
        glVertex3f(-1.5f, 4.5f, -1.5f);
        glVertex3f(1.5, 4.5f, -1.5f);
        glVertex3f(1.5f, 0.5f, -1.5f);

        // Left Side
        glVertex3f(-1.5f, 0.5f, -1.5f);
        glVertex3f(-1.5f, 4.5f, -1.5f);
        glVertex3f(-1.5, 4.5f, 0.5f);
        glVertex3f(-1.5f, 0.5f, 0.5f);

        // Right Side
        glVertex3f(1.5f, 0.5f, -1.5f);
        glVertex3f(1.5f, 4.5f, -1.5f);
        glVertex3f(1.5, 4.5f, 0.5f);
        glVertex3f(1.5f, 0.5f, 0.5f);

        // Front
        glVertex3f(-1.5f, 0.5f, 0.5f);
        glVertex3f(-1.5f, 4.5f, 0.5f);
        glVertex3f(1.5, 4.5f, 0.5f);
        glVertex3f(1.5f, 0.5f, 0.5f);

        glColor3f(0.5f, 0.3f, 0.2f);
        // Left Support
        glVertex3f(-1.5f, 0.0f, -1.5f);
        glVertex3f(-1.5f, 0.5f, -1.5f);
        glVertex3f(-1.2, 0.5f, -1.5f);
        glVertex3f(-1.2f, 0.0f, -1.5f);

        glVertex3f(-1.5f, 0.0f, -1.5f);
        glVertex3f(-1.5f, 0.5f, -1.5f);
        glVertex3f(-1.5, 0.5f, 0.5f);
        glVertex3f(-1.5f, 0.0f, 0.5f);

        glVertex3f(-1.2f, 0.0f, -1.5f);
        glVertex3f(-1.2f, 0.5f, -1.5f);
        glVertex3f(-1.2, 0.5f, 0.5f);
        glVertex3f(-1.2f, 0.0f, 0.5f);

        glVertex3f(-1.5f, 0.0f, 0.5f);
        glVertex3f(-1.5f, 0.5f, 0.5f);
        glVertex3f(-1.2, 0.5f, 0.5f);
        glVertex3f(-1.2f, 0.0f, 0.5f);

        // Right Support
        glVertex3f(1.5f, 0.0f, -1.5f);
        glVertex3f(1.5f, 0.5f, -1.5f);
        glVertex3f(1.2f, 0.5f, -1.5f);
        glVertex3f(1.2f, 0.0f, -1.5f);

        glVertex3f(1.5f, 0.0f, -1.5f);
        glVertex3f(1.5f, 0.5f, -1.5f);
        glVertex3f(1.5f, 0.5f, 0.5f);
        glVertex3f(1.5f, 0.0f, 0.5f);

        glVertex3f(1.2f, 0.0f, -1.5f);
        glVertex3f(1.2f, 0.5f, -1.5f);
        glVertex3f(1.2f, 0.5f, 0.5f);
        glVertex3f(1.2f, 0.0f, 0.5f);

        glVertex3f(1.5f, 0.0f, 0.5f);
        glVertex3f(1.5f, 0.5f, 0.5f);
        glVertex3f(1.2f, 0.5f, 0.5f);
        glVertex3f(1.2f, 0.0f, 0.5f);

        glEnd();

        //lines
        glColor3f(0.149f, 0.149f, 0.149f);
        glLineWidth(5.0f);
        glBegin(GL_LINES);

        glVertex3f(-1.4f, 0.6f, 0.501f);
        glVertex3f(-1.4f, 4.4f, 0.501f);

        glVertex3f(-1.4f, 4.4f, 0.501f);
        glVertex3f(1.4f, 4.4f, 0.501f);

        glVertex3f(1.4f, 0.6f, 0.501f);
        glVertex3f(1.4f, 4.4f, 0.501f);

        glVertex3f(-1.4f, 0.6f, 0.501f);
        glVertex3f(1.4f, 0.6f, 0.501f);

        //middle line
        glVertex3f(0.0f, 0.6f, 0.501f);
        glVertex3f(0.0f, 4.4f, 0.501f);

        glEnd();

        // Handles
        glColor3f(0.5f, 0.5f, 0.5f);
        glPointSize(10.0f);
        glBegin(GL_POINTS);
        glVertex3f(-0.2f, 2.5f, 0.502f);
        glVertex3f(0.2f, 2.5f, 0.502f);
        glEnd();
    }
};

#endif
