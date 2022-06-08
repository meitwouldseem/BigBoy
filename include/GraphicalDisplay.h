#ifndef GRAPHICALDISPLAY_H
#define GRAPHICALDISPLAY_H
#include <cstdint>
#include <memory>
#include <array>
#include <SFML/Graphics.hpp>

#include "BusDevice.h"

class GraphicalDisplay : public sf::RenderWindow, public BusDevice
{
    public:
        GraphicalDisplay();
        void ProcessEvents();

    private:
        void BusWrite(uint16_t addr, uint8_t data) override;
        bool ConnectedAtAddress(uint16_t addr) override;

        std::array<uint8_t, 0x2000> Memory_;
        std::vector<sf::VertexArray> TileVertices_;
};

#endif // GRAPHICALDISPLAY_H
