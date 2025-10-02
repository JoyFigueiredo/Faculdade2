#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
using namespace std;
#include <iostream>

float auxX;
float auxY;


static void resize(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
    //gluOrtho2D (-40.0f, 40.0f, -40.0f, 40.0f);

    // estabelece a janela de seleção (esquerda, direita, inferior,
    // superior) mantendo a proporção com a janela de visualizão
    if (width <= height)
        gluOrtho2D (-40.0f, 40.0f, -40.0f*height/width, 40.0f*height/width);
    else
        gluOrtho2D (-40.0f*width/height, 40.0f*width/height, -40.0f, 40.0f);
}
static void display(){
//desenha o primeiro ponto
    glPointSize(7.0f);
    glColor3f(0,0,1);
    glBegin(GL_QUADS);
        glVertex2f(-15,-10);
        glVertex2f(15,-10);
        glVertex2f(15,10);
        glVertex2f(-15,10);
    glEnd();
    glColor3f(1,0,0);
    glBegin(GL_TRIANGLES);
        glVertex2f(15,10);
        glVertex2f(-15,10);
        glVertex2f(0,20);
    glEnd();
    //PORTA
    glColor3f(0,1,0);
    glBegin(GL_QUADS);
        glVertex2f(-4,5);
        glVertex2f(4,5);
        glVertex2f(4,-9.5);
        glVertex2f(-4,-9.5);
    glEnd();
    //JANELAS
    glColor3f(0,1,0);
    glBegin(GL_QUADS);
        glVertex2f(6.5,0);
        glVertex2f(9,0);
        glVertex2f(9,1.5);
        glVertex2f(6.5,1.5);
    glEnd();
    glColor3f(0,1,0);
    glBegin(GL_QUADS);
        glVertex2f(10,0);
        glVertex2f(12.5,0);
        glVertex2f(12.5,1.5);
        glVertex2f(10,1.5);
    glEnd();
    glColor3f(0,1,0);
    glBegin(GL_QUADS);
        glVertex2f(6.5,2.5);
        glVertex2f(9,2.5);
        glVertex2f(9,4);
        glVertex2f(6.5,4);
    glEnd();
    glColor3f(0,1,0);
    glBegin(GL_QUADS);
        glVertex2f(10,2.5);
        glVertex2f(12.5,2.5);
        glVertex2f(12.5,4);
        glVertex2f(10,4);
    glEnd();
    glFlush();
}

void setup(void)
{
// Define a cor de fundo da janela de visualização como branca
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//limpa a tela
    glClear(GL_COLOR_BUFFER_BIT);
//define a cor preta como inicial
    glColor3f(0.0f, 0.0f, 0.0f);

    gluOrtho2D(-40,40,-40,40);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exercício 1");
    glutDisplayFunc(display);
    //glutKeyboardFunc(key);
// registra a função callback para tratar os eventos do mouse
    //glutMouseFunc(mouse);
    glutReshapeFunc(resize);
    setup();
    glutMainLoop();
    return 0;
}
