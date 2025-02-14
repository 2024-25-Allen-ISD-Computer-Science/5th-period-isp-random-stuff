#include <GL/glut.h>
#include <stdio.h>

float buttonX1 = 100, buttonY1 = 100; // defining size
float buttonX2 = 300, buttonY2 = 200;

void drawButton() {
    glColor3f(0.2f, 0.6f, 0.8f); // hi this is a colo
    glBegin(GL_QUADS); // this makes rectangles
        glVertex2f(buttonX1, buttonY1); // defining vertexes for rects
        glVertex2f(buttonX2, buttonY1);
        glVertex2f(buttonX2, buttonY2);
        glVertex2f(buttonX1, buttonY2);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); // this is also a color
    glRasterPos2f(160, 150); // defininng starting position
    const char* text = "button"; // text in button
    for (const char* c = text; *c != '\0'; c++) { // for every char in text that isnt equal to the string terminator
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // print char with font
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // clear screen
    drawButton(); // procedure call
    glutSwapBuffers(); // display next frame
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { // if left mouse button is down
        int invertedY = 500 - y; // switching to normal coordinates because computer coordinates confuse me

        if (x >= buttonX1 && x <= buttonX2 && invertedY >= buttonY1 && invertedY <= buttonY2) { // if click is in domain and range
            printf("button activated\n"); // print button activated yayyyy
        }
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // make glut window
    glutInitWindowSize(500, 500); // x, y resolution
    glutCreateWindow("button"); // title

    glutDisplayFunc(display); // map for 2d rendering
    glutMouseFunc(mouse); // make the mouse work
    glutMainLoop(); // start the main loop
    return 0; // bye!
}
