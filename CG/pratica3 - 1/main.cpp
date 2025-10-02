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
    glBegin(GL_POINTS);
    glVertex2i(auxX, auxY);
    glEnd();
    glFlush();
}
static void key(unsigned char key, int x, int y)
{
     cout << key << endl;
    switch(key){
    case 'R':
    case 'r':
        glColor3f(1,0,0);
        break;
    case 'b':
    case 'B':
        glColor3f(0,0,1);
        break;
    case 'G':
    case 'g':
        glColor3f(0,1,0);
        break;
    case 27:
        exit(0);
    break;
    }

    if (key == 27)
        exit(0);
}

// função para tratar os eventos do mouse
static void mouse(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON){
        if (state == GLUT_DOWN){

        }
    }
}

// função responsável por fazer as inicializações
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
    glutKeyboardFunc(key);
// registra a função callback para tratar os eventos do mouse
    glutMouseFunc(mouse);
    glutReshapeFunc(resize);
    setup();
    glutMainLoop();
    return 0;
}
