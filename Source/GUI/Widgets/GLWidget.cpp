//
// Created by Jared Chester on 3/27/2021.
//

#include "GLWidget.h"

void GLWidget::initializeGL() {
    glEnable(GL_LIGHTING);glEnable(GL_LIGHT0);
    glClearColor(1, 1, 0, 1); //sets a red background
    glEnable(GL_DEPTH_TEST);
}

void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}