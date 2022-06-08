#include <iostream>
#include <memory>

#include "Bus.h"
#include "Cpu.h"
#include "CpuStateMonitor.h"
#include "GraphicalDisplay.h"

int main()
{
    auto bus = std::make_shared<Bus>();
    auto cpu = std::make_shared<Cpu>(bus);
    cpu->Reset();

    auto cpuMonitor = std::make_shared<CpuStateMonitor>(cpu);
    auto display = std::make_shared<GraphicalDisplay>();
    bus->AttachDevice(display);

    //sf::Clock clock;
    //sf::Time cycle = sf::microseconds(0.954);

    while (true)
    {
        cpu->Step();
        if (cpuMonitor->isOpen())
            cpuMonitor->ProcessEvents();
        if (display->isOpen())
            display->ProcessEvents();
        //std::cout << clock.restart().asMicroseconds() << std::endl;
    }

    //std::cout << cpu->Run();

    return 0;
}
