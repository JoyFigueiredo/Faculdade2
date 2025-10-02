#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

//variáveis globais
GLsizei auxWidth, auxHeight;

// função de redimensionamento da janela de visualização
static void resize(int width, int height){
    //glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;

    //variáveis globais
	auxWidth = width;
	auxHeight = height;

    // estabelece a janela de seleção (esquerda, direita, inferior,
    // superior) mantendo a proporção com a janela de visualizão
    if (width <= height)
        gluOrtho2D (-40.0f, 40.0f, -40.0f*height/width, 40.0f*height/width);
    else
        gluOrtho2D (-40.0f*width/height, 40.0f*width/height, -40.0f, 40.0f);
}

void desenharQuadrado(void){
     glBegin(GL_QUADS);
       glVertex2i(-40, 40);
       glVertex2i(-40, -40);
       glVertex2i(40, -40);
       glVertex2i(40, 40);
     glEnd();
}

// função de redesenho da janela de visualização
static void display(){
   // especifica que a cor corrente: preto
     glColor3f(0.0f, 0.0f, 0.0f);
     // limpa a janela de visualização com a cor de fundo especificada
     glClear(GL_COLOR_BUFFER_BIT);

    glViewport(0, 0, auxWidth/2, auxHeight/2);
    glColor3f(1.0f, 0.0f, 0.0f); // vermelho
    desenharQuadrado();

    glViewport(auxWidth/2, 0, auxWidth/2, auxHeight/2);
    glColor3f(0.0f, 1.0f, 0.0f); // verde
    desenharQuadrado();

    glViewport(auxWidth/2, auxHeight/2, auxWidth/2, auxHeight/2);
    glColor3f(0.0f, 0.0f, 1.0f); // azul
    desenharQuadrado();

    glViewport(0, auxHeight/2, auxWidth/2, auxHeight/2);
    glColor3f(1.0f, 1.0f, 0.0f); // amarelo
    desenharQuadrado();

	// executa os comandos OpenGL
	glFlush();
}

// função para tratar os eventos do teclado
static void key(unsigned char key, int x, int y){
	if (key == 27)
		exit(0);
}

// função responsável por fazer as inicializações
void setup(void){
}

// Programa Principal
int main(int argc, char *argv[]){
    // utilizada para inicializar a biblioteca GLUT
    glutInit(&argc, argv);

	// define do modo de operação da GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(400, 400);

    // especifica a posição inicial da janela GLUT
	glutInitWindowPosition(100, 100);

	// cria a janela passando como título como argumento
	glutCreateWindow("Exemplo 03");

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
