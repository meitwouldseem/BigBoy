#include "Cpu.h"


int Cpu::NOP() {return 4;}

int Cpu::HALT() {exit(0); return 0;}

int Cpu::CB() {CBshift=true; return 4;}

int Cpu::LD_SP() {SP = Imm16(); return 12;}
int Cpu::LD_HL() {WritePair(Imm16(), H, L); return 12;}
int Cpu::LD_DE() {WritePair(Imm16(), D, E); return 12;}
int Cpu::LD_BC() {WritePair(Imm16(), B, C); return 12;}

//8bit xor bindings
int Cpu::XOR_B() {XOR(B); return 4;}
int Cpu::XOR_C() {XOR(C); return 4;}
int Cpu::XOR_D() {XOR(D); return 4;}
int Cpu::XOR_E() {XOR(E); return 4;}
int Cpu::XOR_H() {XOR(H); return 4;}
int Cpu::XOR_L() {XOR(L); return 4;}
int Cpu::XOR_HL_() {XOR(ReadBus(ReadPair(H, L))); return 8;}
int Cpu::XOR_A() {XOR(A); return 4;}
int Cpu::XOR_D8() {XOR(Imm8()); return 8;}

//8bit add bindings
int Cpu::ADD_HL_() {ADD(ReadBus(ReadPair(H, L))); return 8;}

//8but subtract bindings
int Cpu::SUB_B() {SUB(B); return 4;}

//Compare bindings
int Cpu::CP_HL_() {CP(ReadBus(ReadPair(H, L))); return 8;}
int Cpu::CP_D8() {CP(Imm8()); return 8;}

//16bit increment bindings
int Cpu::INC_BC() {IncrementPair(B, C); return 8;}
int Cpu::INC_DE() {IncrementPair(D, E); return 8;}
int Cpu::INC_HL() {IncrementPair(H, L); return 8;}
int Cpu::INC_SP() {SP++; return 8;}

//8bit increment bindings
int Cpu::INC_B() {INC(B); return 4;}
int Cpu::INC_C() {INC(C); return 4;}
int Cpu::INC_D() {INC(D); return 4;}
int Cpu::INC_E() {INC(E); return 4;}
int Cpu::INC_H() {INC(H); return 4;}
int Cpu::INC_L() {INC(L); return 4;}
int Cpu::INC_HL_() {INC(GetRef(ReadPair(H, L))); return 12;}
int Cpu::INC_A() {INC(A); return 4;}

//16bit decrement bindings
int Cpu::DEC_BC() {DecrementPair(B, C); return 8;}
int Cpu::DEC_DE() {DecrementPair(D, E); return 8;}
int Cpu::DEC_HL() {DecrementPair(H, L); return 8;}
int Cpu::DEC_SP() {SP--; return 8;}

//8bit decrement bindings
int Cpu::DEC_B() {DEC(B); return 4;}
int Cpu::DEC_C() {DEC(C); return 4;}
int Cpu::DEC_D() {DEC(D); return 4;}
int Cpu::DEC_E() {DEC(E); return 4;}
int Cpu::DEC_H() {DEC(H); return 4;}
int Cpu::DEC_L() {DEC(L); return 4;}
int Cpu::DEC_HL_() {DEC(GetRef(ReadPair(H, L))); return 12;}
int Cpu::DEC_A() {DEC(A); return 4;}

//8bit load bindings (A)
int Cpu::LD_A_B() {A=B; return 4;}
int Cpu::LD_A_C() {A=C; return 4;}
int Cpu::LD_A_D() {A=D; return 4;}
int Cpu::LD_A_E() {A=E; return 4;}
int Cpu::LD_A_H() {A=H; return 4;}
int Cpu::LD_A_L() {A=L; return 4;}
int Cpu::LD_A_HL_() {A=ReadBus(ReadPair(H, L)); return 8;}
int Cpu::LD_A_A() {return 4;}
int Cpu::LD_A_D8() {A=Imm8(); return 8;}

//8bit load bindings (B)
int Cpu::LD_B_B() {return 4;}
int Cpu::LD_B_C() {B=C; return 4;}
int Cpu::LD_B_D() {B=D; return 4;}
int Cpu::LD_B_E() {B=E; return 4;}
int Cpu::LD_B_H() {B=H; return 4;}
int Cpu::LD_B_L() {B=L; return 4;}
int Cpu::LD_B_HL_() {B=ReadBus(ReadPair(H, L)); return 8;}
int Cpu::LD_B_A() {B=A; return 4;}
int Cpu::LD_B_D8() {B=Imm8(); return 8;}

