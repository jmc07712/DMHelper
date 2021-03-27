#include <Source/Core/Application.h>
#include <Source/GUI/MainWindow.h>

#include <spdlog/spdlog.h>

int main(int argc, char **argv) {
    auto app = Application(argc, argv);
    auto window = MainWindow(1280, 720, "DM Helper");

    spdlog::info("Test");

    window.show();

    int ret = app.Run();

    return ret;
}
