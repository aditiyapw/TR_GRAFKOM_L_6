#include <windows.h>
#include <iostream>
#include <GL/glut.h>
#include <gl/glut.h>

// TOPIC - RAYO VALLECANO STADIUM

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;

void look()
{
    glLoadIdentity();
       gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
       glRotatef(xrot, 1.0f,0.0f, 0.0f);
       glRotatef(yrot, 0.0f, 1.0f, 0.0f);
}

void init(void)
{
    glClearColor(141/255.0f, 230/255.0f, 249/255.0f, 249/255.0f);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
}

void tampil(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //tanah
    //atas
    glBegin(GL_POLYGON);
    glColor3f(219/255.0f, 173/255.0f, 100/255.0f);
    glVertex3f(-80,-30,80);
    glVertex3f(-80,-30,-80);
    glVertex3f(80,-30,-80);
    glVertex3f(80,-30,80);
    glEnd();
    //bawah
    glBegin(GL_POLYGON);
    glColor3f(137/255.0f, 107/255.0f, 60/255.0f);
    glVertex3f(-80,-35,80);
    glVertex3f(-80,-35,-80);
    glVertex3f(80,-35,-80);
    glVertex3f(80,-35,80);
    glEnd();
    //kiri
    glBegin(GL_POLYGON);
    glColor3f(117/255.0f, 91/255.0f, 51/255.0f);
    glVertex3f(-80,-35,80);
    glVertex3f(-80,-30,80);
    glVertex3f(-80,-30,-80);
    glVertex3f(-80,-35,-80);
    glEnd();
    //kanan
    glBegin(GL_POLYGON);
    glColor3f(202/255.0f, 159/255.0f, 90/255.0f);
    glVertex3f(80,-35,80);
    glVertex3f(80,-30,80);
    glVertex3f(80,-30,-80);
    glVertex3f(80,-35,-80);
    glEnd();
    //belakang
    glBegin(GL_POLYGON);
    glColor3f(107/255.0f, 84/255.0f, 48/255.0f);
    glVertex3f(-80,-35,-80);
    glVertex3f(-80,-30,-80);
    glVertex3f(80,-30,-80);
    glVertex3f(80,-35,-80);
    glEnd();
    //depan
    glBegin(GL_POLYGON);
    glColor3f(186/255.0f, 147/255.0f, 83/255.0f);
    glVertex3f(-80,-35,80);
    glVertex3f(-80,-30,80);
    glVertex3f(80,-30,80);
    glVertex3f(80,-35,80);
    glEnd();

    //RUMPUT
    glBegin(GL_POLYGON);
    glColor3f(119/255.0f, 158/255.0f, 41/255.0f);
    glVertex3f(-60,-29.9,40);
    glVertex3f(-60,-29.9,-40);
    glVertex3f(-50,-29.9,-40);
    glVertex3f(-50,-29.9,40);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(135/255.0f, 170/255.0f, 86/255.0f);
    glVertex3f(-50,-29.9,40);
    glVertex3f(-50,-29.9,-40);
    glVertex3f(-40,-29.9,-40);
    glVertex3f(-40,-29.9,40);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(119/255.0f, 158/255.0f, 41/255.0f);
    glVertex3f(-40,-29.9,40);
    glVertex3f(-40,-29.9,-40);
    glVertex3f(-30,-29.9,-40);
    glVertex3f(-30,-29.9,40);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(135/255.0f, 170/255.0f, 86/255.0f);
    glVertex3f(-30,-29.9,40);
    glVertex3f(-30,-29.9,-40);
    glVertex3f(-20,-29.9,-40);
    glVertex3f(-20,-29.9,40);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(119/255.0f, 158/255.0f, 41/255.0f);
    glVertex3f(-20,-29.9,40);
    glVertex3f(-20,-29.9,-40);
    glVertex3f(-10,-29.9,-40);
    glVertex3f(-10,-29.9,40);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(135/255.0f, 170/255.0f, 86/255.0f);
    glVertex3f(-10,-29.9,40);
    glVertex3f(-10,-29.9,-40);
    glVertex3f(0,-29.9,-40);
    glVertex3f(0,-29.9,40);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(119/255.0f, 158/255.0f, 41/255.0f);
    glVertex3f(0,-29.9,40);
    glVertex3f(0,-29.9,-40);
    glVertex3f(10,-29.9,-40);
    glVertex3f(10,-29.9,40);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(135/255.0f, 170/255.0f, 86/255.0f);
    glVertex3f(10,-29.9,40);
    glVertex3f(10,-29.9,-40);
    glVertex3f(20,-29.9,-40);
    glVertex3f(20,-29.9,40);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(119/255.0f, 158/255.0f, 41/255.0f);
    glVertex3f(20,-29.9,40);
    glVertex3f(20,-29.9,-40);
    glVertex3f(30,-29.9,-40);
    glVertex3f(30,-29.9,40);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(135/255.0f, 170/255.0f, 86/255.0f);
    glVertex3f(30,-29.9,40);
    glVertex3f(30,-29.9,-40);
    glVertex3f(40,-29.9,-40);
    glVertex3f(40,-29.9,40);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(119/255.0f, 158/255.0f, 41/255.0f);
    glVertex3f(40,-29.9,40);
    glVertex3f(40,-29.9,-40);
    glVertex3f(50,-29.9,-40);
    glVertex3f(50,-29.9,40);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(135/255.0f, 170/255.0f, 86/255.0f);
    glVertex3f(50,-29.9,40);
    glVertex3f(50,-29.9,-40);
    glVertex3f(60,-29.9,-40);
    glVertex3f(60,-29.9,40);
    glEnd();

    //Papan Iklan
    //belakang
    glBegin(GL_POLYGON);
    glColor3f(251/255.0f, 76/255.0f, 76/255.0f);
    glVertex3f(-50,-29.9,-38);
    glVertex3f(-50,-27,-38);
    glVertex3f(50,-27,-38);
    glVertex3f(50,-29.9,-38);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(252/255.0f, 49/255.0f, 49/255.0f);
    glVertex3f(-50,-29.9,-38.3);
    glVertex3f(-50,-27,-38.3);
    glVertex3f(50,-27,-38.3);
    glVertex3f(50,-29.9,-38.3);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(251/255.0f, 81/255.0f, 81/255.0f);
    glVertex3f(-50,-27,-38);
    glVertex3f(-50,-27,-38.3);
    glVertex3f(50,-27,-38.3);
    glVertex3f(50,-27,-38);
    glEnd();
    //kanan belakang
    glBegin(GL_POLYGON);
    glColor3f(237/255.0f, 237/255.0f, 237/255.0f);
    glVertex3f(50,-29.9,-38.3);
    glVertex3f(50,-27,-38.3);
    glVertex3f(58.3,-27,-32.3);
    glVertex3f(58.3,-29.9,-32.3);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(50,-29.9,-38);
    glVertex3f(50,-27,-38);
    glVertex3f(58,-27,-32);
    glVertex3f(58,-29.9,-32);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(227/255.0f, 227/255.0f, 227/255.0f);
    glVertex3f(50,-27,-38);
    glVertex3f(50,-27,-38.3);
    glVertex3f(58,-27,-32.3);
    glVertex3f(58,-27,-32);
    glEnd();
    //kiri belakang
    glBegin(GL_POLYGON);
    glColor3f(237/255.0f, 237/255.0f, 237/255.0f);
    glVertex3f(-50,-29.9,-38.3);
    glVertex3f(-50,-27,-38.3);
    glVertex3f(-58.3,-27,-32.3);
    glVertex3f(-58.3,-29.9,-32.3);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-50,-29.9,-38);
    glVertex3f(-50,-27,-38);
    glVertex3f(-58,-27,-32);
    glVertex3f(-58,-29.9,-32);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(227/255.0f, 227/255.0f, 227/255.0f);
    glVertex3f(-50,-27,-38);
    glVertex3f(-50,-27,-38.3);
    glVertex3f(-58,-27,-32.3);
    glVertex3f(-58,-27,-32);
    glEnd();

    //kiri
    glBegin(GL_POLYGON);
    glColor3f(252/255.0f, 49/255.0f, 49/255.0f);
    glVertex3f(-58.3,-29.9,-32.3);
    glVertex3f(-58.3,-27,-32.3);
    glVertex3f(-58.3,-27,32.3);
    glVertex3f(-58.3,-29.9,32.3);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(251/255.0f, 76/255.0f, 76/255.0f);
    glVertex3f(-58,-29.9,-32.3);
    glVertex3f(-58,-27,-32.3);
    glVertex3f(-58,-27,32.3);
    glVertex3f(-58,-29.9,32.3);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(251/255.0f, 81/255.0f, 81/255.0f);
    glVertex3f(-58.3,-27,-32.3);
    glVertex3f(-58,-27,-32.3);
    glVertex3f(-58,-27,32.3);
    glVertex3f(-58.3,-27,32.3);
    glEnd();
    //kanan
    glBegin(GL_POLYGON);
    glColor3f(252/255.0f, 49/255.0f, 49/255.0f);
    glVertex3f(58.3,-29.9,-32.3);
    glVertex3f(58.3,-27,-32.3);
    glVertex3f(58.3,-27,32.3);
    glVertex3f(58.3,-29.9,32.3);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(251/255.0f, 76/255.0f, 76/255.0f);
    glVertex3f(58,-29.9,-32.3);
    glVertex3f(58,-27,-32.3);
    glVertex3f(58,-27,32.3);
    glVertex3f(58,-29.9,32.3);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(251/255.0f, 81/255.0f, 81/255.0f);
    glVertex3f(58.3,-27,-32.3);
    glVertex3f(58,-27,-32.3);
    glVertex3f(58,-27,32.3);
    glVertex3f(58.3,-27,32.3);
    glEnd();


    //kanan depan
    glBegin(GL_POLYGON);
    glColor3f(237/255.0f, 237/255.0f, 237/255.0f);
    glVertex3f(50,-29.9,38.3);
    glVertex3f(50,-27,38.3);
    glVertex3f(58.3,-27,32.3);
    glVertex3f(58.3,-29.9,32.3);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(50,-29.9,38);
    glVertex3f(50,-27,38);
    glVertex3f(58,-27,32);
    glVertex3f(58,-29.9,32);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(227/255.0f, 227/255.0f, 227/255.0f);
    glVertex3f(50,-27,38);
    glVertex3f(50,-27,38.3);
    glVertex3f(58,-27,32.6);
    glVertex3f(58,-27,32);
    glEnd();
    //kiri depan
    glBegin(GL_POLYGON);
    glColor3f(237/255.0f, 237/255.0f, 237/255.0f);
    glVertex3f(-50,-29.9,38.3);
    glVertex3f(-50,-27,38.3);
    glVertex3f(-58.3,-27,32.3);
    glVertex3f(-58.3,-29.9,32.3);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-50,-29.9,38);
    glVertex3f(-50,-27,38);
    glVertex3f(-58,-27,32);
    glVertex3f(-58,-29.9,32);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(227/255.0f, 227/255.0f, 227/255.0f);
    glVertex3f(-50,-27,38);
    glVertex3f(-50,-27,38.3);
    glVertex3f(-58,-27,32.6);
    glVertex3f(-58,-27,32);
    glEnd();


    //GARIS RUMPUT
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(-50,-29.8,30);
    glVertex3f(-50,-29.8,-30);
    glVertex3f(50,-29.8,-30);
    glVertex3f(50,-29.8,30);
    glVertex3f(-50,-29.8,-30);
    glVertex3f(50,-29.8,-30);
    glVertex3f(-50,-29.8,30);
    glVertex3f(50,-29.8,30);

    glVertex3f(0,-29.8,30);
    glVertex3f(0,-29.8,-30);

    glVertex3f(-50,-29.8,20);
    glVertex3f(-35,-29.8,20);
    glVertex3f(-50,-29.8,-20);
    glVertex3f(-35,-29.8,-20);
    glVertex3f(-35,-29.8,20);
    glVertex3f(-35,-29.8,-20);
    glVertex3f(50,-29.8,20);
    glVertex3f(35,-29.8,20);
    glVertex3f(50,-29.8,-20);
    glVertex3f(35,-29.8,-20);
    glVertex3f(35,-29.8,-20);
    glVertex3f(35,-29.8,20);

    glVertex3f(-50,-29.8,10);
    glVertex3f(-44,-29.8,10);
    glVertex3f(-50,-29.8,-10);
    glVertex3f(-44,-29.8,-10);
    glVertex3f(-44,-29.8,-10);
    glVertex3f(-44,-29.8,10);
    glVertex3f(50,-29.8,10);
    glVertex3f(44,-29.8,10);
    glVertex3f(50,-29.8,-10);
    glVertex3f(44,-29.8,-10);
    glVertex3f(44,-29.8,-10);
    glVertex3f(44,-29.8,10);
    glEnd();


    //Bendera Corner
    //kiri depan
    glBegin(GL_POLYGON);
    glColor3f(245/255.0f, 211/255.0f, 23/255.0f);
    glVertex3f(-50,-30,30);
    glVertex3f(-49.8,-30,30);
    glVertex3f(-49.8,-25,30);
    glVertex3f(-50,-25,30);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(202/255.0f, 174/255.0f, 20/255.0f);
    glVertex3f(-50,-30,29.8);
    glVertex3f(-49.8,-30,29.8);
    glVertex3f(-49.8,-25,29.8);
    glVertex3f(-50,-25,29.8);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(227/255.0f, 196/255.0f, 22/255.0f);
    glVertex3f(-49.8,-30,29.8);
    glVertex3f(-49.8,-30,30);
    glVertex3f(-49.8,-25,30);
    glVertex3f(-49.8,-25,29.8);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(203/255.0f, 175/255.0f, 20/255.0f);
    glVertex3f(-50,-30,29.8);
    glVertex3f(-50,-30,30);
    glVertex3f(-50,-25,30);
    glVertex3f(-50,-25,29.8);
    glEnd();
    //kiri belakang
    glBegin(GL_POLYGON);
    glColor3f(245/255.0f, 211/255.0f, 23/255.0f);
    glVertex3f(-50,-30,-30);
    glVertex3f(-49.8,-30,-30);
    glVertex3f(-49.8,-25,-30);
    glVertex3f(-50,-25,-30);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(202/255.0f, 174/255.0f, 20/255.0f);
    glVertex3f(-50,-30,-29.8);
    glVertex3f(-49.8,-30,-29.8);
    glVertex3f(-49.8,-25,-29.8);
    glVertex3f(-50,-25,-29.8);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(227/255.0f, 196/255.0f, 22/255.0f);
    glVertex3f(-49.8,-30,-29.8);
    glVertex3f(-49.8,-30,-30);
    glVertex3f(-49.8,-25,-30);
    glVertex3f(-49.8,-25,-29.8);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(203/255.0f, 175/255.0f, 20/255.0f);
    glVertex3f(-50,-30,-29.8);
    glVertex3f(-50,-30,-30);
    glVertex3f(-50,-25,-30);
    glVertex3f(-50,-25,-29.8);
    glEnd();
    //kanan depan
    glBegin(GL_POLYGON);
    glColor3f(245/255.0f, 211/255.0f, 23/255.0f);
    glVertex3f(50,-30,30);
    glVertex3f(49.8,-30,30);
    glVertex3f(49.8,-25,30);
    glVertex3f(50,-25,30);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(202/255.0f, 174/255.0f, 20/255.0f);
    glVertex3f(50,-30,29.8);
    glVertex3f(49.8,-30,29.8);
    glVertex3f(49.8,-25,29.8);
    glVertex3f(50,-25,29.8);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(227/255.0f, 196/255.0f, 22/255.0f);
    glVertex3f(49.8,-30,29.8);
    glVertex3f(49.8,-30,30);
    glVertex3f(49.8,-25,30);
    glVertex3f(49.8,-25,29.8);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(203/255.0f, 175/255.0f, 20/255.0f);
    glVertex3f(50,-30,29.8);
    glVertex3f(50,-30,30);
    glVertex3f(50,-25,30);
    glVertex3f(50,-25,29.8);
    glEnd();
    //kanan belakang
    glBegin(GL_POLYGON);
    glColor3f(245/255.0f, 211/255.0f, 23/255.0f);
    glVertex3f(50,-30,-30);
    glVertex3f(49.8,-30,-30);
    glVertex3f(49.8,-25,-30);
    glVertex3f(50,-25,-30);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(202/255.0f, 174/255.0f, 20/255.0f);
    glVertex3f(50,-30,-29.8);
    glVertex3f(49.8,-30,-29.8);
    glVertex3f(49.8,-25,-29.8);
    glVertex3f(50,-25,-29.8);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(227/255.0f, 196/255.0f, 22/255.0f);
    glVertex3f(49.8,-30,-29.8);
    glVertex3f(49.8,-30,-30);
    glVertex3f(49.8,-25,-30);
    glVertex3f(49.8,-25,-29.8);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(203/255.0f, 175/255.0f, 20/255.0f);
    glVertex3f(50,-30,-29.8);
    glVertex3f(50,-30,-30);
    glVertex3f(50,-25,-30);
    glVertex3f(50,-25,-29.8);
    glEnd();

    //GAWANG
    //kiri
    glBegin(GL_POLYGON);
    glColor3f(245/255.0f, 211/255.0f, 23/255.0f);
    glVertex3f(-49.8,-30,6);
    glVertex3f(-50.2,-30,6);
    glVertex3f(-50.2,-23,6);
    glVertex3f(-49.8,-23,6);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(202/255.0f, 174/255.0f, 20/255.0f);
    glVertex3f(-49.8,-30,5.5);
    glVertex3f(-50.2,-30,5.5);
    glVertex3f(-50.2,-23,5.5);
    glVertex3f(-49.8,-23,5.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(227/255.0f, 196/255.0f, 22/255.0f);
    glVertex3f(-50.2,-30,5.5);
    glVertex3f(-50.2,-30,6);
    glVertex3f(-50.2,-23,6);
    glVertex3f(-50.2,-23,5.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(203/255.0f, 175/255.0f, 20/255.0f);
    glVertex3f(-49.8,-30,5.5);
    glVertex3f(-49.8,-30,6);
    glVertex3f(-49.8,-23,6);
    glVertex3f(-49.8,-23,5.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(245/255.0f, 211/255.0f, 23/255.0f);
    glVertex3f(-49.8,-30,-6);
    glVertex3f(-50.2,-30,-6);
    glVertex3f(-50.2,-23,-6);
    glVertex3f(-49.8,-23,-6);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(202/255.0f, 174/255.0f, 20/255.0f);
    glVertex3f(-49.8,-30,-5.5);
    glVertex3f(-50.2,-30,-5.5);
    glVertex3f(-50.2,-23,-5.5);
    glVertex3f(-49.8,-23,-5.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(227/255.0f, 196/255.0f, 22/255.0f);
    glVertex3f(-50.2,-30,-5.5);
    glVertex3f(-50.2,-30,-6);
    glVertex3f(-50.2,-23,-6);
    glVertex3f(-50.2,-23,-5.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(203/255.0f, 175/255.0f, 20/255.0f);
    glVertex3f(-49.8,-30,-5.5);
    glVertex3f(-49.8,-30,-6);
    glVertex3f(-49.8,-23,-6);
    glVertex3f(-49.8,-23,-5.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(245/255.0f, 211/255.0f, 23/255.0f);
    glVertex3f(-49.8,-23,6);
    glVertex3f(-50.2,-23,6);
    glVertex3f(-50.2,-23,-6);
    glVertex3f(-49.8,-23,-6);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(245/255.0f, 211/255.0f, 23/255.0f);
    glVertex3f(-49.8,-23.5,6);
    glVertex3f(-50.2,-23.5,6);
    glVertex3f(-50.2,-23.5,-6);
    glVertex3f(-49.8,-23.5,-6);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(245/255.0f, 211/255.0f, 23/255.0f);
    glVertex3f(-49.8,-23,6);
    glVertex3f(-49.8,-23.5,6);
    glVertex3f(-49.8,-23.5,-6);
    glVertex3f(-49.8,-23,-6);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(245/255.0f, 211/255.0f, 23/255.0f);
    glVertex3f(-50.2,-23,6);
    glVertex3f(-50.2,-23.5,6);
    glVertex3f(-50.2,-23.5,-6);
    glVertex3f(-50.2,-23,-6);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(245/255.0f, 211/255.0f, 23/255.0f);
    glVertex3f(49.8,-30,6);
    glVertex3f(50.2,-30,6);
    glVertex3f(50.2,-23,6);
    glVertex3f(49.8,-23,6);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(202/255.0f, 174/255.0f, 20/255.0f);
    glVertex3f(49.8,-30,5.5);
    glVertex3f(50.2,-30,5.5);
    glVertex3f(50.2,-23,5.5);
    glVertex3f(49.8,-23,5.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(227/255.0f, 196/255.0f, 22/255.0f);
    glVertex3f(50.2,-30,5.5);
    glVertex3f(50.2,-30,6);
    glVertex3f(50.2,-23,6);
    glVertex3f(50.2,-23,5.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(203/255.0f, 175/255.0f, 20/255.0f);
    glVertex3f(49.8,-30,5.5);
    glVertex3f(49.8,-30,6);
    glVertex3f(49.8,-23,6);
    glVertex3f(49.8,-23,5.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(245/255.0f, 211/255.0f, 23/255.0f);
    glVertex3f(49.8,-30,-6);
    glVertex3f(50.2,-30,-6);
    glVertex3f(50.2,-23,-6);
    glVertex3f(49.8,-23,-6);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(202/255.0f, 174/255.0f, 20/255.0f);
    glVertex3f(49.8,-30,-5.5);
    glVertex3f(50.2,-30,-5.5);
    glVertex3f(50.2,-23,-5.5);
    glVertex3f(49.8,-23,-5.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(227/255.0f, 196/255.0f, 22/255.0f);
    glVertex3f(50.2,-30,-5.5);
    glVertex3f(50.2,-30,-6);
    glVertex3f(50.2,-23,-6);
    glVertex3f(50.2,-23,-5.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(203/255.0f, 175/255.0f, 20/255.0f);
    glVertex3f(49.8,-30,-5.5);
    glVertex3f(49.8,-30,-6);
    glVertex3f(49.8,-23,-6);
    glVertex3f(49.8,-23,-5.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(245/255.0f, 211/255.0f, 23/255.0f);
    glVertex3f(49.8,-23,6);
    glVertex3f(50.2,-23,6);
    glVertex3f(50.2,-23,-6);
    glVertex3f(49.8,-23,-6);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(245/255.0f, 211/255.0f, 23/255.0f);
    glVertex3f(49.8,-23.5,6);
    glVertex3f(50.2,-23.5,6);
    glVertex3f(50.2,-23.5,-6);
    glVertex3f(49.8,-23.5,-6);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(245/255.0f, 211/255.0f, 23/255.0f);
    glVertex3f(49.8,-23,6);
    glVertex3f(49.8,-23.5,6);
    glVertex3f(49.8,-23.5,-6);
    glVertex3f(49.8,-23,-6);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(245/255.0f, 211/255.0f, 23/255.0f);
    glVertex3f(50.2,-23,6);
    glVertex3f(50.2,-23.5,6);
    glVertex3f(50.2,-23.5,-6);
    glVertex3f(50.2,-23,-6);
    glEnd();

    //tribun belakang

    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-60,-30,40);
    glVertex3f(60,-30,40);
    glVertex3f(60,-28,40);
    glVertex3f(-60,-28,40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);//terang
    glVertex3f(-60,-28,40);
    glVertex3f(60,-28,40);
    glVertex3f(60,-28,42);
    glVertex3f(-60,-28,42);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-60,-28,42);
    glVertex3f(60,-28,42);
    glVertex3f(60,-25,42);
    glVertex3f(-60,-25,42);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);//terang
    glVertex3f(-60,-25,42);
    glVertex3f(60,-25,42);
    glVertex3f(60,-25,44);
    glVertex3f(-60,-25,44);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-60,-25,44);
    glVertex3f(60,-25,44);
    glVertex3f(60,-23,44);
    glVertex3f(-60,-23,44);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);//terang
    glVertex3f(-60,-23,44);
    glVertex3f(60,-23,44);
    glVertex3f(60,-23,46);
    glVertex3f(-60,-23,46);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-60,-23,46);
    glVertex3f(60,-23,46);
    glVertex3f(60,-21,46);
    glVertex3f(-60,-21,46);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);//terang
    glVertex3f(-60,-21,46);
    glVertex3f(60,-21,46);
    glVertex3f(60,-21,48);
    glVertex3f(-60,-21,48);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-60,-21,48);
    glVertex3f(60,-21,48);
    glVertex3f(60,-19,48);
    glVertex3f(-60,-19,48);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);//terang
    glVertex3f(-60,-19,48);
    glVertex3f(60,-19,48);
    glVertex3f(60,-19,50);
    glVertex3f(-60,-19,50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-60,-19,50);
    glVertex3f(60,-19,50);
    glVertex3f(60,-17,50);
    glVertex3f(-60,-17,50);
    glEnd();

    //pemisah atas bawah
    //bawah
    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);//terang
    glVertex3f(-60,-17,55);
    glVertex3f(60,-17,55);
    glVertex3f(60,-17,47);
    glVertex3f(-60,-17,47);
    glEnd();
    //atas
    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);//terang
    glVertex3f(-60,-15,50);
    glVertex3f(60,-15,50);
    glVertex3f(60,-15,47);
    glVertex3f(-60,-15,47);
    glEnd();
    //depan
    glBegin(GL_POLYGON);
    glColor3f(252/255.0f, 49/255.0f, 49/255.0f);
    glVertex3f(-60,-17,47);
    glVertex3f(60,-17,47);
    glVertex3f(60,-15,47);
    glVertex3f(-60,-15,47);
    glEnd();
    //samping
    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);//terang
    glVertex3f(-60,-17,47);
    glVertex3f(-60,-15,47);
    glVertex3f(-60,-15,55);
    glVertex3f(-60,-17,55);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);//terang
    glVertex3f(60,-17,47);
    glVertex3f(60,-15,47);
    glVertex3f(60,-15,55);
    glVertex3f(60,-17,55);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-60,-17,47);
    glVertex3f(60,-17,47);
    glVertex3f(60,-15,47);
    glVertex3f(-60,-15,47);
    glEnd();

	//
	glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-60,-17,50);
    glVertex3f(60,-17,50);
    glVertex3f(60,-15,50);
    glVertex3f(-60,-15,50);
    glEnd();

	//tribun depan atas

    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-60,-17,53);
    glVertex3f(60,-17,53);
    glVertex3f(60,-15,53);
    glVertex3f(-60,-15,53);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);//terang
    glVertex3f(-60,-15,53);
    glVertex3f(60,-15,53);
    glVertex3f(60,-15,55);
    glVertex3f(-60,-15,55);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-60,-15,55);
    glVertex3f(60,-15,55);
    glVertex3f(60,-13,55);
    glVertex3f(-60,-13,55);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);//terang
    glVertex3f(-60,-13,55);
    glVertex3f(60,-13,55);
    glVertex3f(60,-13,57);
    glVertex3f(-60,-13,57);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-60,-13,57);
    glVertex3f(60,-13,57);
    glVertex3f(60,-11,57);
    glVertex3f(-60,-11,57);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);//terang
    glVertex3f(-60,-11,57);
    glVertex3f(60,-11,57);
    glVertex3f(60,-11,59);
    glVertex3f(-60,-11,59);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-60,-11,59);
    glVertex3f(60,-11,59);
    glVertex3f(60,-9,59);
    glVertex3f(-60,-9,59);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);//terang
    glVertex3f(-60,-9,59);
    glVertex3f(60,-9,59);
    glVertex3f(60,-9,61);
    glVertex3f(-60,-9,61);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-60,-9,61);
    glVertex3f(60,-9,61);
    glVertex3f(60,-7,61);
    glVertex3f(-60,-7,61);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);//terang
    glVertex3f(-60,-7,61);
    glVertex3f(60,-7,61);
    glVertex3f(60,-7,63);
    glVertex3f(-60,-7,63);
    glEnd();

    //tribun depan

    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(60,-30,-40);
    glVertex3f(-60,-30,-40);
    glVertex3f(-60,-28,-40);
    glVertex3f(60,-28,-40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);//terang
    glVertex3f(60,-28,-40);
    glVertex3f(-60,-28,-40);
    glVertex3f(-60,-28,-42);
    glVertex3f(60,-28,-42);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(60,-28,-42);
    glVertex3f(-60,-28,-42);
    glVertex3f(-60,-25,-42);
    glVertex3f(60,-25,-42);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);//terang
    glVertex3f(60,-25,-42);
    glVertex3f(-60,-25,-42);
    glVertex3f(-60,-25,-44);
    glVertex3f(60,-25,-44);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(60,-25,-44);
    glVertex3f(-60,-25,-44);
    glVertex3f(-60,-23,-44);
    glVertex3f(60,-23,-44);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);//terang
    glVertex3f(60,-23,-44);
    glVertex3f(-60,-23,-44);
    glVertex3f(-60,-23,-46);
    glVertex3f(60,-23,-46);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(60,-23,-46);
    glVertex3f(-60,-23,-46);
    glVertex3f(-60,-21,-46);
    glVertex3f(60,-21,-46);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);//terang
    glVertex3f(60,-21,-46);
    glVertex3f(-60,-21,-46);
    glVertex3f(-60,-21,-48);
    glVertex3f(60,-21,-48);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(60,-21,-48);
    glVertex3f(-60,-21,-48);
    glVertex3f(-60,-19,-48);
    glVertex3f(60,-19,-48);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);//terang
    glVertex3f(60,-19,-48);
    glVertex3f(-60,-19,-48);
    glVertex3f(-60,-19,-50);
    glVertex3f(60,-19,-50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(60,-19,-50);
    glVertex3f(-60,-19,-50);
    glVertex3f(-60,-17,-50);
    glVertex3f(60,-17,-50);
    glEnd();

    //pemisah atas bawah
    //bawah
    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);//terang
    glVertex3f(60,-17,-55);
    glVertex3f(-60,-17,-55);
    glVertex3f(-60,-17,-47);
    glVertex3f(60,-17,-47);
    glEnd();
    //atas
    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);//terang
    glVertex3f(60,-15,-50);
    glVertex3f(-50,-15,-50);
    glVertex3f(-50,-15,-47);
    glVertex3f(60,-15,-47);
    glEnd();
    //depan
    glBegin(GL_POLYGON);
    glColor3f(252/255.0f, 49/255.0f, 49/255.0f);
    glVertex3f(60,-17,-47);
    glVertex3f(-60,-17,-47);
    glVertex3f(-60,-15,-47);
    glVertex3f(60,-15,-47);
    glEnd();
    //samping
    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);//terang
    glVertex3f(60,-17,-47);
    glVertex3f(60,-15,-47);
    glVertex3f(60,-15,-55);
    glVertex3f(60,-17,-55);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);//terang
    glVertex3f(-60,-17,-47);
    glVertex3f(-60,-15,-47);
    glVertex3f(-60,-15,-55);
    glVertex3f(-60,-17,-55);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(60,-17,-47);
    glVertex3f(-60,-17,-47);
    glVertex3f(-60,-15,-47);
    glVertex3f(60,-15,-47);
    glEnd();

	//
	glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(60,-17,-50);
    glVertex3f(-60,-17,-50);
    glVertex3f(-60,-15,-50);
    glVertex3f(60,-15,-50);
    glEnd();

	//tribun depan atas

    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(60,-17,-53);
    glVertex3f(-60,-17,-53);
    glVertex3f(-60,-15,-53);
    glVertex3f(60,-15,-53);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);//terang
    glVertex3f(60,-15,-53);
    glVertex3f(-60,-15,-53);
    glVertex3f(-60,-15,-55);
    glVertex3f(60,-15,-55);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(60,-15,-55);
    glVertex3f(-60,-15,-55);
    glVertex3f(-60,-13,-55);
    glVertex3f(60,-13,-55);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);//terang
    glVertex3f(60,-13,-55);
    glVertex3f(-60,-13,-55);
    glVertex3f(-60,-13,-57);
    glVertex3f(60,-13,-57);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(60,-13,-57);
    glVertex3f(-60,-13,-57);
    glVertex3f(-60,-11,-57);
    glVertex3f(60,-11,-57);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);//terang
    glVertex3f(60,-11,-57);
    glVertex3f(-60,-11,-57);
    glVertex3f(-60,-11,-59);
    glVertex3f(60,-11,-59);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(60,-11,-59);
    glVertex3f(-60,-11,-59);
    glVertex3f(-60,-9,-59);
    glVertex3f(60,-9,-59);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);//terang
    glVertex3f(60,-9,-59);
    glVertex3f(-60,-9,-59);
    glVertex3f(-60,-9,-61);
    glVertex3f(60,-9,-61);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(60,-9,-61);
    glVertex3f(-60,-9,-61);
    glVertex3f(-60,-7,-61);
    glVertex3f(60,-7,-61);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);//terang
    glVertex3f(60,-7,-61);
    glVertex3f(-60,-7,-61);
    glVertex3f(-60,-7,-63);
    glVertex3f(60,-7,-63);
    glEnd();

    //tribun kiri
    //1
    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);
    glVertex3f(-60,-29.8,35);
    glVertex3f(-62,-29.8,35);
    glVertex3f(-62,-29.8,18);
    glVertex3f(-60,-29.8,18);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);
    glVertex3f(-60,-29.8,11);
    glVertex3f(-62,-29.8,11);
    glVertex3f(-62,-29.8,-13);
    glVertex3f(-60,-29.8,-13);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);
    glVertex3f(-60,-29.8,-20);
    glVertex3f(-62,-29.8,-20);
    glVertex3f(-62,-29.8,-35);
    glVertex3f(-60,-29.8,-35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(240/255.0f, 228/255.0f, 37/255.0f);
    glVertex3f(-60,-29.8,-18);
    glVertex3f(-62,-29.8,-18);
    glVertex3f(-62,-29.8,-20);
    glVertex3f(-60,-29.8,-20);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(240/255.0f, 228/255.0f, 37/255.0f);
    glVertex3f(-60,-29.8,13);
    glVertex3f(-62,-29.8,13);
    glVertex3f(-62,-29.8,11);
    glVertex3f(-60,-29.8,11);
    glEnd();

    //2
    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);
    glVertex3f(-62,-27.8,35);
    glVertex3f(-64,-27.8,35);
    glVertex3f(-64,-27.8,18);
    glVertex3f(-62,-27.8,18);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);
    glVertex3f(-62,-27.8,11);
    glVertex3f(-64,-27.8,11);
    glVertex3f(-64,-27.8,-13);
    glVertex3f(-62,-27.8,-13);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);
    glVertex3f(-62,-27.8,-20);
    glVertex3f(-64,-27.8,-20);
    glVertex3f(-64,-27.8,-35);
    glVertex3f(-62,-27.8,-35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(240/255.0f, 228/255.0f, 37/255.0f);
    glVertex3f(-62,-27.8,-18);
    glVertex3f(-64,-27.8,-18);
    glVertex3f(-64,-27.8,-20);
    glVertex3f(-62,-27.8,-20);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(240/255.0f, 228/255.0f, 37/255.0f);
    glVertex3f(-62,-27.8,13);
    glVertex3f(-64,-27.8,13);
    glVertex3f(-64,-27.8,11);
    glVertex3f(-62,-27.8,11);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(183/255.0f, 183/255.0f, 183/255.0f);
    glVertex3f(-62,-29.8,35);
    glVertex3f(-62,-27.8,35);
    glVertex3f(-62,-27.8,18);
    glVertex3f(-62,-29.8,18);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(183/255.0f, 183/255.0f, 183/255.0f);
    glVertex3f(-62,-29.8,13);
    glVertex3f(-62,-27.8,13);
    glVertex3f(-62,-27.8,-13);
    glVertex3f(-62,-29.8,-13);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(183/255.0f, 183/255.0f, 183/255.0f);
    glVertex3f(-62,-29.8,-18);
    glVertex3f(-62,-27.8,-18);
    glVertex3f(-62,-27.8,-35);
    glVertex3f(-62,-29.8,-35);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(186/255.0f, 180/255.0f, 15/255.0f);
    glVertex3f(-61.9,-29.8,13);
    glVertex3f(-61.9,-27.8,13);
    glVertex3f(-61.9,-27.8,11);
    glVertex3f(-61.9,-29.8,11);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(186/255.0f, 180/255.0f, 15/255.0f);
    glVertex3f(-61.9,-29.8,-18);
    glVertex3f(-61.9,-27.8,-18);
    glVertex3f(-61.9,-27.8,-20);
    glVertex3f(-61.9,-29.8,-20);
    glEnd();

    //3
    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);
    glVertex3f(-64,-25.8,35);
    glVertex3f(-66,-25.8,35);
    glVertex3f(-66,-25.8,18);
    glVertex3f(-64,-25.8,18);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);
    glVertex3f(-64,-25.8,13);
    glVertex3f(-66,-25.8,13);
    glVertex3f(-66,-25.8,-13);
    glVertex3f(-64,-25.8,-13);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);
    glVertex3f(-64,-25.8,-18);
    glVertex3f(-66,-25.8,-18);
    glVertex3f(-66,-25.8,-35);
    glVertex3f(-64,-25.8,-35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(240/255.0f, 228/255.0f, 37/255.0f);
    glVertex3f(-64,-25.7,-18);
    glVertex3f(-66,-25.7,-18);
    glVertex3f(-66,-25.7,-20);
    glVertex3f(-64,-25.7,-20);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(240/255.0f, 228/255.0f, 37/255.0f);
    glVertex3f(-64,-25.7,13);
    glVertex3f(-66,-25.7,13);
    glVertex3f(-66,-25.7,11);
    glVertex3f(-64,-25.7,11);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(183/255.0f, 183/255.0f, 183/255.0f);
    glVertex3f(-64,-27.8,35);
    glVertex3f(-64,-25.8,35);
    glVertex3f(-64,-25.8,18);
    glVertex3f(-64,-27.8,18);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(183/255.0f, 183/255.0f, 183/255.0f);
    glVertex3f(-64,-27.8,13);
    glVertex3f(-64,-25.8,13);
    glVertex3f(-64,-25.8,-13);
    glVertex3f(-64,-27.8,-13);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(183/255.0f, 183/255.0f, 183/255.0f);
    glVertex3f(-64,-27.8,-18);
    glVertex3f(-64,-25.8,-18);
    glVertex3f(-64,-25.8,-35);
    glVertex3f(-64,-27.8,-35);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(186/255.0f, 180/255.0f, 15/255.0f);
    glVertex3f(-63.9,-27.8,13);
    glVertex3f(-63.9,-25.8,13);
    glVertex3f(-63.9,-25.8,11);
    glVertex3f(-63.9,-27.8,11);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(186/255.0f, 180/255.0f, 15/255.0f);
    glVertex3f(-63.9,-27.8,-18);
    glVertex3f(-63.9,-25.8,-18);
    glVertex3f(-63.9,-25.8,-20);
    glVertex3f(-63.9,-27.8,-20);
    glEnd();

    //4
    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);
    glVertex3f(-66,-23.8,35);
    glVertex3f(-68,-23.8,35);
    glVertex3f(-68,-23.8,-35);
    glVertex3f(-66,-23.8,-35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(240/255.0f, 228/255.0f, 37/255.0f);
    glVertex3f(-66,-23.7,-18);
    glVertex3f(-68,-23.7,-18);
    glVertex3f(-68,-23.7,-20);
    glVertex3f(-66,-23.7,-20);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(240/255.0f, 228/255.0f, 37/255.0f);
    glVertex3f(-66,-23.7,13);
    glVertex3f(-68,-23.7,13);
    glVertex3f(-68,-23.7,11);
    glVertex3f(-66,-23.7,11);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);
    glVertex3f(-66,-25.8,35);
    glVertex3f(-76,-25.8,35);
    glVertex3f(-76,-25.8,-35);
    glVertex3f(-66,-25.8,-35);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(183/255.0f, 183/255.0f, 183/255.0f);
    glVertex3f(-66,-25.8,35);
    glVertex3f(-66,-23.8,35);
    glVertex3f(-66,-23.8,-35);
    glVertex3f(-66,-25.8,-35);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(186/255.0f, 180/255.0f, 15/255.0f);
    glVertex3f(-65.9,-25.8,13);
    glVertex3f(-65.9,-23.8,13);
    glVertex3f(-65.9,-23.8,11);
    glVertex3f(-65.9,-25.8,11);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(186/255.0f, 180/255.0f, 15/255.0f);
    glVertex3f(-65.9,-25.8,-18);
    glVertex3f(-65.9,-23.8,-18);
    glVertex3f(-65.9,-23.8,-20);
    glVertex3f(-65.9,-25.8,-20);
    glEnd();

    //5
    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);
    glVertex3f(-68,-21.8,35);
    glVertex3f(-70,-21.8,35);
    glVertex3f(-70,-21.8,-35);
    glVertex3f(-68,-21.8,-35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(240/255.0f, 228/255.0f, 37/255.0f);
    glVertex3f(-68,-21.7,-18);
    glVertex3f(-70,-21.7,-18);
    glVertex3f(-70,-21.7,-20);
    glVertex3f(-68,-21.7,-20);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(240/255.0f, 228/255.0f, 37/255.0f);
    glVertex3f(-68,-21.7,13);
    glVertex3f(-70,-21.7,13);
    glVertex3f(-70,-21.7,11);
    glVertex3f(-68,-21.7,11);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(183/255.0f, 183/255.0f, 183/255.0f);
    glVertex3f(-68,-23.8,35);
    glVertex3f(-68,-21.8,35);
    glVertex3f(-68,-21.8,-35);
    glVertex3f(-68,-23.8,-35);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(186/255.0f, 180/255.0f, 15/255.0f);
    glVertex3f(-67.9,-23.8,13);
    glVertex3f(-67.9,-21.8,13);
    glVertex3f(-67.9,-21.8,11);
    glVertex3f(-67.9,-23.8,11);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(186/255.0f, 180/255.0f, 15/255.0f);
    glVertex3f(-67.9,-23.8,-18);
    glVertex3f(-67.9,-21.8,-18);
    glVertex3f(-67.9,-21.8,-20);
    glVertex3f(-67.9,-23.8,-20);
    glEnd();

    //6
    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);
    glVertex3f(-70,-19.8,35);
    glVertex3f(-72,-19.8,35);
    glVertex3f(-72,-19.8,-35);
    glVertex3f(-70,-19.8,-35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(240/255.0f, 228/255.0f, 37/255.0f);
    glVertex3f(-70,-19.7,-18);
    glVertex3f(-72,-19.7,-18);
    glVertex3f(-72,-19.7,-20);
    glVertex3f(-70,-19.7,-20);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(240/255.0f, 228/255.0f, 37/255.0f);
    glVertex3f(-70,-19.7,13);
    glVertex3f(-72,-19.7,13);
    glVertex3f(-72,-19.7,11);
    glVertex3f(-70,-19.7,11);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(183/255.0f, 183/255.0f, 183/255.0f);
    glVertex3f(-70,-21.8,35);
    glVertex3f(-70,-19.8,35);
    glVertex3f(-70,-19.8,-35);
    glVertex3f(-70,-21.8,-35);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(186/255.0f, 180/255.0f, 15/255.0f);
    glVertex3f(-69.9,-21.8,13);
    glVertex3f(-69.9,-19.8,13);
    glVertex3f(-69.9,-19.8,11);
    glVertex3f(-69.9,-21.8,11);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(186/255.0f, 180/255.0f, 15/255.0f);
    glVertex3f(-69.9,-21.8,-18);
    glVertex3f(-69.9,-19.8,-18);
    glVertex3f(-69.9,-19.8,-20);
    glVertex3f(-69.9,-21.8,-20);
    glEnd();

    //7
    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);
    glVertex3f(-72,-17.8,35);
    glVertex3f(-74,-17.8,35);
    glVertex3f(-74,-17.8,-35);
    glVertex3f(-72,-17.8,-35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(240/255.0f, 228/255.0f, 37/255.0f);
    glVertex3f(-72,-17.7,-18);
    glVertex3f(-74,-17.7,-18);
    glVertex3f(-74,-17.7,-20);
    glVertex3f(-72,-17.7,-20);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(240/255.0f, 228/255.0f, 37/255.0f);
    glVertex3f(-72,-17.7,13);
    glVertex3f(-74,-17.7,13);
    glVertex3f(-74,-17.7,11);
    glVertex3f(-72,-17.7,11);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(183/255.0f, 183/255.0f, 183/255.0f);
    glVertex3f(-72,-19.8,35);
    glVertex3f(-72,-17.8,35);
    glVertex3f(-72,-17.8,-35);
    glVertex3f(-72,-19.8,-35);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(186/255.0f, 180/255.0f, 15/255.0f);
    glVertex3f(-71.9,-19.8,13);
    glVertex3f(-71.9,-17.8,13);
    glVertex3f(-71.9,-17.8,11);
    glVertex3f(-71.9,-19.8,11);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(186/255.0f, 180/255.0f, 15/255.0f);
    glVertex3f(-71.9,-19.8,-18);
    glVertex3f(-71.9,-17.8,-18);
    glVertex3f(-71.9,-17.8,-20);
    glVertex3f(-71.9,-19.8,-20);
    glEnd();

    //8
    glBegin(GL_POLYGON);
    glColor3f(222/255.0f, 222/255.0f, 222/255.0f);
    glVertex3f(-74,-15.8,35);
    glVertex3f(-76,-15.8,35);
    glVertex3f(-76,-15.8,-35);
    glVertex3f(-74,-15.8,-35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(240/255.0f, 228/255.0f, 37/255.0f);
    glVertex3f(-74,-15.7,-18);
    glVertex3f(-76,-15.7,-18);
    glVertex3f(-76,-15.7,-20);
    glVertex3f(-74,-15.7,-20);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(240/255.0f, 228/255.0f, 37/255.0f);
    glVertex3f(-74,-15.7,13);
    glVertex3f(-76,-15.7,13);
    glVertex3f(-76,-15.7,11);
    glVertex3f(-74,-15.7,11);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(183/255.0f, 183/255.0f, 183/255.0f);
    glVertex3f(-74,-17.8,35);
    glVertex3f(-74,-15.8,35);
    glVertex3f(-74,-15.8,-35);
    glVertex3f(-74,-17.8,-35);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(186/255.0f, 180/255.0f, 15/255.0f);
    glVertex3f(-73.9,-17.8,13);
    glVertex3f(-73.9,-15.8,13);
    glVertex3f(-73.9,-15.8,11);
    glVertex3f(-73.9,-17.8,11);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(186/255.0f, 180/255.0f, 15/255.0f);
    glVertex3f(-73.9,-17.8,-18);
    glVertex3f(-73.9,-15.8,-18);
    glVertex3f(-73.9,-15.8,-20);
    glVertex3f(-73.9,-17.8,-20);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-60,-30,35);
    glVertex3f(-62,-30,35);
    glVertex3f(-62,-29.8,35);
    glVertex3f(-60,-29.8,35);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-62,-30,35);
    glVertex3f(-64,-30,35);
    glVertex3f(-64,-27.8,35);
    glVertex3f(-62,-27.8,35);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-64,-30,35);
    glVertex3f(-66,-30,35);
    glVertex3f(-66,-25.8,35);
    glVertex3f(-64,-25.8,35);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-66,-30,35);
    glVertex3f(-68,-30,35);
    glVertex3f(-68,-23.8,35);
    glVertex3f(-66,-23.8,35);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-68,-30,35);
    glVertex3f(-70,-30,35);
    glVertex3f(-70,-21.8,35);
    glVertex3f(-68,-21.8,35);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-70,-30,35);
    glVertex3f(-72,-30,35);
    glVertex3f(-72,-19.8,35);
    glVertex3f(-70,-19.8,35);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-72,-30,35);
    glVertex3f(-74,-30,35);
    glVertex3f(-74,-17.8,35);
    glVertex3f(-72,-17.8,35);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-74,-30,35);
    glVertex3f(-76,-30,35);
    glVertex3f(-76,-15.8,35);
    glVertex3f(-74,-15.8,35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-60,-30,18);
    glVertex3f(-62,-30,18);
    glVertex3f(-62,-29.8,18);
    glVertex3f(-60,-29.8,18);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-62,-30,18);
    glVertex3f(-64,-30,18);
    glVertex3f(-64,-27.8,18);
    glVertex3f(-62,-27.8,18);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-64,-30,18);
    glVertex3f(-66,-30,18);
    glVertex3f(-66,-25.8,18);
    glVertex3f(-64,-25.8,18);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-66,-30,18);
    glVertex3f(-68,-30,18);
    glVertex3f(-68,-23.8,18);
    glVertex3f(-66,-23.8,18);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-68,-30,18);
    glVertex3f(-70,-30,18);
    glVertex3f(-70,-21.8,18);
    glVertex3f(-68,-21.8,18);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-70,-30,18);
    glVertex3f(-72,-30,18);
    glVertex3f(-72,-19.8,18);
    glVertex3f(-70,-19.8,18);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-72,-30,18);
    glVertex3f(-74,-30,18);
    glVertex3f(-74,-17.8,18);
    glVertex3f(-72,-17.8,18);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-74,-30,18);
    glVertex3f(-76,-30,18);
    glVertex3f(-76,-15.8,18);
    glVertex3f(-74,-15.8,18);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-60,-30,13);
    glVertex3f(-62,-30,13);
    glVertex3f(-62,-29.8,13);
    glVertex3f(-60,-29.8,13);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-62,-30,13);
    glVertex3f(-64,-30,13);
    glVertex3f(-64,-27.8,13);
    glVertex3f(-62,-27.8,13);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-64,-30,13);
    glVertex3f(-66,-30,13);
    glVertex3f(-66,-25.8,13);
    glVertex3f(-64,-25.8,13);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-66,-30,13);
    glVertex3f(-68,-30,13);
    glVertex3f(-68,-23.8,13);
    glVertex3f(-66,-23.8,13);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-68,-30,13);
    glVertex3f(-70,-30,13);
    glVertex3f(-70,-21.8,13);
    glVertex3f(-68,-21.8,13);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-70,-30,13);
    glVertex3f(-72,-30,13);
    glVertex3f(-72,-19.8,13);
    glVertex3f(-70,-19.8,13);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-72,-30,13);
    glVertex3f(-74,-30,13);
    glVertex3f(-74,-17.8,13);
    glVertex3f(-72,-17.8,13);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-74,-30,13);
    glVertex3f(-76,-30,13);
    glVertex3f(-76,-15.8,13);
    glVertex3f(-74,-15.8,13);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-60,-30,-13);
    glVertex3f(-62,-30,-13);
    glVertex3f(-62,-29.8,-13);
    glVertex3f(-60,-29.8,-13);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-62,-30,-13);
    glVertex3f(-64,-30,-13);
    glVertex3f(-64,-27.8,-13);
    glVertex3f(-62,-27.8,-13);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-64,-30,-13);
    glVertex3f(-66,-30,-13);
    glVertex3f(-66,-25.8,-13);
    glVertex3f(-64,-25.8,-13);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-66,-30,-13);
    glVertex3f(-68,-30,-13);
    glVertex3f(-68,-23.8,-13);
    glVertex3f(-66,-23.8,-13);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-68,-30,-13);
    glVertex3f(-70,-30,-13);
    glVertex3f(-70,-21.8,-13);
    glVertex3f(-68,-21.8,-13);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-70,-30,-13);
    glVertex3f(-72,-30,-13);
    glVertex3f(-72,-19.8,-13);
    glVertex3f(-70,-19.8,-13);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-72,-30,-13);
    glVertex3f(-74,-30,-13);
    glVertex3f(-74,-17.8,-13);
    glVertex3f(-72,-17.8,-13);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-74,-30,-13);
    glVertex3f(-76,-30,-13);
    glVertex3f(-76,-15.8,-13);
    glVertex3f(-74,-15.8,-13);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-60,-30,-18);
    glVertex3f(-62,-30,-18);
    glVertex3f(-62,-29.8,-18);
    glVertex3f(-60,-29.8,-18);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-62,-30,-18);
    glVertex3f(-64,-30,-18);
    glVertex3f(-64,-27.8,-18);
    glVertex3f(-62,-27.8,-18);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-64,-30,-18);
    glVertex3f(-66,-30,-18);
    glVertex3f(-66,-25.8,-18);
    glVertex3f(-64,-25.8,-18);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-66,-30,-18);
    glVertex3f(-68,-30,-18);
    glVertex3f(-68,-23.8,-18);
    glVertex3f(-66,-23.8,-18);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-68,-30,-18);
    glVertex3f(-70,-30,-18);
    glVertex3f(-70,-21.8,-18);
    glVertex3f(-68,-21.8,-18);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-70,-30,-18);
    glVertex3f(-72,-30,-18);
    glVertex3f(-72,-19.8,-18);
    glVertex3f(-70,-19.8,-18);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-72,-30,-18);
    glVertex3f(-74,-30,-18);
    glVertex3f(-74,-17.8,-18);
    glVertex3f(-72,-17.8,-18);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-74,-30,-18);
    glVertex3f(-76,-30,-18);
    glVertex3f(-76,-15.8,-18);
    glVertex3f(-74,-15.8,-18);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-60,-30,-35);
    glVertex3f(-62,-30,-35);
    glVertex3f(-62,-29.8,-35);
    glVertex3f(-60,-29.8,-35);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-62,-30,-35);
    glVertex3f(-64,-30,-35);
    glVertex3f(-64,-27.8,-35);
    glVertex3f(-62,-27.8,-35);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-64,-30,-35);
    glVertex3f(-66,-30,-35);
    glVertex3f(-66,-25.8,-35);
    glVertex3f(-64,-25.8,-35);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-66,-30,-35);
    glVertex3f(-68,-30,-35);
    glVertex3f(-68,-23.8,-35);
    glVertex3f(-66,-23.8,-35);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-68,-30,-35);
    glVertex3f(-70,-30,-35);
    glVertex3f(-70,-21.8,-35);
    glVertex3f(-68,-21.8,-35);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-70,-30,-35);
    glVertex3f(-72,-30,-35);
    glVertex3f(-72,-19.8,-35);
    glVertex3f(-70,-19.8,-35);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-72,-30,-35);
    glVertex3f(-74,-30,-35);
    glVertex3f(-74,-17.8,-35);
    glVertex3f(-72,-17.8,-35);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-74,-30,-35);
    glVertex3f(-76,-30,-35);
    glVertex3f(-76,-15.8,-35);
    glVertex3f(-74,-15.8,-35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(200/255.0f, 200/255.0f, 200/255.0f);
    glVertex3f(-62,-25.8,18);
    glVertex3f(-62,-25.8,13);
    glVertex3f(-66,-25.8,13);
    glVertex3f(-66,-25.8,18);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-62,-25.8,18);
    glVertex3f(-62,-30,18);
    glVertex3f(-66,-30,18);
    glVertex3f(-66,-25.8,18);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-62,-25.8,13);
    glVertex3f(-62,-30,13);
    glVertex3f(-66,-30,13);
    glVertex3f(-66,-25.8,13);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(200/255.0f, 200/255.0f, 200/255.0f);
    glVertex3f(-62,-25.8,-18);
    glVertex3f(-62,-25.8,-13);
    glVertex3f(-66,-25.8,-13);
    glVertex3f(-66,-25.8,-18);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-62,-25.8,-18);
    glVertex3f(-62,-30,-18);
    glVertex3f(-66,-30,-18);
    glVertex3f(-66,-25.8,-18);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(165/255.0f, 165/255.0f, 165/255.0f);
    glVertex3f(-62,-25.8,-13);
    glVertex3f(-62,-30,-13);
    glVertex3f(-66,-30,-13);
    glVertex3f(-66,-25.8,-13);
    glEnd();






    glPushMatrix();
    glPopMatrix();

    glutSwapBuffers();
}

void idle()
{
    if (!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y)
{
    look();
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar/tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
	case 'A':
		// bergeser ke kiri
		glTranslatef(-1.0, 0.0, 0.0);
		break;
	case 'd':
	case 'D':
		// bergeser ke kanan
		glTranslatef(1.0, 0.0, 0.0);
		break;
	case 'w':
	case 'W':
		// bergeser ke atas
		glTranslatef(0.0, 1.0, 0.0);
		break;
	case 's':
	case 'S':
		// bergeser ke bawah
		glTranslatef(0.0, -1.0, 0.0);
		break;
	case 'x':
	case 'X':
		// berotasi ke kanan
		glRotatef(1.0, 0.0, 0.0, -5.0);
		break;
	case 'z':
	case 'Z':
		// berotasi ke kiri
		glRotatef(1.0, 0.0, 0.0, 5.0);
		break;
	case 'c':
	case 'C':
		// perbesar
		glTranslatef(0.0, 0.0, 5.0);
		break;
	case 'v':
	case 'V':
		// perkecil
		glTranslatef(0.0, 0.0, -5.0);
		break;
	}
    tampil();
}

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("TR GRAFIKA KOMPUTER ASDOS");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}
