#include <iostream>
#include <math.h>
#include <string.h>

#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include "src/chair.hpp"
#include "src/table.hpp"
#include "src/cupboard.hpp"
#include "src/window.hpp"
#include "src/fan.hpp"

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000

using namespace std;

// angle of rotation for the camera direction
float angle = 0.0, yAngle = 0.0;
// actual vector representing the camera's direction
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
// XZ position of the camera
float x = -5.0f, z = 18.0f;
float roll = 0.0f;

//for mouse movements
float halfWidth = (float)(WINDOW_WIDTH/2.0);
float halfHeight = (float)(WINDOW_HEIGHT/2.0);
float mouseX = 0.0f, mouseY = 0.0f;
bool rightMouseDown = false;
float targetAngle = 0.0f, targetYAngle = 0.0f;
float smoothFactor = 0.3f; // Increased from 0.1 to 0.3 for faster response
float mouseSensitivity = 0.03f; // Increased from 0.015 to 0.03 for more sensitive movement

//Fan
Fan f;


void renderScene(void) {

	// Clear Color and Depth Buffers

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(x, 2.5f, z,
		x + lx, 2.5f + ly, z + lz,
		roll + 0.0f, 2.5f, 0.0f);

	// Draw floor
	glColor3f(0.4f, 0.4f, 0.45f);  // Medium gray with slight blue tint for floor
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 0.0f, -10.0f);
	glVertex3f(-10.0f, 0.0f, 10.0f);
	glVertex3f(10.0f, 0.0f, 10.0f);
	glVertex3f(10.0f, 0.0f, -10.0f);
	glEnd();

    //wall
    glColor3f(0.75f, 0.82f, 0.88f);  // Light blue-gray for front wall
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 0.0f, -10.0f);
	glVertex3f(-10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 0.0f, -10.0f);
	glEnd();

	//wall
    glColor3f(0.85f, 0.85f, 0.75f);  // Warm light gray for side walls
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 0.0f, -10.0f);
	glVertex3f(-10.0f, 7.0f, -10.0f);
	glVertex3f(-10.0f, 7.0f, 10.0f);
	glVertex3f(-10.0f, 0.0f, 10.0f);
	glEnd();

	//wall with door
    glColor3f(0.85f, 0.85f, 0.75f);  // Matching side wall color
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 0.0f, 10.0f);
	glVertex3f(-10.0f, 7.0f, 10.0f);
	glVertex3f(-6.0f, 7.0f, 10.0f);
	glVertex3f(-6.0f, 0.0f, 10.0f);
	glEnd();

	glColor3f(0.85f, 0.85f, 0.75f);
	glBegin(GL_QUADS);
	glVertex3f(-3.0f, 0.0f, 10.0f);
	glVertex3f(-3.0f, 7.0f, 10.0f);
	glVertex3f(10.0f, 7.0f, 10.0f);
	glVertex3f(10.0f, 0.0f, 10.0f);
	glEnd();

	glColor3f(0.85f, 0.85f, 0.75f);
	glBegin(GL_QUADS);
	glVertex3f(-6.0f, 7.0f, 10.0f);
	glVertex3f(-6.0f, 5.0f, 10.0f);
	glVertex3f(-3.0f, 5.0f, 10.0f);
	glVertex3f(-3.0f, 7.0f, 10.0f);
	glEnd();

    // Door frame
    glColor3f(0.45f, 0.25f, 0.15f);  // Rich medium wood color
    glLineWidth(30.0f);
    glBegin(GL_LINES);
    glVertex3f(-6.0f, 5.0f, 10.01f);
    glVertex3f(-3.0f, 5.0f, 10.01f);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-6.0f, 5.0f, 10.01f);
    glVertex3f(-6.0f, 0.0f, 10.01f);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-3.0f, 0.0f, 10.01f);
    glVertex3f(-3.0f, 5.0f, 10.01f);
    glEnd();

	//wall
    glColor3f(0.85f, 0.85f, 0.75f);  // Matching side wall color
	glBegin(GL_QUADS);
	glVertex3f(10.0f, 0.0f, -10.0f);
	glVertex3f(10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 7.0f, 10.0f);
	glVertex3f(10.0f, 0.0f, 10.0f);
	glEnd();

	//ceiling
	glColor3f(0.82f, 0.82f, 0.82f);  // Darker ceiling color
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 7.0f, 10.0f);
	glVertex3f(-10.0f, 7.0f, 10.0f);
	glEnd();

	// Draw prof's chair
	Chair profChair;
	glPushMatrix();
	glTranslatef( 6.0f, 1.0f, -9.0f);
	glScalef(0.32f, 0.32f, 0.32f);
	glRotatef(-30.0, 0.0, 1.0, 0.0);
	profChair.drawChair();
	glPopMatrix();

	// Draw prof's table
	Table profTable;
	glPushMatrix();
	glTranslatef( 6.0f, 1.4f, -7.6f);
	glScalef(0.5f, 0.5f, 0.5f);
	glRotatef(-30.0, 0.0, 1.0, 0.0);
	profTable.drawTable();
	glPopMatrix();

	// Draw student chairs
	Chair studentChair[4][4];
	for (int i = -3; i <= 3; i+=2){
		for (int j = -3; j <= 3; j+=2) {
			glPushMatrix();
			glTranslatef(i*2.0, 0.8f, j * 2.0 + 2.2f);
			glScalef(0.25f, 0.25f, 0.25f);
			glRotatef(180.0, 0.0, 1.0, 0.0);
			studentChair[i][j].drawChair();
			glPopMatrix();
		}
	}

	// Draw student tables
	Table studentTable[4][4];
	for (int i = -3; i <= 3; i+=2){
		for (int j = -3; j <= 3; j+=2) {
			glPushMatrix();
			glTranslatef(i*2.0 + 0.3f, 1.2f, j * 2.0 + 1.2f);
			glScalef(0.4f, 0.4f, 0.4f);
			studentTable[i][j].drawTable();
			glPopMatrix();
		}
	}

	// Draw cupboard
	Cupboard cupboard;
	glPushMatrix();
	glTranslatef( 8.49f, 0.0f, -3.5f);
	glRotatef(-90.0, 0.0, 1.0, 0.0);
	cupboard.drawCupboard();
	glPopMatrix();

	// Blackboard
    glColor3f(0.2f, 0.2f, 0.2f);  // Dark gray for blackboard frame
    glBegin(GL_QUADS);
    glVertex3f(-6.0f, 2.0f, -9.99f);
    glVertex3f(-6.0f, 5.5f, -9.99f);
    glVertex3f(6.0f, 5.5f, -9.99f);
    glVertex3f(6.0f, 2.0f, -9.99f);
    glEnd();

	glColor3f(0.149f, 0.149f, 0.149f);
	glBegin(GL_QUADS);
	glVertex3f(-5.8f, 2.2f, -9.98f);
	glVertex3f(-5.8f, 5.3f, -9.98f);
	glVertex3f(5.8f, 5.3f, -9.98f);
	glVertex3f(5.8f, 2.2f, -9.98f);
	glEnd();

	//Floor pattern
	glColor3f(0.149f, 0.149f, 0.149f);
	glLineWidth(3.0f);
	for(int i = 0; i < 20; i += 2)
	{
		glBegin(GL_LINES);
		glVertex3f(-10.0f + i, 0.001f, -10.01f);
		glVertex3f(-10.0f + i, 0.001f, 10.01f);
		glEnd();
	}
	for(int i = 0; i < 20; i += 2)
	{
		glBegin(GL_LINES);
		glVertex3f(-10.0f, 0.001f, -10.01f + i);
		glVertex3f(10.0f, 0.001f, -10.01f + i);
		glEnd();
	}

	//windows
	Window w;
	w.drawWindow1();
	w.drawWindow2();
	w.drawWindowSill();
	glPushMatrix();
	glTranslatef( 0.0f, 0.0f, 8.0f);
	w.drawWindowSill();
	glPopMatrix();

	// Draw fan switch
    glPushMatrix();
    glColor3f(0.8f, 0.8f, 0.8f);
    glTranslatef(7.0f, 4.0f, -9.98f);  // Position on front wall
    glBegin(GL_QUADS);
    glVertex3f(-0.2f, -0.3f, 0.0f);
    glVertex3f(-0.2f, 0.3f, 0.0f);
    glVertex3f(0.2f, 0.3f, 0.0f);
    glVertex3f(0.2f, -0.3f, 0.0f);
    glEnd();
    
    // Switch toggle indicator
    glColor3f(f.getState() ? 0.0f : 1.0f, f.getState() ? 1.0f : 0.0f, 0.0f);  // Red when off, green when on
    glTranslatef(0.0f, 0.0f, 0.01f);
    glBegin(GL_QUADS);
    glVertex3f(-0.1f, -0.2f, 0.0f);
    glVertex3f(-0.1f, 0.2f, 0.0f);
    glVertex3f(0.1f, 0.2f, 0.0f);
    glVertex3f(0.1f, -0.2f, 0.0f);
    glEnd();
    glPopMatrix();

	// Draw fan
	glPushMatrix();
	glTranslatef(0.0f, 6.0f, 0.0);
	glScalef(0.3f, 0.3f, 0.3f);
	f.drawFan();
	glPopMatrix();

	
	glutSwapBuffers();
}

