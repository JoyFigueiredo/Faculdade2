#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <cmath>
#include <string>
#include <iostream>

#include <SOIL/SOIL.h>


/* =============================================================================
 *                      VARIAVEIS
 * =============================================================================*/
float posicaoPaleta1 = 0.0f;
float posicaoPaleta2 = 0.0f;
float velocidadePaleta = 1;

float posicaoBola[3] = {0.0f, 0.0f, 0.0f};
float direcaoBola[3] = {0.02f, 0.02f, 0.0f};
float velocidadeBola = 1.0f;

int pontuacaoJogador1 = 0;
int pontuacaoJogador2 = 0;

float cameraRadius = 30.0f;
float cameraAngleX = 45.0f;
float cameraAngleY = 45.0f;

GLfloat luzX = 50.0;
GLfloat luzY = 250.0;
GLfloat luzZ = 1.0;

bool jogoPausado = true;
GLuint textureID;
unsigned char *image_in_RAM, image_in_RAM_bytes;

/* =============================================================================
 *                      TEXTURAS
 * =============================================================================*/



/* =============================================================================
 *                      PALETAS
 * =============================================================================*/
void paletas1(float x, float y, float z)
{
    glPushMatrix();
        glColor3f(1, 0, 0);
        //glScalef(1.0, 5.0, 1);
        glTranslatef(x, y, z);
        glutSolidCube(2.0);
    glPopMatrix();
}

void paletas2(float x, float y, float z)
{
    glPushMatrix();
        glColor3f(1, 0, 1);
        //glScalef(1.0, 5.0, 1);
        glTranslatef(x, y, z);
        glutSolidCube(2.0);
    glPopMatrix();
}

/* =============================================================================
 *                      BOLINHA
 * =============================================================================*/
void desenhaBola(float x, float y, float z)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glPushMatrix();
        glColor3f(1, 1, 1);
        glTranslatef(x, y, z);
        glutSolidSphere(1.0, 50, 50);
    glPopMatrix();

     glDisable(GL_TEXTURE_2D);
}

/* =============================================================================
 *                      PLATAFORMA
 * =============================================================================*/
void desenhaMeio()
{
    // Desenha uma linha tracejada no eixo Y
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(10, 0xAAAA); // Padrão de linha tracejada
    glBegin(GL_LINES);
    glVertex3f(0.0f, -20.0f, 0.0f);
    glVertex3f(0.0f, 20.0f, 0.0f);
    glEnd();
    glDisable(GL_LINE_STIPPLE);

    // Normais do plano (em direção à câmera)
    glNormal3f(0.0f, 0.0f, 1.0f);

    // Desenha a superfície do jogo (um plano)
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glVertex3f(-20.0f, -20.0f, -1);
    glVertex3f(20.0f, -20.0f, -1);
    glVertex3f(20.0f, 20.0f, -1);
    glVertex3f(-20.0f, 20.0f, -1);
    glEnd();
}

/* =============================================================================
 *                      PLACAR
 * =============================================================================*/
void desenharTexto(const char* texto, GLfloat x, GLfloat y, GLfloat z)
{
    glColor3f(1.0f, 1.0f, 1.0f);

    glRasterPos3f(x, y, z);

    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == '\n') {
            y -= 1.5f;
            glRasterPos3f(x, y, z);
        } else {

            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, texto[i]);
        }
    }
}

void exibirPlacar()
{

    std::string placar = std::to_string(pontuacaoJogador1);
    desenharTexto(placar.c_str(), -10.0f, -4.0f, 0.0f);

    std::string placar2 = std::to_string(pontuacaoJogador2);
    desenharTexto(placar2.c_str(), 10.0f, -4.0f, 0.0f);
}

/* =============================================================================
 *                      ATUALIZA TABULEIRO
 * =============================================================================*/
void atualiza()
{
//MOVIMENTAÇÃO DA BOLINHA
    if(!jogoPausado){
        posicaoBola[0] += direcaoBola[0] * velocidadeBola;
        posicaoBola[1] += direcaoBola[1] * velocidadeBola;

        if (posicaoBola[1] > 19.0f || posicaoBola[1] < -19.0f) {
            direcaoBola[1] = -direcaoBola[1];
        }

    }

//LIMITAR PALETAS (NÃO TA FUNCIONANDO)
    if (posicaoPaleta1 > 18.0f) {
        posicaoPaleta1 = 18.0f;
    } else if (posicaoPaleta1 < -18.0f) {
        posicaoPaleta1 = -18.0f;
    }

    if (posicaoPaleta2 > 18.0f) {
        posicaoPaleta2 = 18.0f;
    } else if (posicaoPaleta2 < -18.0f) {
        posicaoPaleta2 = -18.0f;
    }

// COLISÃO
    if (posicaoBola[0] + 1.0f > 14.0f && posicaoBola[0] - 1.0f < 16.0f) {
        if (posicaoBola[1] + 1.0f > posicaoPaleta2 - 1.0f && posicaoBola[1] - 1.0f < posicaoPaleta2 + 1.0f) {
            direcaoBola[0] = -direcaoBola[0];
        }
    }else if (posicaoBola[0] + 1.0f > -16.0f && posicaoBola[0] - 1.0f < -14.0f) {
        if (posicaoBola[1] + 1.0f > posicaoPaleta1 - 1.0f && posicaoBola[1] - 1.0f < posicaoPaleta1 + 1.0f) {
            direcaoBola[0] = -direcaoBola[0];
        }
    }

// PONTUAÇÃO
    if (posicaoBola[0] > 20.0f) {
        posicaoBola[0] = 0.0f;
        posicaoBola[1] = 0.0f;
        pontuacaoJogador1++;
    } else if (posicaoBola[0] < -20.0f) {
        posicaoBola[1] = 0.0f;
        posicaoBola[0] = 0.0f;
        pontuacaoJogador2++;
    }
}

