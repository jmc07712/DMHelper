//
// Created by Jared Chester on 3/27/21.
//

#include <spdlog/spdlog.h>
#include "Application.h"

Application::Application(int argc, char **argv): QApplication(argc, argv) {
    this->Initialize();
}

Application::~Application() {
    if (this->m_isInitialized)
        this->Shutdown();
}

void Application::Initialize() {
    spdlog::info("Initializing application.");
    this->m_isInitialized = true;
}

void Application::Shutdown() {
    spdlog::info("Shutting down application.");
}

int Application::Run() {
    if (!this->m_isInitialized) {
        return 0;
    }

    return this->exec();
}



