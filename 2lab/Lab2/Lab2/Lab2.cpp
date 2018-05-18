// Lab2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "GL\freeglut.h"
#include <windows.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>

#define GL_BGR ff00ff
#define pi (3.14)

#define SHAR (0)
#define PIRAMID (1)
#define	BOTH (2)

#define X (0)
#define Y (1)

float size_shar = 0.5;
float size_piramid = 0.5;
float color_shar[3];
float color_piramid[3];
float pos_shar[3];
float pos_piramid[3];
int angle_shar[2];
int angle_piramid[2];
int timer = 0;
int state = SHAR;
int rotating_state = 0;
GLUquadricObj *mySphere;

int xpos, ypos;

int InitGL(void){
	pos_shar[0] = -1.0;
	pos_shar[1] = 0.0;
	pos_shar[2] = 0.0;

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { 20.2, 20.0, 30.0, 0.0 };
	glShadeModel(GL_FLAT);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	mySphere = gluNewQuadric();  // Создать квадратичный объект
	// тип генерируемых нормалей для него – «сглаженные»
	gluQuadricNormals(mySphere, GL_SMOOTH);
	// Настройка отображения сферы
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);

	return true;
}

void mouse(int x, int y){
	xpos = x;
	ypos = y;
	glutPostRedisplay();
}

void timer_func(int a){
	if (timer < 350) {
		timer++;
	}
	glutPostRedisplay();
	glutTimerFunc(25, timer_func, a);
}

void drawShar(float size){
	glTranslatef(pos_shar[0], pos_shar[1], pos_shar[2]);
	glColor3f(color_shar[0], color_shar[1], color_shar[2]);
	glPushMatrix();
	glRotatef(angle_shar[0], 1.0, 0.0, 0.0);
	glRotatef(angle_shar[1], 0.0, 1.0, 0.0);
	glTranslatef(0, -0.9, -0.9);
	glRotatef(1, 0, 1, 0);
	glRotatef(210, 1, 0, 0);
	gluSphere(mySphere, size_shar, 32, 16);
	glPopMatrix();
}

void DrawPiramid(float fA){
	glTranslatef(pos_piramid[0], pos_piramid[1], pos_piramid[2]);
	glColor3f(color_piramid[0], color_piramid[1], color_piramid[2]);
	glPushMatrix();
	glRotatef(angle_piramid[0], 0.0, 1.0, 1.0);
	glRotatef(angle_piramid[1], 1.0, 0.0, 1.0);
	glTranslatef(0, -0.9, -0.9);
	glRotatef(0, 1, 0, 1);
	glRotatef(210, 1, 0, 0);
	glPopMatrix();
	
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);

	glVertex3f(0.0, size_piramid, 0.0);

	glVertex3f(-size_piramid, -size_piramid, size_piramid);

	glVertex3f(size_piramid, -size_piramid, size_piramid);

	///////////////////////////

	glColor3f(0.0, 1.0, 0.0);

	glVertex3f(0.0, size_piramid, 0.0);

	glVertex3f(size_piramid, -size_piramid, size_piramid);

	glVertex3f(size_piramid, -size_piramid, -size_piramid);

	///////////////////////////

	glColor3f(0.0, 0.0, 1.0);

	glVertex3f(0.0, size_piramid, 0.0);

	glVertex3f(size_piramid, -size_piramid, -size_piramid);

	glVertex3f(-size_piramid, -size_piramid, -size_piramid);

	////////////////////////////

	glColor3f(1.0, 1.0, 0.0);

	glVertex3f(0.0, size_piramid, 0.0);

	glVertex3f(-size_piramid, -size_piramid, -size_piramid);

	glVertex3f(-size_piramid, -size_piramid, size_piramid);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);

	glVertex3f(-size_piramid, -size_piramid, size_piramid);

	glVertex3f(-size_piramid, -size_piramid, -size_piramid);

	glVertex3f(size_piramid, -size_piramid, -size_piramid);

	glVertex3f(size_piramid, -size_piramid, size_piramid);
	glEnd();

	glPopMatrix();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(0.0, 0.0, 4.0,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);

	glScalef(1.0, 1.0, 1.0);

	//SHAR
	glPushMatrix();
	//rotate to get the right perspective
	glRotatef(1.0, 5.0, 0.0, 0.0);
	drawShar(size_shar);
	glPopMatrix();

	//Piramid
	glPushMatrix();
	//rotate to get the right perspective
	glRotatef(11.0, 3.0, 0.0, 0.0);
	DrawPiramid(0.5);
	glPopMatrix();
	glFlush();
}

