#include <GL/glut.h>
#include <stdio.h>

float vertices[100000][3];
int faces[100000][4][3];  // Assuming quads and each vertex has 3 coordinates (x, y, z)
int numVertices = 0;
int numFaces = 0;

void loadObj(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    while (1) {
        char lineHeader[23294];
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF) break; // EOF = End Of File. Quit the loop.

        if (strcmp(lineHeader, "v") == 0) {
            fscanf(file, "%f %f %f\n", &vertices[numVertices][0], &vertices[numVertices][1], &vertices[numVertices][2]);
            numVertices++;
        } else if (strcmp(lineHeader, "f") == 0) {
            fscanf(file, "%d//%d %d//%d %d//%d %d//%d\n",
                   &faces[numFaces][0][0], &faces[numFaces][1][0],
                   &faces[numFaces][2][0], &faces[numFaces][3][0],
                   &faces[numFaces][0][1], &faces[numFaces][1][1],
                   &faces[numFaces][2][1], &faces[numFaces][3][1]);
            numFaces++;
        }
    }

    fclose(file);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_QUADS);
    for (int i = 0; i < numFaces; i++) {
        for (int j = 0; j < 4; j++) {
            int vertexIndex = faces[i][j][0] - 1;
            glVertex3f(vertices[vertexIndex][0], vertices[vertexIndex][1], vertices[vertexIndex][2]);
        }
    }
    glEnd();

    glutSwapBuffers();
}

void initialize() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("OBJ Viewer");

    glEnable(GL_DEPTH_TEST);
    initialize();
    loadObj("D:/Faculdade/CG/teste/obj/House.obj");

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
