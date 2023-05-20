#include<GL/glut.h>
#define one 1.0
#define zero 0.0

void plot_point(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i((int)x, (int)y);
    glEnd();
}

void bresenhamcircle(int x0, int y0, int radius) {
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;
    plot_point(x0, y0 + radius);
    plot_point(x0, y0 - radius);
    plot_point(x0 + radius, y0);
    plot_point(x0 - radius, y0);

    while (x <= y) {
        if (d < 0) {
            d = d + 4 * x + 6;
        } else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
        plot_point(x0 + x, y0 + y);
        plot_point(x0 - x, y0 + y);
        plot_point(x0 + x, y0 - y);
        plot_point(x0 - x, y0 - y);
        plot_point(x0 + y, y0 + x);
        plot_point(x0 - y, y0 + x);
        plot_point(x0 + y, y0 - x);
        plot_point(x0 - y, y0 - x);
    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(one,one,one);
    for(int i=0;i<300;i++){
        if(i%25==0){
            bresenhamcircle(300,300,i);
        }
    }
    glFlush();
}

void init(){
    glClearColor(zero,zero,zero,zero);
    gluOrtho2D(0,700,0,700);
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(50,50);
    glutCreateWindow("whatever the fk exist\n");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
