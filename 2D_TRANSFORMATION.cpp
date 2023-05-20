#include <GL/glut.h>
#include <math.h>
#include<bits/stdc++.h>
using namespace std;

int pntX1,pntY1,choice=0,edges=4;
vector<int>pntX;
vector<int>pntY;
int decision=0;
double scalefactorX,scalefactorY;
char reflectionAxis;
double theta;
int transX,transY;
int arbX,arbY;

double round(double d){
    return floor(d+0.5);
}

void drawPolygon(){
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    for(int i=0;i<edges;i++){
        glVertex2i(pntX[i],pntY[i]);
    }
    glEnd();
}

void drawPolygonTrans(int tx,int ty){
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    for(int i=0;i<edges;i++){
        glVertex2i(pntX[i]+tx,pntY[i]+ty);
    }
    glEnd();
}

void drawPolygonMirrorReflection(char reflectionAxis){
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    if(reflectionAxis=='x'||reflectionAxis=='X'){
        for(int i=0;i<edges;i++){
         glVertex2i(round(pntX[i]),round(pntY[i]*-1));
        }
    }
    else if(reflectionAxis=='y' || reflectionAxis=='Y'){
        for(int i=0;i<edges;i++){
            glVertex2i(round(pntX[i]*-1),round(pntY[i]));
        }
    }
    glEnd();
}

void drawScaled(double m,double n){
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    for(int i=0;i<edges;i++){
        glVertex2i(round(pntX[i]*m),round(pntY[i]*n));
    }
    glEnd();
}

void drawrotated(int degree,int arbX,int arbY){
    float radian = 3.14 * degree / 180;

    vector<int> newX;
    vector<int> newY;

    float cx = (pntX[0] + pntX[1] + pntX[2] + pntX[3]) / 4.0;
    float cy = (pntY[0] + pntY[1] + pntY[2] + pntY[3]) / 4.0;

    for(int i = 0; i < edges; i++){
        newX.push_back(pntX[i] - cx - arbX );
        newY.push_back(pntY[i] - cy - arbY );
    }

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);

    for(int i = 0; i < edges; i++){
        float m = newX[i] * cos(radian) - newY[i] * sin(radian);
        float n = newX[i] * sin(radian) + newY[i] * cos(radian);
        glVertex2i(round(m + cx + arbX), round(n + cy +arbY));
    }

    glEnd();
}



void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);


    switch(decision){
        case 1:drawPolygon();
               drawPolygonTrans(transX,transY);
               break;
        case 2:drawPolygon();
               drawScaled(scalefactorX,scalefactorY);
               break;
        case 3:drawPolygon();
               drawrotated(theta,arbX,arbY);
               break;
        case 4:drawPolygon();
               drawPolygonMirrorReflection(reflectionAxis);
               break;
    }

    glFlush();
}

void myInit(void){
    glClearColor(1.0,1.0,1.0,0);
    glColor3f(0.0f,0.0f,0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-640.0 ,640.0, -480.0,480);
}

int main(int argc, char** argv)
{
    for(int i=0;i<edges;i++){
        cout<<"enter co-ordinate of vertex "<<i+1<<':';
        cin>>pntX1>>pntY1;
        pntX.push_back(pntX1);
        pntY.push_back(pntY1);
    }

    cout<<"1.Traslation"<<endl;
    cout<<"2.Scaling"<<endl;
    cout<<"3.Rotation"<<endl;
    cout<<"4.Reflection"<<endl;
    cout<<"enter the decision: "<<endl;
    cin>>decision;

    switch(decision){
        case 1:
             cout<<"enter the translation factor for x and y:";
             cin>>transX>>transY;
             break;
        case 2:
             cout<<"input decimal value bet 0 to 1 inorder to print it in frame"<<endl;
             cout<<"enter scale factor X: ";
             cin>>scalefactorX;
             cout<<"enter scale factor Y: ";
             cin>>scalefactorY;
             //input scale factor less than 10 inorder to print it in frame
             break;
        case 3:
             cout<<"enter Degree of rotation: "<<endl;
             cin>>theta;
             char x;
             cout<<"to rotate about arbitary points, enter arbitary co-ordinates: ";
             cin>>arbX>>arbY;

             break;
        case 4:
            cout<<"reflection about which axis(x or y): "<<endl;
            cin>>reflectionAxis;
            break;
        default:
            cout<<"invalid input"<<endl;
            break;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("extended basic Transformation: ");

    glutDisplayFunc(display);
    myInit();
    glutMainLoop();

    return 0;
}
