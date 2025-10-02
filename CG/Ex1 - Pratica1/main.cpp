#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <cmath> //Biblioteca das funçoes matematicas
#endif

//========================================================
//          Criando Ex 1 Circulos
//========================================================

// Função onde sera passado a quantidade de pontos e o raio dos pontos
void circulos(int numPontos, float raio, float xx)
{
    glBegin(GL_LINE_LOOP); // modo desenho dos pontos iniciada

    for(int i=0; i< numPontos; i++ )
    {
        float angulo = 2 * 3.14* i / numPontos; // 2 pi i/numPontos
        float x = raio* cos(angulo)+xx;
        float y = raio * sin(angulo);

        //Desenha o ponto
        if(numPontos == 7){
            glVertex2f(x,y);
        }else if(numPontos == 10){
            glVertex2f(x,y);
        }else if(numPontos == 30){
            glVertex2f(x,y);
        }
    }

    glEnd();
}

// função de redesenho da janela de visualização
void display()
{
    glClear(GL_COLOR_BUFFER_BIT); //Limpa o buffer

    //glPointSize(5); //Tamanho do ponto
    float raio = 8; // Tamanho do raio
    float espaco = 17; // Tamanho do espaço do circulo

    // PRIMEIRO CIRCULO 7 PONTOS
    glColor3f(3,0,2);
    circulos(7, raio, -espaco);

    // SEGUNDO CIRDULO 10 PONTOS
    glColor3f(0,5,2);
    circulos(10,raio,0.0);

    // TERCEIRO CIRCULO 30 PONTOS
    glColor3f(0,0,1);
    circulos(30,raio,espaco);

    glFlush(); //Força para rederizar
}
//========================================================



// função de redimensionamento da janela de visualização
static void resize(int width, int height){
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

// função para tratar os eventos do teclado
static void key(unsigned char key, int x, int y)
{
}
// função responsável por fazer as inicializações
void setup(void)
{
}

// Programa Principal
int main(int argc, char *argv[])
{

// utilizada para inicializar a biblioteca GLUT
    glutInit(&argc, argv);
// define do modo de operação da GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
// especifica o tamanho inicial em pixels da janela GLUT
    glutInitWindowSize(600, 400);
// especifica a posição inicial da janela GLUT
    glutInitWindowPosition(100, 100);
// cria a janela passando como título como argumento
    glutCreateWindow("circulos  7, 10, 30");

// registra a função callback de redesenho da janela de visualização
    glutDisplayFunc(display);
// registra a função callback para tratar os eventos do teclado
    glutKeyboardFunc(key);
// registra a função callback de redimensionamento da janela de visualização
    glutReshapeFunc(resize);
// chama a função responsável por fazer as inicializações
    setup();
// inicia o processamento e aguarda interações do usuário
    glutMainLoop();
    return 0;
}
