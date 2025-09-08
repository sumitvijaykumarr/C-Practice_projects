#include "Application.h"

int main() {
    Application app;

    try {
        app.Initialize();
        int result = app.Execute();
        app.DeInitialize();
        return result;
    } catch (const std::exception &ex) {
        std::cerr << "[Error] Exception caught: " << ex.what() << std::endl;
        return -1;
    } catch (...) {
        std::cerr << "[Error] Unknown exception caught!" << std::endl;
        return -1;
    }
}
