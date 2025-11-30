// main.c
// Windows 10 Emulator - Entry Point

#include <stdio.h>
#include "core/cpu.h"
#include "mmu/mmu.h"
#include "firmware/uefi.h"
#include "graphics/directx.h"

int main(void) {
    // Init subsystems
    mmu_init();
    gfx_init();

    // Banner
    gfx_clear();
    gfx_draw_text(2, 1, "Gokbiz Yazilim");
    gfx_draw_text(2, 2, "Windows 10 Emulator - Demo Boot");
    gfx_draw_text(2, 4, "Booting...");
    gfx_present();

    // UEFI boot ve CPU
    CPU cpu;
    uefi_boot(&cpu);

    // CPU'yu belirli adim calistir
    cpu_run(&cpu, 64);

    // Son ekran
    gfx_clear();
    gfx_draw_text(2, 1, "Boot Completed");
    gfx_draw_text(2, 3, "Registers:");
    char line[64];
    for (int i = 0; i < 8; ++i) {
        snprintf(line, sizeof(line), "R%d = %u", i, cpu.regs[i]);
        gfx_draw_text(2, 5 + i, line);
    }
    gfx_present();

    // MMU test: STORE8 ile yazılan veri
    printf("\nMMU check: memory[20] = %u\n", mmu_read8(20));

    // Durum
    printf("CPU halted: %s\n", cpu.halted ? "true" : "false");
    printf("PC: 0x%08X\n", cpu.pc);
    return 0;
}