/* =============================================================================
 *                      LUZ
 * =============================================================================*/
void luz(){
    // Definição das propriedades da luz ambiente
    GLfloat luzAmbiente[4]={0.2, 0.2, 0.2 ,1.0};
    // Definição das propriedades da luz difusa (cor)
    GLfloat luzDifusa[4]={0.8, 0.8, 0.8, 1.0};
    // Definição das propriedades da luz especular (brilho)
    GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};
    // Posição da fonte de luz
    GLfloat posicaoLuz[4]={0.0, luzX, luzY, luzZ};
    // Capacidade de brilho do material
    GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
    GLint especMaterial = 60;
    // Define a refletância do material
    glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
    // Define a concentração do brilho
    glMateriali(GL_FRONT,GL_SHININESS,especMaterial);
    // Ativa o uso da luz ambiente
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

    // Define os parâmetros da luz de número 0
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );
}

/* =============================================================================
 *                      DISPLAYS
 * =============================================================================*/


static void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    luz();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    float cameraX = cameraRadius * sin(cameraAngleX);
    float cameraY = cameraRadius * cos(cameraAngleX) * sin(cameraAngleY);
    float cameraZ = cameraRadius * cos(cameraAngleX) * cos(cameraAngleY);

    gluLookAt(cameraX, cameraY, cameraZ, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);

    glColor3f(1, 1, 1);
    desenhaMeio();

    paletas1(-15, posicaoPaleta1, 0);
    paletas2(15, posicaoPaleta2, 0);

    desenhaBola(posicaoBola[0], posicaoBola[1], posicaoBola[2]);

    exibirPlacar();


    glutSwapBuffers();
    atualiza();
    glutPostRedisplay();
}

/* =============================================================================
 *                      TECLAS
 * =============================================================================*/
static void key(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        exit(0);
        break;
    case 'w':
        posicaoPaleta1 += velocidadePaleta;
        break;
    case 'q':
        posicaoPaleta1 -= velocidadePaleta;
        break;
    case 'p':
        posicaoPaleta2 += velocidadePaleta;
        break;
    case 'o':
        posicaoPaleta2 -= velocidadePaleta;
        break;
    case 'i':
        cameraRadius -= 1.0f;
        break;
    case 'k':
        cameraRadius += 1.0f;
        break;
    case 'z':
        velocidadeBola +=0.5;
        break;
    case 'x':
        velocidadeBola -= 0.5;
        break;
    }

    glutPostRedisplay();
}

static void specialkey(int key, int x, int y)
{
    switch (key) {
    case GLUT_KEY_UP:
        cameraAngleX += 0.1f;
        break;
    case GLUT_KEY_DOWN:
        cameraAngleX -= 0.1f;
        break;
    case GLUT_KEY_LEFT:
        cameraAngleY -= 0.1f;
        break;
    case GLUT_KEY_RIGHT:
        cameraAngleY += 0.1f;
        break;
    case GLUT_KEY_F1:
        jogoPausado = false;
        break;
    case GLUT_KEY_F2:
        posicaoBola[0] = 0.0f;
        posicaoBola[1] = 0.0f;
        posicaoPaleta1 = 0.0f;
        posicaoPaleta2 = 0.0f;
        pontuacaoJogador1 = 0;
        pontuacaoJogador2 = 0;
        jogoPausado = true;
        break;
    }

    glutPostRedisplay();
}


/* =============================================================================
 *                      INICIALIZAÇÃO
 * =============================================================================*/
void setup(void)
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0, 1.0, 1.0, 100.0);
    // Habilita a definição da cor do material a partir da cor corrente
    glEnable(GL_COLOR_MATERIAL);
    //Habilita o uso de iluminação
    glEnable(GL_LIGHTING);
    // Habilita a luz de número 0
    glEnable(GL_LIGHT0);
    // Habilita o modelo de colorização de Gouraud
    glShadeModel(GL_SMOOTH);

}

// Função principal
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Trabalho Pratico Pong 3D");

    system("cls");

    // Imprime a legenda no console
    std::cout   << "Controles:\n"
                <<"Jogador 1: \n"
                << "Q e W para mover paleta. \n"
                <<"\n"
                <<"Jogador 2: \n"
                << "O e P para mover paleta. \n"
                <<"\n"
                <<"JOGO: \n"
                <<"F1: Inicia o Jogo. \n"
                <<"F2: Reseta. \n"
                <<"\n"
                <<"CAMERA: \n"
                << "I: Aproximar a câmera\n"
                << "K: Afastar a câmera\n"
                << "Setas direcionais: Controlar a orientação da câmera\n"
                << "Esc: Sair do jogo\n";

    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutSpecialFunc(specialkey);
    setup();
    glutMainLoop();

    return 0;
}
