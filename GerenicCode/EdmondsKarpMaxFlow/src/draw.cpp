#include "draw.h"

void draw_init(){

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    glClear(GL_ACCUM_BUFFER_BIT);
}

void draw(){


    glClearColor(1, 1, 1, 255);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0,0,0);
    glBegin(GL_LINES);
        glVertex2f(-.5, -.5);
        glVertex2f(.5, .5);
    glEnd();
    glColor3f(0,1,0);
    glBegin(GL_TRIANGLES);
        glVertex2f(.1, .4);
        glVertex2f(.2, .3);
        glVertex2f(.15, .2);
    glEnd();

}
