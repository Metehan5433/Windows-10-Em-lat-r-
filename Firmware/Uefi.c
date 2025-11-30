// firmware/uefi.c
// Windows 10 Emulator - UEFI Firmware Simulation

#include <stdint.h>
#include <stdio.h>
#include "../core/cpu.c"
#include "../mmu/mmu.c"
#include "../instructions.h"

// Reset vector adresi
#define RESET_VECTOR 0x0000FFF0

void uefi_boot() {
    printf("UEFI: Booting Windows 10 Emulator...\n");

    // CPU reset
    cpu_reset();

    // Belleğe basit bir boot kodu yükle
    mmu_write32(RESET_VECTOR, 0xEA000000); // örnek jump opcode

    // CPU'yu reset vectorden başlat
    cpu_execute(RESET_VECTOR);
}
