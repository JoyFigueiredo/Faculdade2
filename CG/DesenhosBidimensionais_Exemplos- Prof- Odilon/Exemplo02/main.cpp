#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

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

// função de redesenho da janela de visualização
static void display(){
   // especifica que a cor corrente: preto
     glColor3f(0.0f, 0.0f, 0.0f);
     // limpa a janela de visualização com a cor de fundo especificada
     glClear(GL_COLOR_BUFFER_BIT);

    // aumenta a espessura das linhas
    glLineWidth(2.0f);

    // Desenha duas linhas para representar os eixos X e Y
    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 0.0f); //amarelo em RGB
        glVertex2i(0, 40); // linha do eixo Y
        glVertex2i(0, -40);
        glVertex2i(-40, 0);// linha do eixo X
        glVertex2i(40, 0);
    glEnd();

    // Desenha um quadrado
    glBegin(GL_LINE_LOOP);
        glColor3f(1.0f, 0.0f, 0.0f); // vermelho em RGB
        glVertex2i(-20, 20);
        glVertex2i(-20, -20);
        glVertex2i(20, -20);
        glVertex2i(20, 20);
    glEnd();

	// Executa os comandos OpenGL
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
	glutCreateWindow("Exemplo 02");

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
