//
// Created by Jared Chester on 3/27/21.
//

#ifndef DMHELPER_APPLICATION_H
#define DMHELPER_APPLICATION_H


#include <QApplication>

class Application: public QApplication {
public:
    Application(int argc, char **argv);
    ~Application() override;

    int Run();

private:
    void Initialize();
    void Shutdown();

private:
    bool m_isInitialized = false;
};


#endif //DMHELPER_APPLICATION_H