void rotate_shar_global_axes(int axis, int direction){
	float angle_x, angle_y, radius;
	if (axis == Y){
		radius = sqrt(pos_shar[0] * pos_shar[0] + pos_shar[2] * pos_shar[2]);
		if (radius == 0){
			angle_shar[1] += direction;
			return;
		}
		angle_x = acos(pos_shar[0] / radius);
		angle_x += direction*pi / 180;
		pos_shar[0] = radius*cos(angle_x);
		pos_shar[2] = radius*sin(angle_x);
		std::cout << pos_shar[2] << std::endl;
	}
	else{
		radius = sqrt(pos_shar[1] * pos_shar[1] + pos_shar[2] * pos_shar[2]);
		if (radius == 0){
			angle_shar[0] += direction;
			return;
		}
		angle_y = acos(pos_shar[1] / radius);
		angle_y += direction*pi / 180;
		pos_shar[1] = radius*cos(angle_y);
		pos_shar[2] = radius*sin(angle_y);
	}
}

void rotate_piramid_global_axes(int axis, int direction){
	float angle_x, angle_y, radius;
	if (axis == Y){
		radius = sqrt(pos_piramid[0] * pos_piramid[0] + pos_piramid[2] * pos_piramid[2]);
		if (radius == 0){
			angle_piramid[1] += direction;
			return;
		}
		angle_x = acos(pos_piramid[0] / radius);
		angle_x += direction*pi / 180;
		pos_piramid[0] = radius*cos(angle_x);
		pos_piramid[2] = radius*sin(angle_x);
		std::cout << pos_piramid[2] << std::endl;
	}
	else{
		radius = sqrt(pos_piramid[1] * pos_piramid[1] + pos_piramid[2] * pos_piramid[2]);
		if (radius == 0){
			angle_piramid[0] += direction;
			return;
		}
		angle_y = acos(pos_piramid[1] / radius);
		angle_y += direction*pi / 180;
		pos_piramid[1] = radius*cos(angle_y);
		pos_piramid[2] = radius*sin(angle_y);
	}
}

