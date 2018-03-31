#include<windows.h>

#include <iostream>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

//Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
		case 27: //Escape key
			exit(0);
	}
}

//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING); //Enable lighting
	glEnable(GL_LIGHT0); //Enable light #0
	glEnable(GL_LIGHT1); //Enable light #1
	glEnable(GL_NORMALIZE); //Automatically normalize normals
	//glShadeModel(GL_SMOOTH); //Enable smooth shading
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

//------------------------------------------------
float _angle = 0.0f;
void update(int value) ;


void drawSun(){
    //sun
    glColor3f(.98,.4,0.0);
    glutSolidSphere(0.65,200,200);
}

float MercuryAngle, MercurySpeed = 15.0f;
void drawMercury(){
    //mercury

    glPushMatrix();
    glRotatef(MercuryAngle,0.0f,1.0f,0.0f);
    glTranslatef(.4,.1,0.0);

    glColor3f(.88,.88,.88);
    glutSolidSphere(0.07,100,100);
    glPopMatrix();
}

float VenusAngle, VenusSpeed = 10.0f;
void drawVenus(){
    //Venus

        //Orbit
    glColor3f(1,1,1);
    glutWireTorus(.8,0,100,1);

    glPushMatrix();
    glRotatef(VenusAngle,0.0f,1.0f,0.0f);
    glTranslatef(0.8,0.1,0.0);

    glColor3f(.96,.82,.6);
    glutSolidSphere(.1,100,100);
    glPopMatrix();
}

float EarthAngle, EarthSpeed = 8.0f;
void drawEarth(){
    //earth

        //Orbit
    glColor3f(1,1,1);
    glutWireTorus(1.35,.0,100,1);


    glPushMatrix();
    glRotatef(EarthAngle,0.0f,1.0f,0.0f);
    glTranslatef(1.3,0.1,0.0);

    glColor3f(.27,.68,.93);
    glutSolidSphere(.15,100,100);
    glPopMatrix();
}

float MarsAngle, MarsSpeed = 9.0f;
void drawMars(){
    //mars

    //Orbit
    glColor3f(1,1,1);
    glutWireTorus(1.85,0,100,1);

    glPushMatrix();
    glRotatef(MarsAngle,0.0f,1.0f,0.0f);
    glTranslatef(1.8,0.1,0.0);

    glColor3f(.99,.33,.3);
    glutSolidSphere(.11,100,100);
    glPopMatrix();
}

float JupiterAngle, JupiterSpeed = 6.0f;
void drawJupiter(){
    //Jupiter

    //Orbit
    glColor3f(1,1,1);
    glutWireTorus(2.3,0,100,1);

    glPushMatrix();
    glRotatef(JupiterAngle,0.0f,1.0f,0.0f);
    glTranslatef(2.3,0.1,0.0);

    glColor3f(.67,.59,.53);
    glutSolidSphere(.25,100,100);
    glPopMatrix();
}

float SaturnAngle, SaturnSpeed = 3.0f;
void drawSaturn(){
    //Saturn

    //Orbit
    glColor3f(1,1,1);
    glutWireTorus(2.8,0,100,1);

    glPushMatrix();
    glRotatef(SaturnAngle,0.0f,1.0f,0.0f);
    glTranslatef(2.8,0.1,0.0);

    glColor3f(.75,.62,.43);
    glutSolidSphere(.18,100,100);
    glPopMatrix();
}

float UranusAngle, UranusSpeed = 4.0f;
void drawUranus(){
    //Uranus

    //Orbit
    glColor3f(1,1,1);
    glutWireTorus(3.35,0,100,1);

    glPushMatrix();
    glRotatef(UranusAngle,0.0f,1.0f,0.0f);
    glTranslatef(3.3,0.1,0.0);

    glColor3f(.5,.62,.8);
    glutSolidSphere(.13,100,100);
    glPopMatrix();
}

float NeptuneAngle, NeptuneSpeed = 7.0f;
void drawNeptune(){
    //Neptune

    //Orbit
    glColor3f(1,1,1);
    glutWireTorus(3.85,0,100,1);

    glPushMatrix();
    glRotatef(NeptuneAngle,0.0f,1.0f,0.0f);
    glTranslatef(3.8,0.1,0.0);

    glColor3f(.22,.32,.82);
    glutSolidSphere(.11,100,100);
    glPopMatrix();
}

//------------------------------------------------

//Draws the 3D scene
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 0.6f, -7.5f);

	//Add ambient light
	GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; //Color (0.2, 0.2, 0.2)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	//Add positioned light
	GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
	GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f}; //Positioned at (4, 0, 8)
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

	//Add directed light
	GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2)
	//Coming from the direction (-1, 0.5, 0.5)
	GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

	glColor3f(1.0f, 1.0f, 0.0f);

    // rotate the whole scene by 20 degree
    glRotatef(40,1.0f,.5f,-0.35f);

//------------Call Draw Functions-------------

    //drawStars();
    drawSun();
    drawMercury();
    drawVenus();
    drawEarth();
    drawMars();
    drawJupiter();
    drawSaturn();
    drawUranus();
    drawNeptune();


	glutSwapBuffers();
}


//--------------Draw Ends----------------------

void update(int value) {
	MercuryAngle += MercurySpeed;
	if(MercuryAngle>360.0f)
        MercuryAngle -= 360.0f;

	VenusAngle += VenusSpeed;
	if(VenusAngle>360.0f)
        VenusAngle -= 360.0f;

	EarthAngle += EarthSpeed;
	if(EarthAngle>360.0f)
        EarthAngle -= 360.0f;

	MarsAngle += MarsSpeed;
	if(MarsAngle>360.0f)
        MarsAngle -= 360.0f;

	JupiterAngle += JupiterSpeed;
	if(JupiterAngle>360.0f)
        JupiterAngle -= 360.0f;

	SaturnAngle += SaturnSpeed;
	if(SaturnAngle>360.0f)
        SaturnAngle -= 360.0f;

	UranusAngle += UranusSpeed;
	if(UranusAngle>360.0f)
        UranusAngle -= 360.0f;

	NeptuneAngle += NeptuneSpeed;
	if(NeptuneAngle>360.0f)
        NeptuneSpeed -= 360.0f;

	glutPostRedisplay();
	glutTimerFunc(50, update, 0);
}

//-----------------------------------------------------

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1050,650);

	//Create the window
	glutCreateWindow("Solar System");
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);

	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	glutTimerFunc(1, update, 0); //Add a timer

	glutMainLoop();
	return 0;
}
