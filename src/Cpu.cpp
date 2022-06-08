#include <iostream>

#include "Cpu.h"
#include "OpcodeTranslation.h"
#include "Bus.h"


Cpu::Cpu()
: InstructionLookup1_(BuildTranslationTable1())
, InstructionLookup2_(BuildTranslationTable2())
, Bus_(std::make_shared<Bus>())
{
}

Cpu::Cpu(std::shared_ptr<Bus> bus)
: InstructionLookup1_(BuildTranslationTable1())
, InstructionLookup2_(BuildTranslationTable2())
, Bus_(bus)
{
}

int Cpu::Run()
{
    int cycles = 0;
    Reset();
    while (true)
    {
        cycles++;
        Step();
        if (PC > 256) return cycles;
    }
}

void Cpu::Step()
{
    uint8_t oppcode = ReadBus(PC++);

    //std::cout << std::hex << +oppcode << std::endl;

    if (CBshift)
    {
        (this->*InstructionLookup2_[oppcode])();
        CBshift = false;
    }
    else
        (this->*InstructionLookup1_[oppcode])();
}

CpuState Cpu::State()
{
    CpuState state;
    state.A = A;
    state.B = B;
    state.C = C;
    state.D = D;
    state.E = E;
    state.F = F;
    state.H = H;
    state.L = L;
    state.SP = SP;
    state.PC = PC;
    state.z = z;
    state.n = n;
    state.h = h;
    state.c = c;
    state.CBshift = CBshift;
    return state;
}

void Cpu::Reset()
{
    A = 0x00;
    B = 0x00;
    C = 0x00;
    D = 0x00;
    E = 0x00;
    F = 0x00;

    H = 0x00;
    L = 0x00;

    SP = 0x0000;
    PC = 0x0000;

    z = false;
    n = false;
    h = false;
    c = false;

    CBshift = false;
}

void Cpu::WriteBus(uint16_t addr, uint8_t data)
{
    Bus_->Write(addr, data);
}

uint8_t Cpu::ReadBus(uint16_t addr)
{
    return Bus_->Read(addr);
}

uint8_t& Cpu::GetRef(uint16_t addr)
{
    return Bus_->GetRef(addr);
}
