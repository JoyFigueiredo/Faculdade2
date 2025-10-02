#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>


// fun��o de redesenho da janela de visualiza��o
static void display(){

    //Limpa tmb o eixo Z
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(0.0f, 0.0f, 1.0f);

    // Fun��o da GLUT para fazer o desenho de um cubo com a cor corrente
	glutWireCube(50);

	glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    // utilizada para inicializar a biblioteca GLUT
    glutInit(&argc, argv);

    // define do modo de opera��o da GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // especifica o tamanho inicial em pixels da janela GLUT
    glutInitWindowSize(800, 800);

    // especifica a posi��o inicial da janela GLUT
    glutInitWindowPosition(100, 100);

    // cria a janela passando como t�tulo como argumento
    glutCreateWindow("Trabalho Pratico Tangram");

    // registra a fun��o callback de redesenho da janela de visualiza��o
    glutDisplayFunc(display);

    // registra a fun��o callback para tratar os eventos do teclado
    glutKeyboardFunc(key);

    // registra a fun��o callback de redimensionamento da janela de visualiza��o
    glutReshapeFunc(resize);

    // Registra a fun��o callback para tratamento das teclas Especiais
    glutSpecialFunc(specialkey);

    // chama a fun��o respons�vel por fazer as inicializa��es
    setup();

    // inicia o processamento e aguarda intera��es do usu�rio
    glutMainLoop();

    return 0;
}
