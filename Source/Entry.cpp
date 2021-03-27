#include <Source/Core/Application.h>
#include <Source/GUI/MainWindow.h>
#include <QOpenGLWidget>

#include <sqlite3.h>

class GLWidget : public QOpenGLWidget {
public:
    GLWidget() {}

    ~GLWidget() {}

    void initializeGL() override {
        glEnable(GL_LIGHTING);glEnable(GL_LIGHT0);
        glClearColor(1, 1, 0, 1); //sets a red background
        glEnable(GL_DEPTH_TEST);
    }

    void paintGL() override {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void resizeGL(int w, int h) override {
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
    }
};

int main(int argc, char **argv) {
    auto app = Application(argc, argv);
    auto window = MainWindow(1280, 720, "DM Helper");

    window.show();

    int ret = app.exec();

    return ret;
}
