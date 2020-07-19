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
    glColor3f(93/255.0f, 118/255.0f, 77/255.0f);
    glVertex3f(-60,-29.9,40);
    glVertex3f(-60,-29.9,-40);
    glVertex3f(60,-29.9,-40);
    glVertex3f(60,-29.9,40);
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