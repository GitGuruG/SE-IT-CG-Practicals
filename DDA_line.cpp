#include <GL/glut.h>
#include <iostream>

#define zero 0.0
#define one 1.0

using namespace std;

int a, b, c, d, type;

void dda(int x1, int y1, int x2, int y2, int type) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int length = dx > dy ? dx : dy;

    float ix = (float)dx / (float)length;
    float iy = (float)dy / (float)length;

    glColor3f(one, one, one);
    if (type == 4) {
        glPointSize(5.0f);
    } else {
        glPointSize(1.0f);
    }
    glBegin(GL_POINTS);

    float x = x1, y = y1;
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (type == 4 || type == 1) {
            glVertex2i((int)x, (int)y);
        }
        if (j % 2 == 0 && type == 2) {
            glVertex2i((int)x, (int)y);
        }
        if (j < 5 && type == 3) {
            glVertex2i((int)x, (int)y);
        }
        j = (j + 1) % 10;
        x += ix;
        y += iy;
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(zero, zero, zero);
    dda(a, b, c, d, type);
    glFlush();
}

void init() {
    glClearColor(zero, zero, zero, zero);
    gluOrtho2D(0, 700, 0, 700);
}

int main(int argc, char** argv) {
    cout << "Enter coordinates of initial point: ";
    cin >> a >> b;
    cout << "Enter coordinates of final point: ";
    cin >> c >> d;

    cout << "Enter type of line:\n";
    cout << "1. Simple Line\n";
    cout << "2. Dotted Line\n";
    cout << "3. Dashed Line\n";
    cout << "4. Solid Line\n";
    cin >> type;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Line Drawing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