// Handles the events triggered when one of the arrow keys are pressed.
// @param key : key pressed
// @param xx : x coordinate of mouse position
// @param yy : y coordinate of mouse position
void processSpecialKeys(int key, int xx, int yy) {

	float fraction = 0.1f;

	switch (key) {
	case GLUT_KEY_LEFT:
		x += sin(angle - M_PI/2.0) * fraction;
		z += -cos(angle - M_PI/2.0) * fraction;
		break;
	case GLUT_KEY_RIGHT:
		x += sin(M_PI/2.0 + angle) * fraction;
		z += -cos(M_PI/2.0 + angle) * fraction;
		break;
	case GLUT_KEY_UP:
		x += lx * fraction;
		z += lz * fraction;
		break;
	case GLUT_KEY_DOWN:
		x -= lx * fraction;
		z -= lz * fraction;
		break;
	}
}


// Handles the events triggered when any key on the keyboard is pressed.
//Specifically, handles w,a,s,d and Esc.
// moves the camera frward, backward and sideways.
// @param key : key pressed
// @param xx : x coordinate of mouse position
// @param yy : y coordinate of mouse position
void processNormalKeys(unsigned char key, int xx, int yy) {
    float fraction = 0.1f;
    if(key == 'w'){
        x += lx * fraction;
		z += lz * fraction;
    } else if(key == 'a'){
        x += sin(angle - M_PI/2.0) * fraction;
		z += -cos(angle - M_PI/2.0) * fraction;
    } else if(key == 's'){
        x -= lx * fraction;
		z -= lz * fraction;
    } else if(key == 'd'){
        x += sin(M_PI/2.0 + angle) * fraction;
		z += -cos(M_PI/2.0 + angle) * fraction;
    } else if (key == 'x') {
		roll += 0.5f;
	} else if (key == 'z') {
		roll -= 0.5f;
	}
	
	if (key == 27)
		exit(0);
}

