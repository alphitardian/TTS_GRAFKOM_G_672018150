#include <iostream>
#include <GL/freeglut.h>
using namespace std;

void batikPattern() {
	
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

	glBegin(GL_POINTS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2f(300.0, 300.0);
	glEnd();

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