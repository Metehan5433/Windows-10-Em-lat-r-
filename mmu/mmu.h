// mmu/mmu.h
// Windows 10 Emulator - MMU Interface

#ifndef MMU_H
#define MMU_H

#include <stdint.h>

#define MEMORY_SIZE (16 * 1024 * 1024) // 16 MB

void mmu_init(void);
uint8_t  mmu_read8(uint32_t addr);
uint32_t mmu_read32(uint32_t addr);
void mmu_write8(uint32_t addr, uint8_t value);
void mmu_write32(uint32_t addr, uint32_t value);

#endif // MMU_H
