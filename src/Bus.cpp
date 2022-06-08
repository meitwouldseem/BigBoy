#include "Bus.h"
#include "BusDevice.h"

uint8_t Bus::Read(uint16_t addr)
{
    return GetRef(addr);
}

void Bus::Write(uint16_t addr, uint8_t data)
{
    for (auto& device : Devices_)
        if(device->ConnectedAtAddress(addr))
            device->BusWrite(addr, data);

    BusMemory_[addr] = data;
}

uint8_t& Bus::GetRef(uint16_t addr)
{
    if (addr >= 0x0000 && addr <= 0x00ff)
    {
        return bootrom_[addr];
    }
    else if (addr >= 0x0104 && addr <= 0x0133)
    {
        return logo_[addr-0x0104];
    }
    else if (addr >= 0x0134 && addr <= 0x014D)
    {
        return checksum_[addr-0x0134];
    }
    else if (addr == 0xff44)
    {
        return LCDvalue_;//simulates the LCD driver.
    }
    return BusMemory_[addr];
}

void Bus::AttachDevice(std::shared_ptr<BusDevice> device)
{
    Devices_.push_back(device);
}
