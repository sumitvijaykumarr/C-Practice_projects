#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <stdexcept>

class Application {
public:
    Application();
    ~Application();

    // Lifecycle methods
    void Initialize();       // setup resources
    int Execute();           // main loop
    void DeInitialize();     // cleanup

private:
    bool running;
    int counter;
};

#endif // APPLICATION_H
