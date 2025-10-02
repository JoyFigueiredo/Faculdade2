#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>


// função de redesenho da janela de visualização
static void display(){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(0.0f, 0.0f, 1.0f);

    // Função da GLUT para fazer o desenho de um cubo com a cor corrente
	glutWireCube(50);

	glutSwapBuffers();
}


// função para tratar os eventos do teclado
static void key(unsigned char key, int x, int y){
	if (key == 27)
		exit(0);
}


// função de redimensionamento da janela de visualização
static void resize(int width, int height){
    // Para previnir uma divisão por zero
	if ( height == 0 ) height= 1;

	// Especifica as dimensães da viewport
	glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Especifica a projeção paralela ortogrofica
	// (esquerda, direita, inferior, superior,
	// plano frontal, plano traseiro)
	glOrtho(-65.0, 65.0, -65.0, 65.0, -400.0, 400.0);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);

	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// Especifica posição do observador e do alvo
	gluLookAt(40, 60, 100, 0, 0, 0, 0, 1, 0);
}


// função responsável por fazer as inicializações
void setup(void){
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);

    glViewport(0, 0, 500, 500);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

}

// Programa Principal
int main(int argc, char *argv[]){
    // utilizada para inicializar a biblioteca GLUT
    glutInit(&argc, argv);

	// define do modo de operação da GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	// especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(450, 450);

    // especifica a posição inicial da janela GLUT
	glutInitWindowPosition(100, 100);

	// cria a janela passando como título como argumento
	glutCreateWindow("Projeto 02");

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

