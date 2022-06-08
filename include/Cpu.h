#ifndef CPU_H
#define CPU_H
#include <cstdint>
#include <array>
#include <memory>

#include "OpcodeTranslation.h"

class Bus;

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
    bool CBshift;
};

class Cpu
{
public:
    Cpu();
    Cpu(std::shared_ptr<Bus> bus);

    int Run();
    void Step();
    void Reset();
    CpuState State();

private:
    void WriteBus(uint16_t addr, uint8_t data);
    uint8_t ReadBus(uint16_t addr);
    uint8_t& GetRef(uint16_t addr);

    //OpcodeTranslation.h
    const std::array<InstrPtr, 256> BuildTranslationTable1();
    const std::array<InstrPtr, 256> BuildTranslationTable2();

    //Instructions.h
    //instruction bindings

    // _ at the end of a binding denotes 16bit reg being used as a pointer
    // D8 means 8bit immediate data

    int NOP();
    int HALT();
    int CB();

    int LD_SP();
    int LD_HL();
    int LD_DE();
    int LD_BC();

    //8bit xor bindings
    int XOR_B();
    int XOR_C();
    int XOR_D();
    int XOR_E();
    int XOR_H();
    int XOR_L();
    int XOR_HL_();
    int XOR_A();
    int XOR_D8();

    //8bit add bindings
    int ADD_HL_();

    //8but subtract bindings
    int SUB_B();

    //Compare bindings
    int CP_HL_();
    int CP_D8();

    //16bit increment bindings
    int INC_BC();
    int INC_DE();
    int INC_HL();
    int INC_SP();

    //8bit increment bindings
    int INC_B();
    int INC_C();
    int INC_D();
    int INC_E();
    int INC_H();
    int INC_L();
    int INC_HL_();
    int INC_A();

    //16bit decrement bindings
    int DEC_BC();
    int DEC_DE();
    int DEC_HL();
    int DEC_SP();

    //8bit decrement bindings
    int DEC_B();
    int DEC_C();
    int DEC_D();
    int DEC_E();
    int DEC_H();
    int DEC_L();
    int DEC_HL_();
    int DEC_A();

    //8bit load bindings (A)
    int LD_A_B();
    int LD_A_C();
    int LD_A_D();
    int LD_A_E();
    int LD_A_H();
    int LD_A_L();
    int LD_A_HL_();
    int LD_A_A();
    int LD_A_D8();

    //8bit load bindings (B)
    int LD_B_B();
    int LD_B_C();
    int LD_B_D();
    int LD_B_E();
    int LD_B_H();
    int LD_B_L();
    int LD_B_HL_();
    int LD_B_A();
    int LD_B_D8();

    //8bit load bindings (C)
    int LD_C_B();
    int LD_C_C();
    int LD_C_D();
    int LD_C_E();
    int LD_C_H();
    int LD_C_L();
    int LD_C_HL_();
    int LD_C_A();
    int LD_C_D8();

    //8bit load bindings (D)
    int LD_D_B();
    int LD_D_C();
    int LD_D_D();
    int LD_D_E();
    int LD_D_H();
    int LD_D_L();
    int LD_D_HL_();
    int LD_D_A();
    int LD_D_D8();

    //8bit load bindings (E)
    int LD_E_B();
    int LD_E_C();
    int LD_E_D();
    int LD_E_E();
    int LD_E_H();
    int LD_E_L();
    int LD_E_HL_();
    int LD_E_A();
    int LD_E_D8();

    //8bit load bindings (H)
    int LD_H_B();
    int LD_H_C();
    int LD_H_D();
    int LD_H_E();
    int LD_H_H();
    int LD_H_L();
    int LD_H_HL_();
    int LD_H_A();
    int LD_H_D8();

    //8bit load bindings (L)
    int LD_L_B();
    int LD_L_C();
    int LD_L_D();
    int LD_L_E();
    int LD_L_H();
    int LD_L_L();
    int LD_L_HL_();
    int LD_L_A();
    int LD_L_D8();

    int LD_HL_B_();
    int LD_HL_C_();
    int LD_HL_D_();
    int LD_HL_E_();
    int LD_HL_H_();
    int LD_HL_L_();
    int LD_HL_A_();
    int LD_HL_D8_();

    int LD_C_A_();
    int LD_A_C_();

    int LD_BC_A_();
    int LD_DE_A_();
    int LD_A_BC_();
    int LD_A_DE_();

    int LD_D16_A();

    int LD_D8_A();
    int LD_A_D8_();

    int LD_HLp_A_();
    int LD_HLm_A_();
    int LD_A_HLp_();
    int LD_A_HLm_();

    //bit rotate bindings

    int RLA();

    int RL_C();

    //jump bindings

    int JR_D8();

    int JR_NZ_D8();
    int JR_Z_D8();

    //call/return bindings

    int CALL_D16();

    int RET();

    //push bindings

    int PUSH_BC();

    //pop bindings

    int POP_BC();

    //bit manipulation bindings

    int BIT_7_H();

    //instruction behaviour implementations

    void XOR(uint8_t operand);

    void INC(uint8_t &operand);
    void INC(uint8_t &hi, uint8_t &lo);
    void DEC(uint8_t &operand);
    void DEC(uint8_t &hi, uint8_t &lo);

    void ADD(uint8_t operand);

    void SUB(uint8_t operand);

    void CP(uint8_t operand);

    void POP(uint8_t &hi, uint8_t &lo);
    uint16_t POP();
    void PUSH(uint8_t hi, uint8_t lo);
    void PUSH(uint16_t operand);

    //bit rotate

    void RL(uint8_t &operand);

    //jump commands

    int JR(int8_t operand, bool condition);

    //Bit manipulation

    void BIT(uint8_t bit, uint8_t operand);

    void CALL(uint16_t operand);

    //Read and write HL

    void WritePair(uint16_t val, uint8_t &hi, uint8_t &lo);
    uint16_t ReadPair(uint8_t hi, uint8_t lo);

    //Increment/Decrement pair

    void IncrementPair(uint8_t &hi, uint8_t &lo);
    void DecrementPair(uint8_t &hi, uint8_t &lo);

    //Addressing modes

    uint8_t Imm8();
    uint16_t Imm16();
    uint8_t Ptr8();
    uint16_t Ptr16();

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
    bool CBshift = false;

    const std::array<InstrPtr, 256> InstructionLookup1_;
    const std::array<InstrPtr, 256> InstructionLookup2_;

    std::shared_ptr<Bus> Bus_;
};

#endif // CPU_H
