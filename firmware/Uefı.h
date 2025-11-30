// firmware/uefi.h
// Windows 10 Emulator - UEFI Interface

#ifndef UEFI_H
#define UEFI_H

#include <stdint.h>
#include "../core/cpu.h"

// Reset vector adresi (son sayfa gibi bir yer)
#define RESET_VECTOR 0x0000FFF0

void uefi_boot(CPU* cpu);

#endif // UEFI_H
