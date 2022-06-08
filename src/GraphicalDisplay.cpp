#include <bitset>
#include "GraphicalDisplay.h"

GraphicalDisplay::GraphicalDisplay()
: RenderWindow(sf::VideoMode(500, 500), "Big Boy")
, TileVertices_(128, sf::VertexArray(sf::Quads, 8*8*4))
{

}

void GraphicalDisplay::ProcessEvents()
{
    sf::Event event;
    while (pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            close();
    }

    clear(sf::Color::Blue);
    for (const auto& tile : TileVertices_)
        draw(tile);
    display();
}

void GraphicalDisplay::BusWrite(uint16_t addr, uint8_t data)
{
    Memory_[addr] = data;
    std::bitset<8> byte1;
    std::bitset<8> byte2;
    if (addr % 2)
    {
        byte1 = std::bitset<8>(data);
        byte2 = std::bitset<8>(Memory_[addr+1]);
    }
    else
    {
        byte1 = std::bitset<8>(Memory_[addr-1]);
        byte2 = std::bitset<8>(data);
    }

    size_t tileIndex = (addr - 0x8000) / 0x10;
    size_t tileOffset = ((addr - 0x8000) % 0x10)/2;

    if (tileIndex >= TileSet_.size()) return;

    for (int i=0; i<8; i++)
    {
        if (byte1.test(i))
        {
            if (byte2.test(i))
            {
                newPixels[i*4] = 255;
                newPixels[(i*4)+1] = 255;
                newPixels[(i*4)+2] = 255;
                newPixels[(i*4)+3] = 128;
            }
            else
            {
                newPixels[i*4] = 63;
                newPixels[(i*4)+1] = 63;
                newPixels[(i*4)+2] = 63;
                newPixels[(i*4)+3] = 128;
            }
        }
        else
        {
            if (byte2.test(i))
            {
                newPixels[i*4] = 128;
                newPixels[(i*4)+1] = 128;
                newPixels[(i*4)+2] = 128;
                newPixels[(i*4)+3] = 128;
            }
            else
            {
                newPixels[i*4] = 0;
                newPixels[(i*4)+1] = 0;
                newPixels[(i*4)+2] = 0;
                newPixels[(i*4)+3] = 128;
            }
        }
    }

    TileSet_[tileIndex].update(newPixels.data(), 8, 1, 0, tileOffset);
    //TileSprites_[tileIndex].setTexture(TileSet_[tileIndex]);
}

bool GraphicalDisplay::ConnectedAtAddress(uint16_t addr)
{
    return addr >= 0x8000 && addr <=0x97FF;
}
