//
// Created by Jared Chester on 3/27/21.
//

#include "MainWindow.h"

MainWindow::MainWindow(int w, int h, const char *title): QMainWindow() {
    this->resize(w, h);
    this->setWindowTitle(title);
}

