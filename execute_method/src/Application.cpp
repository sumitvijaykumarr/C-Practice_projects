#include "Application.h"
#include <thread>
#include <chrono>

Application::Application() : running(false), counter(0) {}

Application::~Application() {
    if (running) {
        DeInitialize(); // ensure cleanup if not done
    }
}

void Application::Initialize() {
    std::cout << "[Init] Application starting..." << std::endl;
    running = true;
}

int Application::Execute() {
    if (!running) {
        throw std::runtime_error("Application not initialized!");
    }

    while (running) {
        std::cout << "[Loop] Counter = " << counter << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(1));
        counter++;

        if (counter > 5) {
            running = false; // exit after 5 iterations
        }
    }
    return 0;
}

void Application::DeInitialize() {
    std::cout << "[DeInit] Cleaning up resources..." << std::endl;
    running = false;
}
