#include <array>

#include "OpcodeTranslation.h"
#include "cpu.h"

#define BIND(code, func) table[code] = &Cpu::func


const std::array<InstrPtr, 256> Cpu::BuildTranslationTable1()
{
    std::array<InstrPtr, 256> table;
    //table[0] = &Cpu::NOP;

    BIND(0x00, NOP);
    BIND(0xCB, CB);

    //XOR
    BIND(0xA8, XOR_B);
    BIND(0xA9, XOR_C);
    BIND(0xAA, XOR_D);
    BIND(0xAB, XOR_E);
    BIND(0xAC, XOR_H);
    BIND(0xAD, XOR_L);
    BIND(0xAE, XOR_HL_);
    BIND(0xAF, XOR_A);
    BIND(0xEE, XOR_D8);

    //Load pair
    BIND(0x01, LD_BC);
    BIND(0x11, LD_DE);
    BIND(0x21, LD_HL);
    BIND(0x31, LD_SP);

    BIND(0x86, ADD_HL_);

    BIND(0x90, SUB_B);

    //Compare
    BIND(0xFE, CP_D8);
    BIND(0xBE, CP_HL_);

    //Increment
    BIND(0x03, INC_BC);
    BIND(0x13, INC_DE);
    BIND(0x23, INC_HL);
    BIND(0x33, INC_SP);
    BIND(0x04, INC_B);
    BIND(0x0C, INC_C);
    BIND(0x14, INC_D);
    BIND(0x1C, INC_E);
    BIND(0x24, INC_H);
    BIND(0x2C, INC_L);
    BIND(0x34, INC_HL_);
    BIND(0x3C, INC_A);

    //Decrement
    BIND(0x0B, DEC_BC);
    BIND(0x1B, DEC_DE);
    BIND(0x2B, DEC_HL);
    BIND(0x3B, DEC_SP);
    BIND(0x05, DEC_B);
    BIND(0x0D, DEC_C);
    BIND(0x15, DEC_D);
    BIND(0x1D, DEC_E);
    BIND(0x25, DEC_H);
    BIND(0x2D, DEC_L);
    BIND(0x35, DEC_HL_);
    BIND(0x3D, DEC_A);

    //Load
    BIND(0x78, LD_A_B);
    BIND(0x79, LD_A_C);
    BIND(0x7A, LD_A_D);
    BIND(0x7B, LD_A_E);
    BIND(0x7C, LD_A_H);
    BIND(0x7D, LD_A_L);
    BIND(0x7E, LD_A_HL_);
    BIND(0x7F, LD_A_A);
    BIND(0x3E, LD_A_D8);

    BIND(0x40, LD_B_B);
    BIND(0x41, LD_B_C);
    BIND(0x42, LD_B_D);
    BIND(0x43, LD_B_E);
    BIND(0x44, LD_B_H);
    BIND(0x45, LD_B_L);
    BIND(0x46, LD_B_HL_);
    BIND(0x47, LD_B_A);
    BIND(0x06, LD_B_D8);

    BIND(0x48, LD_C_B);
    BIND(0x49, LD_C_C);
    BIND(0x4A, LD_C_D);
    BIND(0x4B, LD_C_E);
    BIND(0x4C, LD_C_H);
    BIND(0x4D, LD_C_L);
    BIND(0x4E, LD_C_HL_);
    BIND(0x4F, LD_C_A);
    BIND(0x0E, LD_C_D8);

    BIND(0x50, LD_D_B);
    BIND(0x51, LD_D_C);
    BIND(0x52, LD_D_D);
    BIND(0x53, LD_D_E);
    BIND(0x54, LD_D_H);
    BIND(0x55, LD_D_L);
    BIND(0x56, LD_D_HL_);
    BIND(0x57, LD_D_A);
    BIND(0x16, LD_D_D8);

    BIND(0x58, LD_E_B);
    BIND(0x59, LD_E_C);
    BIND(0x5A, LD_E_D);
    BIND(0x5B, LD_E_E);
    BIND(0x5C, LD_E_H);
    BIND(0x5D, LD_E_L);
    BIND(0x5E, LD_E_HL_);
    BIND(0x5F, LD_E_A);
    BIND(0x1E, LD_E_D8);

    BIND(0x60, LD_H_B);
    BIND(0x61, LD_H_C);
    BIND(0x62, LD_H_D);
    BIND(0x63, LD_H_E);
    BIND(0x64, LD_H_H);
    BIND(0x65, LD_H_L);
    BIND(0x66, LD_H_HL_);
    BIND(0x67, LD_H_A);
    BIND(0x26, LD_H_D8);

    BIND(0x68, LD_L_B);
    BIND(0x69, LD_L_C);
    BIND(0x6A, LD_L_D);
    BIND(0x6B, LD_L_E);
    BIND(0x6C, LD_L_H);
    BIND(0x6D, LD_L_L);
    BIND(0x6E, LD_L_HL_);
    BIND(0x6F, LD_L_A);
    BIND(0x2E, LD_L_D8);

    BIND(0x70, LD_HL_B_);
    BIND(0x71, LD_HL_C_);
    BIND(0x72, LD_HL_D_);
    BIND(0x73, LD_HL_E_);
    BIND(0x74, LD_HL_H_);
    BIND(0x75, LD_HL_L_);
    BIND(0x77, LD_HL_A_);
    BIND(0x36, LD_HL_D8_);

    BIND(0xE2, LD_C_A_);
    BIND(0xF2, LD_A_C_);

    BIND(0x02, LD_BC_A_);
    BIND(0x12, LD_DE_A_);
    BIND(0x0A, LD_A_BC_);
    BIND(0x1A, LD_A_DE_);

    BIND(0xEA, LD_D16_A);

    BIND(0xE0, LD_D8_A);
    BIND(0xF0, LD_A_D8_);

    BIND(0x22, LD_HLp_A_);
    BIND(0x32, LD_HLm_A_);
    BIND(0x2A, LD_A_HLp_);
    BIND(0x3A, LD_A_HLm_);

    BIND(0x17, RLA);

    BIND(0x18, JR_D8);
    BIND(0x28, JR_Z_D8);
    BIND(0x20, JR_NZ_D8);

    BIND(0xCD, CALL_D16);

    BIND(0xC5, PUSH_BC);

    BIND(0xC1, POP_BC);

    BIND(0xC9, RET);

    return table;
}

const std::array<InstrPtr, 256> Cpu::BuildTranslationTable2()
{
    std::array<InstrPtr, 256> table;

    BIND(0x11, RL_C);

    BIND(0x7C, BIT_7_H);

    return table;
}
