//
// Created by Jared Chester on 3/27/21.
//

#include <iostream>
#include "Application.h"

Application::Application(int argc, char **argv): QApplication(argc, argv) {
    this->Initialize();
}

Application::~Application() noexcept {
    if (this->m_isInitialized)
        this->Shutdown();
}

void Application::Initialize() {
    std::cout << "Initializing application." << std::endl;
    this->m_isInitialized = true;
}

void Application::Shutdown() {
    std::cout << "Shutting down application." << std::endl;
}

int Application::Run() {
    if (!this->m_isInitialized) {
        return 0;
    }

    return this->exec();
}



