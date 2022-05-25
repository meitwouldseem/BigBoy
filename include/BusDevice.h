#ifndef BUSDEVICE_H
#define BUSDEVICE_H

namespace bus {
    class BusDevice
    {
        public:
            BusDevice();
            virtual ~BusDevice() = default;

        private:
            void write(uint16_t addr, uint8_t data);
            uint8_t read(uint16_t addr);
    };
}
#endif // BUSDEVICE_H