void processMouseMovement(int xx, int yy) {
    if (!rightMouseDown) return;
    
    mouseX = (float)(halfWidth - xx)/halfWidth;
    mouseY = (float)(halfHeight - yy)/halfHeight;
    
    // Update target angles with increased sensitivity (changed from 0.005f to 0.015f)
    targetAngle = angle - (mouseSensitivity * mouseX);
    if(abs(yAngle - (mouseSensitivity * mouseY)) < (M_PI/2)) {  
        targetYAngle = yAngle - (mouseSensitivity * mouseY);     
    }
}

void processMouseButtons(int button, int state, int xx, int yy) {
    if (button == GLUT_RIGHT_BUTTON) {
        rightMouseDown = (state == GLUT_DOWN);
    }
    // Fan switch - left click to toggle
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Convert mouse coordinates to OpenGL coordinates
        GLint viewport[4];
        GLdouble modelview[16];
        GLdouble projection[16];
        GLfloat winX, winY, winZ;
        GLdouble posX, posY, posZ;

        glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
        glGetDoublev(GL_PROJECTION_MATRIX, projection);
        glGetIntegerv(GL_VIEWPORT, viewport);

        winX = (float)xx;
        winY = (float)viewport[3] - (float)yy;
        glReadPixels(xx, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);

        gluUnProject(winX, winY, winZ,
                    modelview, projection, viewport,
                    &posX, &posY, &posZ);

        // Check if click is near the switch position
        float switchX = 7.0f;
        float switchY = 4.0f;
        float switchZ = -9.98f;

        float dx = posX - switchX;
        float dy = posY - switchY;
        float dz = posZ - switchZ;

        // Increase the click detection area
        float clickRadius = 1.0f;
        if (dx * dx + dy * dy + dz * dz < clickRadius * clickRadius) {
            f.toggleFan();
            glutPostRedisplay();  
        }
    }
}

void animate() {
    // Smooth camera movement
    if (rightMouseDown || angle != targetAngle || yAngle != targetYAngle) {
        angle = angle * (1-smoothFactor) + targetAngle * smoothFactor;
        yAngle = yAngle * (1-smoothFactor) + targetYAngle * smoothFactor;

        lx = sin(angle);
        ly = -sin(yAngle);
        lz = -cos(angle);
    }

    // Rotate the fan
    f.rotateFan();

    glutPostRedisplay();
}

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);
	halfWidth = (float)(w/2.0);
	halfHeight = (float)(h/2.0);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Classroom");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(animate);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
    glutMotionFunc(processMouseMovement);
    glutMouseFunc(processMouseButtons);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}