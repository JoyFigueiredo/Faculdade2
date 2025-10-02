#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>


//variáveis para controle da translação
GLfloat posicaoX=0, posicaoY=0;
GLfloat escala = 0.5;
GLfloat angulo = 0;

//Triangulo GRANDE1
GLfloat posicaoX1=0, posicaoY1=0;
GLfloat angulo1 = 0;

//Triangulo GRANDE2
GLfloat posicaoX2=0, posicaoY2=0;
GLfloat angulo2 = 0;

//Triangulo Medio2
GLfloat posicaoX3=0, posicaoY3=0;
GLfloat angulo3 = 0;

//Triangulo pequeno1
GLfloat posicaoX4=0, posicaoY4=0;
GLfloat angulo4 = 0;

//Triangulo pequeno2
GLfloat posicaoX5=0, posicaoY5=0;
GLfloat angulo5 = 0;

//Quadrado
GLfloat posicaoX6=0, posicaoY6=0;
GLfloat angulo6 = 0;

//Paralelogramo
GLfloat posicaoX7=0, posicaoY7=0;
GLfloat angulo7 = 0;

int peca = 0;
int aux = 0;
int invert = 1;

/*
*=============================================================
*               Funçao Reset
*=============================================================
*/
void resetTransformations() {
//variáveis para controle da translação
 posicaoX=0, posicaoY=0;
 escala = 0.5;
 angulo = 0;

//Triangulo GRANDE1
 posicaoX1=0, posicaoY1=0;
 angulo1 = 0;

//Triangulo GRANDE2
 posicaoX2=0, posicaoY2=0;
 angulo2 = 0;

//Triangulo Medio2
posicaoX3=0, posicaoY3=0;
angulo3 = 0;

//Triangulo pequeno1
posicaoX4=0, posicaoY4=0;
angulo4 = 0;

//Triangulo pequeno2
posicaoX5=0, posicaoY5=0;
angulo5 = 0;

//Quadrado
 posicaoX6=0, posicaoY6=0;
 angulo6 = 0;

//Paralelogramo
 posicaoX7=0, posicaoY7=0;
 angulo7 = 0;
}

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

/*
*=============================================================
*               Formas Geometricas
*=============================================================
*/
void quadrado()
{
    glBegin(GL_QUADS); // modo desenho dos pontos iniciada
    glVertex2f(-20,-20);
    glVertex2f(20,-20);
    glVertex2f(20,20);
    glVertex2f(-20,20);
    glEnd();
}

void paralelogramo()
{
    glBegin(GL_POLYGON); // modo desenho dos pontos iniciada
    glVertex2f(-10, -10); //A
    glVertex2f(30, -10); //B
    glVertex2f(10, 10); //C
    glVertex2f(-30, 10); //D
    glEnd();
}

void triangulo()
{
    glBegin(GL_TRIANGLES); // modo desenho dos pontos iniciada
    glVertex2f(-20,-20);
    glVertex2f(0,0);
    glVertex2f(-20,20);
    glEnd();
}


void quadradoPrincipal()
{
    glBegin(GL_LINE_LOOP); // modo desenho dos pontos iniciada
    glVertex2f(-20,-20);
    glVertex2f(20,-20);
    glVertex2f(20,20);
    glVertex2f(-20,20);
    glEnd();
}
/*
*=============================================================
*/

/*
*=============================================================
*               LEGENDA
*=============================================================
*/

void desenharTexto(const char* texto, GLfloat x, GLfloat y) {
    // Define a cor do texto (branco)
    glColor3f(1.0f, 1.0f, 1.0f);

    // Posiciona o texto no local desejado
    glRasterPos2f(x, y);

    // Loop para desenhar cada caractere do texto
    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == '\n') {
            // Se encontrar '\n', mova para a próxima linha
            y -= 1.5f; // Você pode ajustar a quantidade de espaço vertical entre as linhas
            glRasterPos2f(x, y);
        } else {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, texto[i]);
        }
    }
}

/*
*=============================================================
*/

static void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    desenharTexto("Legenda Pressione:"
                "\n  'a' = movimentar"
                "\n  'b' = girar peça "
                "\n  'i' = Inverte peca 7 \n(precisa pressionar 7 antes de inverter)"
                "\n  '1' = Peca Azul escura"
                "\n  '2' = Peca Verde "
                "\n  '3' = Peca Azul Clara"
                "\n  '4' = Peca Vermelha "
                "\n  '5' = Peca Rosa"
                "\n  '6' = Peca Amarela "
                "\n  '7' = Peca Branca "
                "\n \n 'F1' = RESETAR"
                  , -38.0f, 38.0f);

    switch (peca){
    case 1:
        posicaoX1 = posicaoX1+ posicaoX;
        angulo1 =angulo1+ angulo;
        posicaoY1 = posicaoY1+ posicaoY;
        break;
    case 2:
        posicaoX2 =posicaoX2+ posicaoX;
        angulo2 =angulo2+ angulo;
        posicaoY2 = posicaoY2+ posicaoY;
        break;
    case 3:
        posicaoX3 = posicaoX3+ posicaoX;
        angulo3 =angulo3+ angulo;
        posicaoY3 =posicaoY3+ posicaoY;
        break;
    case 4:
        posicaoX4 =posicaoX4+ posicaoX;
        angulo4 =angulo4+ angulo;
        posicaoY4 =posicaoY4+ posicaoY;
        break;
    case 5:
        posicaoX5 =posicaoX5+ posicaoX;
        angulo5 =angulo5+ angulo;
        posicaoY5 =posicaoY5+ posicaoY;
        break;
    case 6:
        posicaoX6 =posicaoX6+ posicaoX;
        angulo6 =angulo6+ angulo;
        posicaoY6 =posicaoY6+ posicaoY;
        break;
    case 7:
        posicaoX7 = posicaoX7+ posicaoX;
        angulo7 =angulo7+ angulo;
        posicaoY7 =posicaoY7+ posicaoY;
    break;
    }
