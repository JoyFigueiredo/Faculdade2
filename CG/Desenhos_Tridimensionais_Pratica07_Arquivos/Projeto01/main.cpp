#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>

GLfloat tam = 500;
GLfloat tamEsp = 25;
GLfloat posicaoX = 0;
GLfloat posicaoZ = 0;

/* ===================================================
                Variaveis para camera
   ===================================================  */

GLfloat fAspect;
GLfloat camX = 40;
GLfloat camY = 60;
GLfloat camZ = 100;

int peca = 0;

static void chao()
{
    for(int i = -tam; i <= tam; i+=tamEsp)
    {
        glBegin(GL_LINES);
        //vertical
        glVertex3d(i,0.1,-tam);
        glVertex3d(i,0.1,tam);
        //Horizontal
        glVertex3d(tam,0.1,i);
        glVertex3d(-tam,0.1,i);
        glEnd();
    }
}

void desenharCubo(GLfloat tamanho)
{
//anterior - vermelho
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-tamanho, tamanho, tamanho);
    glVertex3f(-tamanho, -tamanho, tamanho);
    glVertex3f( tamanho, -tamanho, tamanho);
    glVertex3f( tamanho, tamanho, tamanho);
    glEnd();
//lateral esquerda - azul
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex3f( tamanho, tamanho, tamanho);
    glVertex3f( tamanho, -tamanho, tamanho);
    glVertex3f( tamanho, -tamanho, -tamanho);
    glVertex3f( tamanho, tamanho, -tamanho);
    glEnd();
//posterior - amarelo
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f( tamanho, tamanho, -tamanho);
    glVertex3f(-tamanho, tamanho, -tamanho);
    glVertex3f(-tamanho, -tamanho, -tamanho);
    glVertex3f( tamanho, -tamanho, -tamanho);
    glEnd();
//lateral direita - verde
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-tamanho, tamanho, tamanho);
    glVertex3f(-tamanho, tamanho, -tamanho);
    glVertex3f(-tamanho, -tamanho, -tamanho);
    glVertex3f(-tamanho, -tamanho, tamanho);
    glEnd();
//superior - laranja
    glColor3f(1.0f, 0.5f, 0.2f);
    glBegin(GL_QUADS);
    glVertex3f(-tamanho, tamanho, tamanho);
    glVertex3f( tamanho, tamanho, tamanho);
    glVertex3f( tamanho, tamanho, -tamanho);
    glVertex3f(-tamanho, tamanho, -tamanho);
    glEnd();
//inferior - roxo
    glColor3f(0.5f, 0.2f, 0.8f);
    glBegin(GL_QUADS);
    glVertex3f(-tamanho, -tamanho, tamanho);
    glVertex3f(-tamanho, -tamanho, -tamanho);
    glVertex3f( tamanho, -tamanho, -tamanho);
    glVertex3f( tamanho, -tamanho, tamanho);
    glEnd();
}


static void definirVisualizacao()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(90, fAspect, 0.5, 500);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(camX, camY, camZ, 0, 0, 0, 0, 1, 0);
}


// função de redesenho da janela de visualização
static void display()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 1.0f);

    glPushMatrix();
        glColor3f(0, 1, 1);
        glTranslated(0,-25,0);
        chao();
    glPopMatrix();

    glPushMatrix();
        glColor3f(1, 0, 0);
        glRotated(posicaoX,0,1,0);
        desenharCubo(20);
    glPopMatrix();

    glPushMatrix();
        glRotated(posicaoX,0,1,0);
        glTranslated(50,0,0);
        glColor3f(0, 0, 0.5);
        glutSolidSphere(10,50,50);
    glPopMatrix();

    glutSwapBuffers();
}

static void specialkey(int key, int x, int y)
{
    switch (key){
    case GLUT_KEY_LEFT:
        posicaoX --;
        posicaoZ ++;
        break;
    case GLUT_KEY_RIGHT:
        posicaoX ++;
        posicaoZ --;
        break;
        case GLUT_KEY_UP:
         if(peca == 1){
            camX ++;
        }else if(peca == 2){
            camY ++;
        }else if(peca == 3){
            camZ ++;
        }
        definirVisualizacao();
        break;
    case GLUT_KEY_DOWN:
        if(peca == 1){
            camX --;
        }else if(peca == 2){
            camY --;
        }else if(peca == 3){
            camZ --;
        }
        definirVisualizacao();
        break;
    }
    display();
}

// função para tratar os eventos do teclado
static void key(unsigned char key, int x, int y)
{if (key == 27){
        exit(0);
    }else if(key == 'x'){
        peca = 1;
    }else if(key == 'y'){
        peca = 2;
    }else if(key == 'z'){
        peca = 3;
    }
}

// função de redimensionamento da janela de visualização
static void resize(int width, int height)
{
    // Para previnir uma divisão por zero
    if ( height == 0 ) height= 1;

    // Especifica as dimensães da viewport
    glViewport(0, 0, width, height);

    // Calcula a correção de aspecto
    fAspect = (GLfloat)width/(GLfloat)height;

    definirVisualizacao();
}


// função responsável por fazer as inicializações
void setup(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    glViewport(0, 0, 500, 500);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

// Programa Principal
int main(int argc, char *argv[])
{
    // utilizada para inicializar a biblioteca GLUT
    glutInit(&argc, argv);

    // define do modo de operação da GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    // especifica o tamanho inicial em pixels da janela GLUT
    glutInitWindowSize(500, 500);

    // especifica a posição inicial da janela GLUT
    glutInitWindowPosition(100, 100);

    // cria a janela passando como título como argumento
    glutCreateWindow("Projeto 01");

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

