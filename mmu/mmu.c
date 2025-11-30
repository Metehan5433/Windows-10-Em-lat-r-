// mmu/mmu.c
// Windows 10 Emulator - Memory Management Unit
// Bellek okuma/yazma fonksiyonları

#include <stdint.h>
#include <stdio.h>

#define MEMORY_SIZE 0x1000000 // 16 MB örnek bellek

static uint8_t memory[MEMORY_SIZE];

// 8-bit okuma
uint8_t mmu_read8(uint32_t addr) {
    if (addr < MEMORY_SIZE) {
        return memory[addr];
    } else {
        printf("MMU: Invalid read8 at 0x%08X\n", addr);
        return 0;
    }
}

// 32-bit okuma
uint32_t mmu_read32(uint32_t addr) {
    if (addr + 3 < MEMORY_SIZE) {
        return memory[addr] |
               (memory[addr+1] << 8) |
               (memory[addr+2] << 16) |
               (memory[addr+3] << 24);
    } else {
        printf("MMU: Invalid read32 at 0x%08X\n", addr);
        return 0;
    }
}

// 8-bit yazma
void mmu_write8(uint32_t addr, uint8_t value) {
    if (addr < MEMORY_SIZE) {
        memory[addr] = value;
    } else {
        printf("MMU: Invalid write8 at 0x%08X\n", addr);
    }
}

// 32-bit yazma
void mmu_write32(uint32_t addr, uint32_t value) {
    if (addr + 3 < MEMORY_SIZE) {
        memory[addr]   = (value & 0xFF);
        memory[addr+1] = ((value >> 8) & 0xFF);
        memory[addr+2] = ((value >> 16) & 0xFF);
        memory[addr+3] = ((value >> 24) & 0xFF);
    } else {
        printf("MMU: Invalid write32 at 0x%08X\n", addr);
    }
}
