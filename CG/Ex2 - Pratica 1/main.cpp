#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <cmath> //Biblioteca das fun�oes matematicas
#endif
#include <iostream>
using namespace std;

//========================================================
//          Criando Ex 2
//========================================================

// Fun��o onde sera passado a quantidade de pontos e o raio dos pontos
void funcao1(){
    glBegin(GL_LINE_STRIP); // modo desenho dos
    int aux = -3;
    int numPontos = 8;

    for(int i=0; i< numPontos; i++ ){
        float y = (aux*aux) - (2* aux);
        float x = aux;
        glVertex2f(x,y);
        cout << "X: " << x << " Y: "<< y<<endl;
        //cout << x;
        aux = aux+1;
    }

    glEnd();
}

void funcao2(){
    glBegin(GL_LINE_STRIP); // modo desenho dos
    int aux = -3;
    int numPontos = 10;

    for(int i=0; i< numPontos; i++ ){
        float y = -(aux*aux) + (3* aux);
        float x = aux;
        glVertex2f(x,y);
        cout << "X: " << x << " Y: "<< y<<endl;
        //cout << x;
        aux = aux+1;
    }

    glEnd();
}

void plano(){
//=========================================
//              Plano cartesiano
//=========================================
glLineWidth(2);

glBegin(GL_LINES);
    glColor3f(1,1,0);
    glVertex2i(0,20);
    glVertex2i(0,-20);
    glVertex2i(-20,0);
    glVertex2i(20,0);
glEnd();
//=========================================
}

// fun��o de redesenho da janela de visualiza��o
void display()
{
    glClear(GL_COLOR_BUFFER_BIT); //Limpa o buffer

    glPointSize(5); //Tamanho do ponto

    // PRIMEIRO Funcao
    glColor3f(3,0,2);
    funcao1();


    // SEGUNDA Funcao
    glColor3f(0,0,2);
    funcao2();

    plano();

    glFlush(); //For�a para rederizar
}
//========================================================



// fun��o de redimensionamento da janela de visualiza��o
static void resize(int width, int height){
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
    //gluOrtho2D (-40.0f, 40.0f, -40.0f, 40.0f);

    // estabelece a janela de sele��o (esquerda, direita, inferior,
    // superior) mantendo a propor��o com a janela de visualiz�o
    if (width <= height)
        gluOrtho2D (-20.0f, 20.0f, -20.0f*height/width, 20.0f*height/width);
    else
        gluOrtho2D (-20.0f*width/height, 20.0f*width/height, -20.0f, 20.0f);
}

// fun��o para tratar os eventos do teclado
static void key(unsigned char key, int x, int y)
{
}
// fun��o respons�vel por fazer as inicializa��es
void setup(void)
{
}

// Programa Principal
int main(int argc, char *argv[])
{

// utilizada para inicializar a biblioteca GLUT
    glutInit(&argc, argv);
// define do modo de opera��o da GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
// especifica o tamanho inicial em pixels da janela GLUT
    glutInitWindowSize(400, 400);
// especifica a posi��o inicial da janela GLUT
    glutInitWindowPosition(100, 100);
// cria a janela passando como t�tulo como argumento
    glutCreateWindow("circulos  7, 10, 30");

// registra a fun��o callback de redesenho da janela de visualiza��o
    glutDisplayFunc(display);
// registra a fun��o callback para tratar os eventos do teclado
    glutKeyboardFunc(key);
// registra a fun��o callback de redimensionamento da janela de visualiza��o
    glutReshapeFunc(resize);
// chama a fun��o respons�vel por fazer as inicializa��es
    setup();
// inicia o processamento e aguarda intera��es do usu�rio
    glutMainLoop();
    return 0;
}
