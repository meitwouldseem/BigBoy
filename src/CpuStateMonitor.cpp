#include <string>
#include <sstream>

#include "CpuStateMonitor.h"
#include "Cpu.h"

CpuStateMonitor::CpuStateMonitor(std::shared_ptr<Cpu> cpu)
: RenderWindow(sf::VideoMode(200, 200), "Cpu Monitor")
, cpu_(cpu)
{
    if (!font_.loadFromFile("kongtext.ttf"))
        throw std::runtime_error("Could not load font.");
    text_.setFont(font_);
    text_.setCharacterSize(20);
}

void CpuStateMonitor::ProcessEvents()
{
    sf::Event event;
    while (pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            close();
    }

    UpdateText();

    clear();
    draw(text_);
    display();
}

void CpuStateMonitor::UpdateText()
{
    auto state = cpu_->State();
    auto str = std::stringstream();

    str << "A:" << std::hex << +state.A << std::endl;
    str << "B:" << std::hex << +state.B << std::endl;
    str << "C:" << std::hex << +state.C << std::endl;
    str << "D:" << std::hex << +state.D << std::endl;
    str << "E:" << std::hex << +state.E << std::endl;
    str << "H:" << std::hex << +state.H << std::endl;
    str << "L:" << std::hex << +state.L << std::endl;
    str << "PC:" << std::hex << +state.PC << std::endl;
    str << "SP:" << std::hex << +state.SP << std::endl;

    text_.setString(sf::String(str.str()));
}
