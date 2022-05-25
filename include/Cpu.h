#ifndef CPU_H
#define CPU_H
#include <cstdint>

namespace cpu {
    struct CpuState
    {
        uint8_t A;//accumulator
        uint8_t F;//flags (Ignore)
        uint8_t B;
        uint8_t C;
        uint8_t D;
        uint8_t E;
        uint8_t H;
        uint8_t L;
        uint16_t SP;//stack pointer
        uint16_t PC;//program counter
        //Flags
        bool z;//zero
        bool n;//subtract
        bool h;//half carry (Ignore)
        bool c;//carry
    };

    class Cpu
    {
        public:
            Cpu();

        private:
            void TranslateOpcode();

            CpuState s;
    };
}

#endif // CPU_H
