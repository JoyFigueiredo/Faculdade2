#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>


// função de redesenho da janela de visualização
static void display(){

    //Limpa tmb o eixo Z
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(0.0f, 0.0f, 1.0f);

    // Função da GLUT para fazer o desenho de um cubo com a cor corrente
	glutWireCube(50);

	glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    // utilizada para inicializar a biblioteca GLUT
    glutInit(&argc, argv);

    // define do modo de operação da GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // especifica o tamanho inicial em pixels da janela GLUT
    glutInitWindowSize(800, 800);

    // especifica a posição inicial da janela GLUT
    glutInitWindowPosition(100, 100);

    // cria a janela passando como título como argumento
    glutCreateWindow("Trabalho Pratico Tangram");

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
