#define GL_SILENCE_DEPRECATION
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <GLUT/glut.h>

using namespace std;

void init(void)
{
    glClearColor(39. / 255., 40. / 255., 69. / 255, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

double cubeScale = 0.25;

double posr(double input)
{
    return abs(cos(input)) * (1.0 - cubeScale);
}

double pos = 0.0;
double rpos = cos(pos);

void display(void)
{
    rpos = posr(pos);

    cubeScale = 0.25 + rpos / 5.0;
    
    glutPositionWindow(200. + rpos * 250., 200. + rpos * 250.);

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 81.0 / 255.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.0 + rpos, 0.0 + rpos, 0.0);
    glVertex3f(cubeScale + rpos, 0.0 + rpos, 0.0);
    glVertex3f(cubeScale + rpos, cubeScale + rpos, 0.0);
    glVertex3f(0.0 + rpos, cubeScale + rpos, 0.0);
    glEnd();

    glFlush();

    pos = pos + 0.01;
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(720, 480);
    glutInitWindowPosition(250, 250);

    glutCreateWindow("thicc cube bouncer");

    init();

    glutDisplayFunc(display);
    glutIdleFunc(display);

    glutMainLoop();

    return 0;
}