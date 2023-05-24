#include <GL/glut.h>
#include <iostream>

#define zero 0.0
#define one 1.0

using namespace std;

int a, b, c, d, type;

void dda(int x1, int y1, int x2, int y2, int type) {
    cout<<"IN"<<endl;
    float step,x,y,k,Xin,Yin;
    int dx=x2-x1;
    int dy=y2-y1;

if(abs(dx)> abs(dy))
{
step = abs(dx);
}
else
step = abs(dy);

Xin = dx/step;
Yin = dy/step;

x= x1;
y=y1;
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();

for (k=1 ;k<=step;k++)
{
x= x + Xin;
y= y + Yin;

glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
}
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
