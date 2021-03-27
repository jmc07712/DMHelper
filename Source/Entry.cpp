#include <Source/Core/Application.h>
#include <Source/GUI/MainWindow.h>

#include <spdlog/spdlog.h>
#include <json/json.hpp>
using json = nlohmann::json;

int main(int argc, char **argv) {
    auto app = Application(argc, argv);
    auto window = MainWindow(1280, 720, "DM Helper");

#if WINX64_BUILD
    spdlog::info("Windows build detected.");
    window.setWindowIcon(QIcon("Assets/win_x64/win_x64_app.png"));
#elif MACOS_BUILD
    spdlog::info("MacOS build detected.");
    window.setWindowIcon(QIcon("Assets/win_x64/win_x64_app.png"));
#endif

    window.show();

    int ret = app.Run();

    return ret;
}
