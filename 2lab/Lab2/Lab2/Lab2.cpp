// Lab2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "GL\freeglut.h"
#include <windows.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>

const int Time = 10;

using namespace std;

typedef struct{
	GLboolean visible;
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLUquadricObj *q;
}Shar;

GLUquadricObj  *q;     // ������������ ������ ��� ��������� �����

Shar masShar[500];
GLuint numberShar = 100;
GLfloat sharRadius = 0.3;
GLuint sharRadiusDrope = 30;

int InitGL()
{
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_TEXTURE_2D);
	glClearDepth(1.0f);                 // ��������� ������� ������ �������   - ����, ������������ ������
	glEnable(GL_DEPTH_TEST);            // ��������� ���� �������
	glDepthFunc(GL_LEQUAL);            // ��� ����� �������
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);      // ��������� � ���������� �����������

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glEnable(GL_BLEND);
	// ��������� ������������ ���������
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	// ��������� ����������� �����
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);

	return true;
}



void DrawGLScene()
{
	InitGL();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // �������� ����� � ����� �������
	glLoadIdentity();
	//glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
	glutSwapBuffers();
}

void Timer(int value){
	DrawGLScene();
	glutTimerFunc(Time, Timer, 1);
}
int _tmain(int argc, CHAR* argv[])
{
	glutInit(&argc, argv);
	srand(time(0));
	/*glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("My OpenGL Application");*/

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutGameModeString("1366x768:32"); //1366x768:32
	glutEnterGameMode();
	glutSetCursor(GLUT_CURSOR_NONE);
	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
	glClearColor(0.4, 0.4, 0.9, 1);
	glMatrixMode(GL_PROJECTION);            // ����� ������� ��������
	glLoadIdentity();              // ����� ������� ��������

	// ���������� ����������� �������������� �������� ��� ����
	gluPerspective(45.0f, 1366.0 / 768.0, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	InitGL();

	glutTimerFunc(Time, Timer, 1);

	GLuint temp;
	//glutPostRedisplay();
	/////////////////
	glutMainLoop();
	return EXIT_SUCCESS;
}