void reshape(int w, int h){
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard2(unsigned char key, int x, int y) {
	switch (key) {

		// Вибір фігур(и)
	case 'o': state = SHAR; break;
	case 'p': state = PIRAMID; break;
	case 'b': state = BOTH; break;
	default:
		switch (key) {
			// Переключає режим повороту фігур(и)
		case 'r':
			if (rotating_state == 0) rotating_state = 1;
			else rotating_state = 0;
			break;

			// Зміна розмірів фігур(и)
		case '+':
			if (state==SHAR) if (size_shar <= 1) size_shar += 0.1;
			if (state == PIRAMID) if (size_piramid <= 1) size_piramid += 0.1;
			break;
		case '-':
			if (state == SHAR) if (size_shar >= 0.2) size_shar -= 0.1;
			if (state == PIRAMID) if (size_piramid >= 0.2) size_piramid -= 0.1;
			break;

			// Повороти фігур(и)
		case 'w':
			if (rotating_state == 0) {
				if (state == SHAR) angle_shar[1]++;
				if (state==PIRAMID) angle_piramid[1]++;
			}
			else {
				if (state == SHAR) rotate_shar_global_axes(X, 1);
				if (state == PIRAMID) rotate_piramid_global_axes(X, 1);
			}
			break;
		case 's':
			if (rotating_state == 0) {
				if (state == SHAR) angle_shar[1]--;
				if (state == PIRAMID) angle_piramid[1]--;
			}
			else {
				if (state == SHAR) rotate_shar_global_axes(X, -1);
				if (state == PIRAMID) rotate_piramid_global_axes(X, -1);
			}
			break;
		case 'd':
			if (rotating_state == 0) {
				if (state == SHAR) angle_shar[2]++;
				if (state == PIRAMID) angle_piramid[2]++;
			}
			else {
				if (state == SHAR) rotate_shar_global_axes(Y, 1);
				if (state == PIRAMID) rotate_piramid_global_axes(Y, 1);
			}
			break;
		case 'a':
			if (rotating_state == 0) {
				if (state == SHAR) angle_shar[2]--;
				if (state == PIRAMID) angle_piramid[2]--;
			}
			else {
				if (state == SHAR) rotate_shar_global_axes(Y, -1);
				if (state == PIRAMID) rotate_piramid_global_axes(Y, -1);
			}
			break;
		}
	}
}

void keyboard1(unsigned char key, int x, int y){
	switch (key){
	case 'c': state = SHAR; break;
	case 'r':
		if (rotating_state == 0) rotating_state = 1;
		else rotating_state = 0;
		break;
	case '+':
		if (size_shar <= 1)
			size_shar += 0.1;
		break;
	case '-':
	case SHAR:
		if (size_shar >= 0.2)
			size_shar -= 0.1;
		break;
	case 'w':
		if (rotating_state == 0)
			angle_shar[0]++;
		else
			rotate_shar_global_axes(X, 1);
		break;
	case 's':
		if (rotating_state == 0)
			angle_shar[0]--;
		else
			rotate_shar_global_axes(X, -1);
		break;
	case 'd':
		if (rotating_state == 0)
			angle_shar[1]++;
		else
			rotate_shar_global_axes(Y, 1); break;

	case 'a':
		if (rotating_state == 0)
			angle_shar[1]--;
		else
			rotate_shar_global_axes(Y, -1); break;
	}
}

void keyboard(unsigned char key, int x, int y){
	int mod = glutGetModifiers();
	switch (key){
	case 'm':
		if (mod == GLUT_ACTIVE_CTRL){
			size_shar -= 0.1; break;
		}
		else{
			size_piramid -= 0.1; break;
		}
	case 'p':
		if (mod == GLUT_ACTIVE_CTRL){
			size_shar += 0.1; break;
		}
		else{
			size_piramid += 0.1; break;
		}
	}
	glutDisplayFunc(display);
}

void skeyboard(int key, int x, int y){
		int mod = glutGetModifiers();
			switch (key){
			case GLUT_KEY_DOWN:
				if (mod == GLUT_ACTIVE_CTRL){
					pos_shar[1] -= 0.1; break;
				}
				else{
					pos_piramid[1] -= 0.1; break;
				}
			case GLUT_KEY_UP:
				if (mod == GLUT_ACTIVE_CTRL){
					pos_shar[1] += 0.1; break;
				}
				else{
					pos_piramid[1] += 0.1; break;
				}

			case GLUT_KEY_LEFT:
				if (mod == GLUT_ACTIVE_CTRL){
					pos_shar[0] -= 0.1; break;
				}
				else{
					pos_piramid[0] -= 0.1; break;
				}
			case GLUT_KEY_RIGHT:
				if (mod == GLUT_ACTIVE_CTRL){
					pos_shar[0] += 0.1; break;
				}
				else{
					pos_piramid[0] += 0.1; break;
				}
			}
		}

void set_color(){
	color_shar[0] = 0.2; color_shar[1] = 0.5; color_shar[2] = 0.8;
	color_piramid[0] = 0.8; color_piramid[1] = 0.1; color_piramid[2] = 0.2;
}


int main(int argc, char** argv){
	glutInit(&argc, argv);
	srand(time(0));
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	set_color();
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("My OpenGL Application");
	InitGL();
	glutDisplayFunc(display);
	//glutKeyboardFunc(keyboard1);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(skeyboard);
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutTimerFunc(25, timer_func, 0);

	glutPassiveMotionFunc(mouse);

	glutMainLoop();
	return 0;
}