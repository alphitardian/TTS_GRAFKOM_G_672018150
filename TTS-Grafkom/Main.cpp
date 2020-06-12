#include <iostream>
#include <GL/freeglut.h>
#include <math.h>
#define phi 3.14
using namespace std;

void drawLeftEllipse(float x_rads, float y_rads, float x_center, float y_center) {
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		glVertex2f(cos(i * phi / 180 + 100) * x_rads + x_center, sin(i * phi / 180 + 250) * y_rads + y_center);
	}
	glEnd();
}

void drawRightEllipse(float x_rads, float y_rads, float x_center, float y_center) {
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		glVertex2f(cos(i * phi / 180 - 100) * x_rads + x_center, sin(i * phi / 180 - 250) * y_rads + y_center);
	}
	glEnd();
}

void mainBatikPattern(float delta_x, float delta_y) {
	drawLeftEllipse(25, 25, 25 + delta_x, 275 + delta_y);
	drawRightEllipse(25, 25, 75 + delta_x, 275 + delta_y);
	drawRightEllipse(25, 25, 25 + delta_x, 225 + delta_y);
	drawLeftEllipse(25, 25, 75 + delta_x, 225 + delta_y);
}

void myInit() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glPointSize(10);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	int delta_x1 = 0.0, delta_x2 = 0.0, delta_x3 = 0.0, delta_x4 = 0.0, delta_x5 = 0.0;

	/* 1st Level */
	for (int i = 0; i < 5; i++) {
		mainBatikPattern(delta_x1, 200);
		delta_x1 += 100;
	}

	/* 2nd Level */
	for (int i = 0; i < 5; i++) {
		mainBatikPattern(delta_x2, 100);
		delta_x2 += 100;
	}

	/* Center */
	for (int i = 0; i < 5; i++) {
		mainBatikPattern(delta_x3, 0);
		delta_x3 += 100;
	}

	/* 4th Level */
	for (int i = 0; i < 5; i++) {
		mainBatikPattern(delta_x4, -100);
		delta_x4 += 100;
	}

	/* 5th Level */
	for (int i = 0; i < 5; i++) {
		mainBatikPattern(delta_x5, -200);
		delta_x5 += 100;
	}

	glFlush();

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Tugas 3 - Grafika Komputer");

	glutDisplayFunc(display);

	myInit();
	glutMainLoop();
	return 0;
}