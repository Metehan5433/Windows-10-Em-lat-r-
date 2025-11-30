// include/instructions.h
// Windows 10 Emulator - Instruction Opcodes

#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

// Basit opkod sabitleri
enum {
    OPC_NOP   = 0x01,
    OPC_MOVI  = 0x02,
    OPC_ADD   = 0x03,
    OPC_SUB   = 0x04,
    OPC_JMP   = 0x05,
    OPC_JZ    = 0x06,
    OPC_STORE8= 0x07,
    OPC_LOAD8 = 0x08,
    OPC_HALT  = 0xFF
};

#endif // INSTRUCTIONS_H
