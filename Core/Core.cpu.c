// core/cpu.c
// Windows 10 Emulator - CPU Decoder Module
// Leyla'nın emülatör projesi için referans başlangıç

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "mmu.h"
#include "instructions.h"

// Genel CPU register seti (x86 mimarisi için)
typedef struct {
    uint32_t eax, ebx, ecx, edx;
    uint32_t esi, edi, ebp, esp;
    uint32_t eip;        // Instruction Pointer
    uint32_t eflags;     // Status Flags
} CPUState;

static CPUState cpu;

// Bellekten instruction fetch
uint8_t fetch_byte(uint32_t addr) {
    return mmu_read8(addr);
}

// Instruction decode
void decode_and_execute(uint8_t opcode) {
    switch(opcode) {
        case 0x90: // NOP
            // hiçbir şey yapma
            break;
        case 0xB8: // MOV EAX, imm32
        {
            uint32_t imm = mmu_read32(cpu.eip + 1);
            cpu.eax = imm;
            cpu.eip += 5;
            break;
        }
        case 0xCD: // INT imm8
        {
            uint8_t int_num = mmu_read8(cpu.eip + 1);
            handle_interrupt(int_num);
            cpu.eip += 2;
            break;
        }
        default:
            printf("Unknown opcode: 0x%02X at EIP=0x%08X\n", opcode, cpu.eip);
            break;
    }
}

// CPU ana döngüsü
void cpu_run() {
    while(true) {
        uint8_t opcode = fetch_byte(cpu.eip);
        decode_and_execute(opcode);
    }
}

// CPU reset
void cpu_reset() {
    cpu.eax = cpu.ebx = cpu.ecx = cpu.edx = 0;
    cpu.esi = cpu.edi = cpu.ebp = cpu.esp = 0;
    cpu.eip = 0x0000FFF0; // BIOS reset vector
    cpu.eflags = 0x00000002; // default state
}
