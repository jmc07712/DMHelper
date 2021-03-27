//
// Created by Jared Chester on 3/27/2021.
//

#ifndef DMHELPER_GLWIDGET_H
#define DMHELPER_GLWIDGET_H


#include <QOpenGLWidget>

class GLWidget: public QOpenGLWidget {
public:
    GLWidget() = default;
    ~GLWidget() override = default;

    void initializeGL() override;

    void paintGL() override;

    void resizeGL(int w, int h) override;
};


#endif //DMHELPER_GLWIDGET_H
