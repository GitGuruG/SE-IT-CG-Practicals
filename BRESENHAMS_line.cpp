#include <GL/glut.h>
#include <iostream>

#define zero 0.0
#define one 1.0

using namespace std;

int a, b, c, d, type;

void BresenhamLine(int x1, int y1, int x2, int y2, int type) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    float decision= 2*dy-dx;

    glColor3f(one, one, one);
    if (type == 4) {
        glPointSize(5.0f);
    } else {
        glPointSize(1.0f);
    }
    glBegin(GL_POINTS);

    float x = x1, y = y1;
    int j = 0;
    for (int i = 0; i < abs(dx); i++) {

         if(decision<0){
            x++;
            d+=2*dy;
         }else{
            x++; y++;
            d+= 2*(dy-dx);
         }

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
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(zero, zero, zero);
    BresenhamLine(a, b, c, d, type);
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
/*
    Negative slope is not supported in the given code. However,
    you can refer to the "BRESENHAM_LINE_WITH_MOUSE_INTERFACE.cpp"
    file available in this repository to obtain a line with a negative slope.
    You can simply copy and paste the algorithm from there.

    although this algo. is also popular. short and simple
    but just in case
  */
