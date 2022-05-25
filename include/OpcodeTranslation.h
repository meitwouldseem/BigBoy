#ifndef OPCODETRANSLATION_H
#define OPCODETRANSLATION_H

namespace cpu {
    struct InstructionDefinition
    {
        void (Cpu::*ptr)();
    };
}

#endif // OPCODETRANSLATION_H