/*
*=============================================================
*               DESENHA
*=============================================================
*/
        glPushMatrix();
            //Triangulo GRANDE1
            glColor3f(0, 0, 1);
            glTranslated(posicaoX1, posicaoY1,0);
            glScalef(escala, escala, 0);
            glTranslatef(0.0f ,0.0f, 0.0f);
            glRotatef(0.0f+angulo1, 0.0f, 0.0f, 1.0f);
            glScalef(1,1,0);
            triangulo();
        glPopMatrix();

        glPushMatrix();
            //Triangulo GRANDE2
            glColor3f(0, 1, 0);
            glTranslated(posicaoX2, posicaoY2,0);
            glTranslatef(0.0f ,0.0f, 0.0f);
            glScalef(escala, escala, 0);
            glRotatef(-90.0f+angulo2, 0.0f, 0.0f, 1.0f);
            glScalef(1,1,0);
            triangulo();
        glPopMatrix();

        glPushMatrix();
            //Triangulo Medio2
            glColor3f(0, 1, 1);
            glTranslated(posicaoX3, posicaoY3,0);
            glScalef(escala, escala, 0);
            glTranslatef(20.0f ,-20.0f, 0.0f);
            glScalef(1*0.72,1*0.72,0);
            glRotatef(-225.0f + angulo3, 0.0f, 0.0f, 1.0f);
             glScalef(-1.0f, 1.0f, 1.0f);

            triangulo();
        glPopMatrix();


        glPushMatrix();
            //Triangulo pequeno1
            glColor3f(1, 0, 0);
            glTranslated(posicaoX4, posicaoY4,0);
            glScalef(escala, escala, 0);
            glTranslatef(-10.0f  ,-10.0f, 0.0f);
            glScalef(1*0.5,1*0.5,0);
            glRotatef(angulo4+90.0f, 0.0f, 0.0f, 1.0f);
            triangulo();
        glPopMatrix();

        glPushMatrix();
            //Triangulo pequeno2
            glColor3f(1, 0, 1);
            glTranslated(posicaoX5, posicaoY5,0);
            glScalef(escala, escala, 0);
            glTranslatef(0.0f ,0.0f, 0.0f);
            glRotatef(angulo5+180.0f, 0.0f, 0.0f, 1.0f);
            glScalef(1*0.5,1*0.5,0);
            triangulo();
        glPopMatrix();

        glPushMatrix();
            //Quadrado
            glColor3f(1, 1, 0);
            glTranslated(posicaoX6, posicaoY6,0);
            glScalef(escala, escala, 0);
            glTranslatef(0.0f ,-10.0f, 0.0f);
            glScalef(1*0.35,1*0.35,0);
            glRotatef(angulo6+45.0f, 0.0f, 0.0f, 1.0f);
            quadrado();
        glPopMatrix();

        glPushMatrix();
            //Paralelogramo
            glColor3f(1, 1, 1);
            glTranslated(posicaoX7, posicaoY7,0);
            glScalef(escala, escala, 0);
            glScalef(1*0.5,1*0.5,0);
            glTranslatef(30.0f ,10.0f, 0.0f);
            glRotatef(angulo7+90.0f, 0.0f, 0.0f, 1.0f);
            glScalef(1.0f * invert, 1.0f, 1.0f);
            paralelogramo();
        glPopMatrix();

    glFlush();

}

static void key(unsigned char key, int x, int y)
{
    if (key == 27){
        exit(0);
    }else if(key == 'a'){
        aux = 0;
    }else if(key == 'b'){
        aux = 1;
    }else if(key == '1'){
        peca=1;
    }else if(key == '2'){
        peca=2;
    }else if(key == '3'){
        peca=3;
    }else if(key == '4'){
        peca=4;
    }else if(key == '5'){
        peca=5;
    }else if(key == '6'){
        peca=6;
    }else if(key == '7'){
        peca=7;
    }else if(key == 'i' && peca == 7){
        if(invert == 1){
            invert = -1;
        }else{
            invert = 1;
        }
    }
}

// função para tratar os eventos do teclado para teclas Especiais
static void specialkey(int key, int x, int y)
{
    switch (key){
    case GLUT_KEY_LEFT:
        if(aux ==0){
            posicaoX= -1;
            posicaoY=0;
            angulo =0;
        }else{
            angulo = + 45;
            posicaoX=0;
            posicaoY=0;
        }
        break;
    case GLUT_KEY_RIGHT:
        if(aux ==0){
            posicaoX= +1;
            posicaoY=0;
            angulo=0;
        }else{
            angulo =- 45;
            posicaoX=0;
            posicaoY=0;
        }
        break;
    case GLUT_KEY_UP:
        if(aux ==0){
            posicaoY= +1;
            posicaoX=0;
            angulo=0;
        }else{
            angulo =-45;
            posicaoX=0;
            posicaoY=0;
        }
        break;
    case GLUT_KEY_DOWN:
        if(aux ==0){
            posicaoY=-1;
            posicaoX= 0;
            angulo=0;
        }else if(aux==1){
            angulo = + 45;
            posicaoX=0;
            posicaoY=0;
        }
        break;
    case GLUT_KEY_HOME:
        escala += 0.3;
        break;
    case GLUT_KEY_END:
        escala -= 0.3;
        break;
    case GLUT_KEY_F1:
        resetTransformations();
        peca =0;
        break;
    }
    display();
}

void setup(void)
{

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    glViewport(0, 0, 400, 400);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D (-40.0f, 40.0f, -40.0f, 40.0f);
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
