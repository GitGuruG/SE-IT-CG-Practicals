#include <GL/glut.h>
#include <iostream>

#define zero 0.0
#define one 1.0

using namespace std;

int a, b, c, d, type;

void dda(int x1, int y1, int x2, int y2, int type) {
    float step,x,y,k,Xin,Yin;
    int dx=x2-x1;
    int dy=y2-y1;

    step=abs(dx)> abs(dy)?abs(dx):abs(dy);

    Xin = dx/step;
    Yin = dy/step;

    x= x1;
    y=y1;
    glPointSize(1.0f);
    if(type==4){
        glPointSize(10.0f);
    }
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    int j=0;
    for (k=1 ;k<=step;k++)
    {
    x= x + Xin;
    y= y + Yin;
        if (type == 4 || type == 1) {
            glVertex2i((int)x, (int)y);
        }
        if (j % 4 == 0 && type == 2) {
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
    glColor3f(one, zero, zero);
    dda(-350, 0, 350, 0, 1);
    dda(0, 350, 0, -350, 1);
    glFlush();
}

void init() {
 glClearColor(0.6, 0.6, 0.6, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  gluOrtho2D(-700 / 2, 700 / 2, -700 / 2, 700 / 2);
}

int cnt=0;
int oldx,oldy;
int newx,newy;
void mouse(int button, int state, int x, int y)
{
  if (state == GLUT_DOWN)
  {
    if (button == GLUT_LEFT_BUTTON)
    {
      int xi = x- 350;
      int yi = 350-y;

      cout << xi << "\t" << yi << "\n";

      cnt = (cnt + 1) % 2;

      if (cnt == 1)
      {
        oldx = xi;
        oldy = yi;
        cout << "a" << endl;
      }
      if (cnt == 0)
      {
        newx = xi;
        newy = yi;
        cout << "b" << endl;
      }

      glPointSize(5.0f);
      glColor3f(1.0, 0.0, 0.0);
      glBegin(GL_POINTS);
      glVertex2i(xi, yi);

      glEnd();
      glFlush();
    }
  }
}

void menu(int a){
    cout<<"whatever\n";
    dda(oldx,oldy,newx,newy,a);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Line Drawing");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutCreateMenu(menu);
    glutAddMenuEntry("DDA_SIMPLE", 1);
    glutAddMenuEntry("DDA_DOTTED", 2);
    glutAddMenuEntry("DDA_DASHED", 3);
    glutAddMenuEntry("DDA_SOLID", 4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();

    return 0;
}
/*
How to run?
1.make left click on first position
2.make left click on second position
3.now hold right button and leave it on choice
4.hold left click to see line
*/
