#include <Source/Core/Application.h>
#include <Source/GUI/MainWindow.h>

#include <spdlog/spdlog.h>

#include <json/json.hpp>
using json = nlohmann::json;

int main(int argc, char **argv) {
    auto app = Application(argc, argv);
    auto window = MainWindow(1280, 720, "DM Helper");

    spdlog::info("Test");

    json j2 = {
            {"pi", 3.141},
            {"happy", true},
            {"name", "Niels"},
            {"nothing", nullptr},
            {"answer", {
                           {"everything", 42}
                   }},
            {"list", {1, 0, 2}},
            {"object", {
                           {"currency", "USD"},
                         {"value", 42.99}
                   }}
    };

    spdlog::info(j2.dump());

    window.show();

    int ret = app.Run();

    return ret;
}
