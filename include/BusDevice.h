#ifndef BUSDEVICE_H
#define BUSDEVICE_H
#include <cstdint>

class BusDevice
{
    public:
        BusDevice() = default;
        virtual ~BusDevice() = default;

        virtual void BusWrite(uint16_t addr, uint8_t data) = 0;
        virtual bool ConnectedAtAddress(uint16_t addr) = 0;
};

#endif // BUSDEVICE_H
