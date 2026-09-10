
#include "Game.h"
#include <iostream>
#include <GL/glut.h>
#include <string>
using namespace std;
///////CONSTANTES////////////////////
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int WINDOW_POSITION_X = 0;
const int WINDOW_POSITION_Y = 0;
const char TITLE[] = "PARTE 1";
const GLclampf RED = 0.25;
const GLclampf GREEN = 0.25;
const GLclampf BLUE = 0.25;
const GLclampf ALPHA = 1.0;
bool fullScreenMode = false;
/// //////////////////////////////////////

//////////////////USANDO GAME////////////////
Game game;
////////////////////////////////////////
void writeLine(string text) {
    cout << text << endl;
}
/////////////////////////////////////////
void initGraphics() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
   glEnable(GL_COLOR_MATERIAL);
   glClearColor(RED, GREEN, BLUE, ALPHA);
   game.Init();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    game.Render();
    glutSwapBuffers();
}
void reshape(GLsizei width, GLsizei height) {
    if (height == 0)height = 1;
    GLfloat aspectRatio = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.f, aspectRatio, 1.0f, 200.0f);

    glMatrixMode(GL_MODELVIEW);
}
void idle() {
    game.Update();
    glutPostRedisplay();
}
void keyPressed(unsigned char key, int px, int py)
{
    game.ProcessKeyPressed( key,  px,  py);
    glutPostRedisplay();

}
void mouseMoved(int x, int y) {
    game.ProcessMouseMovement(x, y);
    glutPostRedisplay();
}
void mouseClicked(int button, int state, int x, int y)
{
    game.ProcessMouseClick(button, state, x, y);
    glutPostRedisplay();
}
void specialKey(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_F11:
        fullScreenMode = !fullScreenMode;
        if (fullScreenMode) {
            glutFullScreen();
        }
        else {
            glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
            glutPositionWindow(WINDOW_POSITION_X, WINDOW_POSITION_Y);
        }
    }
}
int main(int argc,char** argv)
{
    writeLine("OPEN GL WORLD");
    writeLine("CREATING WINDOW...");

    glutInit(&argc, argv);   //Inicializacion de GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);//doble buffer,rgba y depth buffer
    glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);//tamaño inicial de la ventana
    glutInitWindowPosition(WINDOW_POSITION_X, WINDOW_POSITION_Y);//posicion inicial de la ventana
    glutCreateWindow("title");//crea una ventana con el titulo dado
    ///tratamiento de eventos///
    glutReshapeFunc(reshape);
    
    //tratamiento del evento de repintado de la ventana
    glutDisplayFunc(display);
    glutKeyboardFunc(keyPressed);
    glutSpecialFunc(specialKey);
    glutMotionFunc(mouseMoved);
    glutMouseFunc(mouseClicked);
    glutIdleFunc(idle);
    ////////////////////////////////
    //inicalizacion de los graficos
    initGraphics();

    writeLine("LOOP...");
    glutMainLoop();
    

}