//8bit load bindings (C)
int Cpu::LD_C_B() {C=B; return 4;}
int Cpu::LD_C_C() {return 4;}
int Cpu::LD_C_D() {C=D; return 4;}
int Cpu::LD_C_E() {C=E; return 4;}
int Cpu::LD_C_H() {C=H; return 4;}
int Cpu::LD_C_L() {C=L; return 4;}
int Cpu::LD_C_HL_() {C=ReadBus(ReadPair(H, L)); return 8;}
int Cpu::LD_C_A() {C=A; return 4;}
int Cpu::LD_C_D8() {C=Imm8(); return 8;}

//8bit load bindings (D)
int Cpu::LD_D_B() {D=B; return 4;}
int Cpu::LD_D_C() {D=C; return 4;}
int Cpu::LD_D_D() {return 4;}
int Cpu::LD_D_E() {D=E; return 4;}
int Cpu::LD_D_H() {D=H; return 4;}
int Cpu::LD_D_L() {D=L; return 4;}
int Cpu::LD_D_HL_() {D=ReadBus(ReadPair(H, L)); return 8;}
int Cpu::LD_D_A() {D=A; return 4;}
int Cpu::LD_D_D8() {D=Imm8(); return 8;}

//8bit load bindings (E)
int Cpu::LD_E_B() {E=B; return 4;}
int Cpu::LD_E_C() {E=C; return 4;}
int Cpu::LD_E_D() {E=D; return 4;}
int Cpu::LD_E_E() {return 4;}
int Cpu::LD_E_H() {E=H; return 4;}
int Cpu::LD_E_L() {E=L; return 4;}
int Cpu::LD_E_HL_() {E=ReadBus(ReadPair(H, L)); return 8;}
int Cpu::LD_E_A() {E=A; return 4;}
int Cpu::LD_E_D8() {E=Imm8(); return 8;}

//8bit load bindings (H)
int Cpu::LD_H_B() {H=B; return 4;}
int Cpu::LD_H_C() {H=C; return 4;}
int Cpu::LD_H_D() {H=D; return 4;}
int Cpu::LD_H_E() {H=E; return 4;}
int Cpu::LD_H_H() {return 4;}
int Cpu::LD_H_L() {H=L; return 4;}
int Cpu::LD_H_HL_() {H=ReadBus(ReadPair(H, L)); return 8;}
int Cpu::LD_H_A() {H=A; return 4;}
int Cpu::LD_H_D8() {H=Imm8(); return 8;}

//8bit load bindings (L)
int Cpu::LD_L_B() {L=B; return 4;}
int Cpu::LD_L_C() {L=C; return 4;}
int Cpu::LD_L_D() {L=D; return 4;}
int Cpu::LD_L_E() {L=E; return 4;}
int Cpu::LD_L_H() {L=H; return 4;}
int Cpu::LD_L_L() {return 4;}
int Cpu::LD_L_HL_() {L=ReadBus(ReadPair(H, L)); return 8;}
int Cpu::LD_L_A() {L=A; return 4;}
int Cpu::LD_L_D8() {L=Imm8(); return 8;}

int Cpu::LD_HL_B_() {WriteBus(ReadPair(H, L), B); return 8;}
int Cpu::LD_HL_C_() {WriteBus(ReadPair(H, L), C); return 8;}
int Cpu::LD_HL_D_() {WriteBus(ReadPair(H, L), D); return 8;}
int Cpu::LD_HL_E_() {WriteBus(ReadPair(H, L), E); return 8;}
int Cpu::LD_HL_H_() {WriteBus(ReadPair(H, L), H); return 8;}
int Cpu::LD_HL_L_() {WriteBus(ReadPair(H, L), L); return 8;}
int Cpu::LD_HL_A_() {WriteBus(ReadPair(H, L), A); return 8;}
int Cpu::LD_HL_D8_() {WriteBus(ReadPair(H, L), Imm8()); return 12;}

int Cpu::LD_C_A_() {WriteBus(0xFF00+C, Imm8()); return 8;}
int Cpu::LD_A_C_() {A=ReadBus(0xFF00+C); return 8;}

int Cpu::LD_BC_A_() {WriteBus(ReadPair(B, C), A); return 8;}
int Cpu::LD_DE_A_() {WriteBus(ReadPair(D, E), A); return 8;}
int Cpu::LD_A_BC_() {A=ReadBus(ReadPair(B, C)); return 8;}
int Cpu::LD_A_DE_() {A=ReadBus(ReadPair(D, E)); return 8;}

int Cpu::LD_D16_A() {WriteBus(Imm16(), A); return 16;}

int Cpu::LD_D8_A() {WriteBus(0xFF00+Imm8(), A); return 12;}
int Cpu::LD_A_D8_() {A=ReadBus(0xFF00+Imm8()); return 12;}

