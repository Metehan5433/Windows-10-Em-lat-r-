// core/cpu.h
// Windows 10 Emulator - CPU Interface

#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint32_t pc;      // Program Counter
    uint32_t regs[8]; // Genel amaçlı 8 register (R0-R7)
    uint32_t flags;   // basit bayraklar: Z(0x1), N(0x2), C(0x4)
    bool halted;
} CPU;

// CPU API
void cpu_init(CPU* cpu);
void cpu_reset(CPU* cpu, uint32_t reset_vector);
void cpu_step(CPU* cpu);            // bir talimat yürüt
void cpu_run(CPU* cpu, uint32_t max_steps); // N adım çalıştır
void cpu_set_flag(CPU* cpu, uint32_t mask, bool value);
bool cpu_get_flag(const CPU* cpu, uint32_t mask);

#endif // CPU_H
