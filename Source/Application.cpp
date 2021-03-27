//
// Created by Jared Chester on 3/27/21.
//

#include "Application.h"

Application::Application(int argc, char **argv): QApplication(argc, argv) {
    this->Initialize();
}

Application::~Application() noexcept {
    if (this->m_isInitialized)
        this->Shutdown();
}

void Application::Initialize() {
    this->m_isInitialized = true;
}

void Application::Shutdown() {}

int Application::Run() {
    if (!this->m_isInitialized) {
        return 0;
    }

    return this->exec();
}



