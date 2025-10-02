#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>

GLboolean superficie;
GLboolean eixos;
GLboolean cubo;
GLfloat anguloVisao, fAspect;
GLfloat eyeX, eyeY, eyeZ;

GLUquadric *quad;

void desenharEixos()
{

    float tamanho = 500.0;

    glBegin(GL_LINES);
    //eixo X
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-tamanho, 0, 0);
    glVertex3f( tamanho, 0, 0);

    //eixo Y
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0, -tamanho, 0);
    glVertex3f(0,  tamanho, 0);

    //eixo Z
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0, 0, -tamanho);
    glVertex3f(0, 0,  tamanho);
    glEnd();
}

// função de redesenho da janela de visualização
static void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(eixos)
    {
        desenharEixos();
    }

    if(cubo)
    {
        glPushMatrix();
            glColor3f(0.3f, 0.8f, 0.5f);
            glTranslated(0, 50, 0);
            gluQuadricTexture(quad,1);
            gluSphere(quad,20,20,20);
        glPopMatrix();

    glPushMatrix();
        glColor3f(0.2f, 0.9f, 0.7f);
        glTranslated(20,0,0);
        gluSphere(quad,10,20,20);
    glPopMatrix();
       // glutWireTeapot(40.0f);//xicara
    }

    glutSwapBuffers();
}



// função para tratar os eventos do teclado
static void key(unsigned char key, int x, int y)
{
    if (key == 27)
        exit(0);

    switch (key)
    {
    case 'a':
    case 'A':
        eixos = !eixos;
        glutPostRedisplay();
        break;
    case 'S':
    case 's':
        superficie = !superficie;
        glutPostRedisplay();
        break;
    case 'C':
    case 'c':
        cubo = !cubo;
        glutPostRedisplay();
        break;
    }
}

//Função criada para definir os parametros de visualização
void definirVisualizacao()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(anguloVisao, fAspect, 0.5, 500);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(eyeX, eyeY, eyeZ, 0, 0, 0, 0, 1, 0);
}

// Função callback chamada quando s�o notificados os eventos do mouse
void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
        if (state == GLUT_DOWN)    // zoom in
        {
            if (anguloVisao >= 10) anguloVisao -= 5;
        }
    if (button == GLUT_RIGHT_BUTTON)
        if (state == GLUT_DOWN)    // zoom out
        {
            if (anguloVisao <= 150) anguloVisao += 5;
        }
    definirVisualizacao();
    glutPostRedisplay();
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
    quad = gluNewQuadric();

    definirVisualizacao();
}

// fun��o para tratar os eventos do teclado para teclas Especiais
static void specialkey(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:		// desloca o volume de visualização para cima
        eyeY -= 2;
        break;
    case GLUT_KEY_DOWN:		// desloca o volume de visualização para baixo
        eyeY += 2;
        break;
    case GLUT_KEY_LEFT:		// desloca o volume de visualização para o lado esquerdo
        eyeX += 2;
        break;
    case GLUT_KEY_RIGHT:	// desloca o volume de visualização para o lado direito
        eyeX -= 2;
        break;
    case GLUT_KEY_PAGE_UP:	// desloca o volume de visualização para frente
        eyeZ -= 2;
        break;
    case GLUT_KEY_PAGE_DOWN:// desloca o volume de visualização para tras
        eyeZ += 2;
        break;
    }

    definirVisualizacao();
    glutPostRedisplay();
}

// função responsável por fazer as inicializações
void setup(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    glViewport(0, 0, 500, 500);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    superficie = true;
    eixos = true;
    cubo = true;

    anguloVisao = 90;

    eyeX = 30.0;
    eyeY = 100.0;
    eyeZ = 150.0;
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
    glutCreateWindow("Trabalho");

    // registra a função callback de redesenho da janela de visualização
    glutDisplayFunc(display);

    // registra a função callback para tratar os eventos do teclado
    glutKeyboardFunc(key);

    // Registra a função callback que gerencia os eventos do mouse
    glutMouseFunc(mouse);

    // Registra a função callback para tratamento das teclas especiais
    glutSpecialFunc(specialkey);

    // registra a função callback de redimensionamento da janela de visualização
    glutReshapeFunc(resize);

    // chama a função responsável por fazer as inicializações
    setup();

    // inicia o processamento e aguarda interações do usuário
    glutMainLoop();

    return 0;
}

