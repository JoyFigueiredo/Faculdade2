
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <cmath> //Biblioteca das funçoes matematicas

#endif

//variáveis para controle da translação
GLfloat posicaoX=0, posicaoY=0;
//variável para controle da escala
GLfloat escala = 1;
GLfloat angulo= 0;

// função de redimensionamento da janela de visualização
static void resize(int width, int height)
{

    // Especifica as dimensões da Viewport
    glViewport(0, 0, width, height);

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Estabelece a janela de seleção (esquerda, direita, inferior,
    // superior) mantendo a proporção com a janela de visualização
    if (width <= height)
        gluOrtho2D (-40.0f, 40.0f, -40.0f*height/width, 40.0f*height/width);
    else
        gluOrtho2D (-40.0f*width/height, 40.0f*width/height, -40.0f, 40.0f);
}

void circulos(){
    float raio = 5;
    glBegin(GL_POLYGON); // modo desenho dos pontos iniciada
    for(int i=0; i< 10; i++ ){
        float angulo = 2 * 3.14* i / 10; // 2 pi i/numPontos
        float x = raio* cos(angulo);
        float y = raio * sin(angulo);
        glVertex2f(x,y);
    }
    glEnd();
}

void quadrado(){
    glBegin(GL_QUADS); // modo desenho dos pontos iniciada
        glVertex2f(-6,-6);
        glVertex2f(6,-6);
        glVertex2f(6,6);
        glVertex2f(-6,6);
    glEnd();
}

// função de redesenho da janela de visualização
static void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    glPushMatrix();
        //CIRCULO
        glColor3f(0, 0, 1);
        glScalef(posicaoX+escala,posicaoY+escala,0);
        glRotatef(angulo,0,0,1);
        circulos();
    glPopMatrix();

    glTranslated(posicaoX, posicaoY,0);

    glPushMatrix();
        //QUADRADO 1
        glColor3f(0, 1, 0);

        glScalef(posicaoX+escala,posicaoY+escala,0);
        glTranslatef(23 ,23, 0.0f);
        quadrado();
    glPopMatrix();

    glPushMatrix();
        //QUADRADO 2
        glColor3f(1, 0, 0);

        glScalef(posicaoX+escala,posicaoY+escala,0);
        glTranslatef(-23 ,23, 0.0f);
        quadrado();
    glPopMatrix();

    glPushMatrix();
        //QUADRADO 3
        glColor3f(1, 1, 0);

        glScalef(posicaoX+escala,posicaoY+escala,0);
        glTranslatef(23 ,-23, 0.0f);
        quadrado();
    glPopMatrix();

    glPushMatrix();
        //QUADRADO 4
        glColor3f(0, 1, 1);
        glScalef(posicaoX+escala,posicaoY+escala,0);
        glTranslatef(-23 ,-23, 0.0f);
        quadrado();
    glPopMatrix();

/*
    // Aplica uma translação sobre o objeto
    glTranslatef(posicaoX, posicaoY, 0.0f);

    // Aplica uma escala sobre o objeto
    glScalef(escala, escala, 1.0f);

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f( 5.0f, -5.0f);
    glVertex2f( 5.0f,  5.0f);
    glVertex2f(-5.0f,  5.0f);
    glVertex2f(-5.0f, -5.0f);
    glEnd();

*/


    glFlush();
}

// função para tratar os eventos do teclado
static void key(unsigned char key, int x, int y)
{
    if (key == 27)
        exit(0);
}

// função para tratar os eventos do teclado para teclas Especiais
static void specialkey(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        posicaoX--;
        angulo = angulo + 45;
        break;
    case GLUT_KEY_RIGHT:
        posicaoX++;
        angulo = angulo - 45;
        break;
    case GLUT_KEY_UP:
        posicaoY++;
        angulo = angulo - 45;
        break;
    case GLUT_KEY_DOWN:
        posicaoY--;
        angulo = angulo + 45;
        break;
    case GLUT_KEY_HOME:
        escala += 0.3;
        break;
    case GLUT_KEY_END:
        escala -= 0.3;
        break;
    }

    display();
}

// função responsável por fazer as inicializações
void setup(void)
{

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    glViewport(0, 0, 400, 400);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D (-40.0f, 40.0f, -40.0f, 40.0f);
}

// Programa Principal
int main(int argc, char *argv[])
{
    // utilizada para inicializar a biblioteca GLUT
    glutInit(&argc, argv);

    // define do modo de operação da GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // especifica o tamanho inicial em pixels da janela GLUT
    glutInitWindowSize(400, 400);

    // especifica a posição inicial da janela GLUT
    glutInitWindowPosition(100, 100);

    // cria a janela passando como título como argumento
    glutCreateWindow("Projeto 03");

    // registra a função callback de redesenho da janela de visualização
    glutDisplayFunc(display);

    // registra a função callback para tratar os eventos do teclado
    glutKeyboardFunc(key);

    // registra a função callback de redimensionamento da janela de visualização
    glutReshapeFunc(resize);

    // Registra a função callback para tratamento das teclas Especiais
    glutSpecialFunc(specialkey);

    // chama a função responsável por fazer as inicializações
    setup();

    // inicia o processamento e aguarda interações do usuário
    glutMainLoop();

    return 0;
}