int Cpu::LD_HLp_A_() {WriteBus(ReadPair(H, L), A); IncrementPair(H, L); return 8;}
int Cpu::LD_HLm_A_() {WriteBus(ReadPair(H, L), A); DecrementPair(H, L); return 8;}
int Cpu::LD_A_HLp_() {A=ReadBus(ReadPair(H, L)); IncrementPair(H, L); return 8;}
int Cpu::LD_A_HLm_() {A=ReadBus(ReadPair(H, L)); DecrementPair(H, L); return 8;}

//bit rotate bindings

int Cpu::RLA() {RL(A); return 4;}

int Cpu::RL_C() {RL(C); return 8;}

//jump bindings

int Cpu::JR_D8() {return JR(Imm8(), true);}

int Cpu::JR_NZ_D8() {return JR(Imm8(), !z);}
int Cpu::JR_Z_D8() {return JR(Imm8(), z);}

//call/return bindings

int Cpu::CALL_D16() {CALL(Imm16()); return 24;}

int Cpu::RET() {PC=POP(); return 16;}

//push bindings

int Cpu::PUSH_BC() {PUSH(B, C); return 16;}

//pop bindings

int Cpu::POP_BC() {POP(B, C); return 12;}

//bit manipulation bindings

int Cpu::BIT_7_H() {BIT(7, H); return 8;}

//helper functions

void Cpu::WritePair(uint16_t val, uint8_t &hi, uint8_t &lo)
{
    hi = val >> 8;
    lo = val;
}

uint16_t Cpu::ReadPair(uint8_t hi, uint8_t lo)
{
    return (hi << 8) | lo;
}

void Cpu::IncrementPair(uint8_t &hi, uint8_t &lo)
{
    lo++;
    if (lo == 0x00)
        hi++;
}

void Cpu::DecrementPair(uint8_t &hi, uint8_t &lo)
{
    lo--;
    if (lo == 0xFF)
        hi--;
}

//XOR operations always write to the ACC (A) so this function need not return a value
void Cpu::XOR(uint8_t operand)
{
    A = A ^ operand;
    z = (A==0x00);
    n = h = c = false;
}

//16 bit increment/decrement operation does not modify flags and as such requires no generalized implementation

void Cpu::INC(uint8_t &operand)
{
    operand++;
    n = false;
    z = (operand==0x00);
}

void Cpu::DEC(uint8_t &operand)
{
    operand--;
    n = true;
    z = (operand==0x00);
}

void Cpu::ADD(uint8_t operand)
{
    uint8_t Acpy = A;
    A += operand;
    z = (A==0x00);
    n = false;
    c = (A < Acpy);
}

void Cpu::SUB(uint8_t operand)
{
    c = (A < operand);
    A -= operand;
    z = (A==0x00);
    n = true;
}

void Cpu::CP(uint8_t operand)
{
    c = (A < operand);
    z = (A==operand);
    n = true;
}

void Cpu::POP(uint8_t &hi, uint8_t &lo)
{
    lo = ReadBus(SP);
    SP++;
    hi = ReadBus(SP);
    SP++;
}

uint16_t Cpu::POP()
{
    uint8_t lo = ReadBus(SP);
    SP++;
    uint8_t hi = ReadBus(SP);
    SP++;
    return (hi << 8) | lo;
}

void Cpu::PUSH(uint8_t hi, uint8_t lo)
{
    SP--;
    WriteBus(SP, hi);
    SP--;
    WriteBus(SP, lo);
}

void Cpu::PUSH(uint16_t operand)
{
    PUSH(operand >> 8, operand);
}

void Cpu::RL(uint8_t &operand)
{
    uint8_t setcarry = operand;
    operand <<= 1;
    operand += c;
    c = ((setcarry & 0x80) == 0x80);
}

//Jump commands

int Cpu::JR(int8_t operand, bool condition)
{//Note the unsigned argument
    //std::cout << "jump from: "<< std::hex << +PC;
    if (condition)
    {
        PC += operand;
        return 12;
    }
    else
        return 8;
    //std::cout << " to " << std::hex << +PC << std::endl;
}

//Bit manipulation

void Cpu::BIT(uint8_t bit, uint8_t operand)
{
    z = !((operand & (1 << bit)) == (1 << bit));
    h = true;
    n = false;
}

void Cpu::CALL(uint16_t operand)
{
    PUSH(PC);
    PC=operand;
}

//addressing modes

uint8_t Cpu::Imm8()
{
    uint8_t byte = ReadBus(PC);
    PC++;
    return byte;
}

uint16_t Cpu::Imm16()
{
    //hi and lo need to be 16 bit integers to make space for the bit shift.
    //16 bit immediate data is read in reverse in all cases that I am aware of.

    uint16_t lo = ReadBus(PC);
    PC++;
    uint16_t hi = ReadBus(PC);
    PC++;

    return (hi << 8) | lo;
}
