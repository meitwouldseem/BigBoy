#ifndef CPUSTATEMONITOR_H
#define CPUSTATEMONITOR_H
#include <memory>
#include <SFML/Graphics.hpp>

class Cpu;

class CpuStateMonitor : public sf::RenderWindow
{
    public:
        CpuStateMonitor(std::shared_ptr<Cpu> cpu);
        void ProcessEvents();

    private:
        void UpdateText();

        std::shared_ptr<Cpu> cpu_;

        sf::Font font_;
        sf::Text text_;
};

#endif // CPUSTATEMONITOR_H
