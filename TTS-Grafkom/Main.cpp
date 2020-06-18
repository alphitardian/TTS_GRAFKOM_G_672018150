#include <iostream>
#include <GL/freeglut.h>
#include <math.h>
#define phi 3.14
using namespace std;

class MyPattern {
	public:
		void mainPattern(float delta_x, float delta_y) {
			drawLeftEclipse(25 + delta_x, 275 + delta_y);
			drawRightEclipse(75 + delta_x, 275 + delta_y);
			drawRightEclipse(25 + delta_x, 225 + delta_y);	
			drawLeftEclipse(75 + delta_x, 225 + delta_y);
		}

		void batikDetails(float point_x1, float point_x2, float point_y1, float point_y2) {
			glBegin(GL_POINTS);
			int x1 = point_x1, y1 = point_y1, x2 = point_x2, y2 = point_y2;
			for (int i = 0; i < 100; i++) {
				glVertex2f(x1, y1);
				x1 += 10;
				y1 -= 10;

				glVertex2f(x2, y2);
				x2 += 10;
				y2 += 10;
			}
			glEnd();
		}

	private:
		void drawLeftEclipse(float x_center, float y_center) {
			glColor3f(0.68, 0.32, 0.22);
			glBegin(GL_POLYGON);
			for (int i = 0; i < 360; i++) {
				glVertex2f(cos(i * phi / 180 + 100) * 25 + x_center, sin(i * phi / 180 + 250) * 25 + y_center);
			}
			glEnd();

			glColor3f(0.83, 0.82, 0.84);
			glBegin(GL_LINE_LOOP);
			for (int i = 0; i < 360; i++) {
				glVertex2f(cos(i * phi / 180 + 100) * 25 + x_center, sin(i * phi / 180 + 250) * 25 + y_center);
			}
			glEnd();
		}

		void drawRightEclipse(float x_center, float y_center) {
			glColor3f(0.68, 0.32, 0.22);
			glBegin(GL_POLYGON);
			for (int i = 0; i < 360; i++) {
				glVertex2f(cos(i * phi / 180 - 100) * 25 + x_center, sin(i * phi / 180 - 250) * 25 + y_center);
			}
			glEnd();

			glColor3f(0.83, 0.82, 0.84);
			glBegin(GL_LINE_LOOP);
			for (int i = 0; i < 360; i++) {
				glVertex2f(cos(i * phi / 180 - 100) * 25 + x_center, sin(i * phi / 180 - 250) * 25 + y_center);
			}
			glEnd();
		}
};

void myInit() {
	glClearColor(0.07, 0.05, 0.07, 0.0);
	glPointSize(3);
	glLineWidth(5);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	MyPattern batikPattern;

	float delta_x = 0.0;
	float delta_y = 200;

	/* Main */
	for (int i = 0; i < 5; i++) {
		for (int i = 0; i < 5; i++) {
			batikPattern.mainPattern(delta_x, delta_y);
			delta_x += 100;
		}
		delta_x = 0.0;
		delta_y -= 100;
	}

	/* Detail */
	int detail_x = 490, detail_y = 400;
	int detail_x2 = 110, detail_y2 = 400;
	for (int i = 0; i < 5; i++) {
		batikPattern.batikDetails(10, 0, detail_x, detail_y);
		detail_x -= 100;
		detail_y -= 100;

		batikPattern.batikDetails(detail_x2, detail_y2, 490, 0);
		detail_x2 += 100;
		detail_y2 -= 100;
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