# Windows 10 Emülatörü (ETS2 & OMSI 2 için)

Bu proje, **Windows 10 işletim sistemini emülatör içinde çalıştırmak** için geliştirilmiştir.  
Amaç: ETS2 (Euro Truck Simulator 2) ve OMSI 2 oyunlarını çalıştırmak, mod yükleme desteği sağlamak ve düşük boyutlu programların kurulmasına izin vermek.

---

## 🚀 Kurulum Adımları

1. **Repo’yu klonla**
   ```bash
   
   # Gokbiz Yazilim - Windows 10 Emulator (Skeleton)

Bu repo, Windows 10 emülatörü için modüler ve derlenebilir bir iskelet içerir:
- MMU (16MB bellek)
- Basit CPU (sözde opkod seti)
- UEFI boot simülasyonu (reset vectorden minimal program)
- ASCII framebuffer ile grafik çıktı

## Derleme
Basit C derleyici ile:

```bash
gcc -std=c11 -O2 -o emulator \
    core/cpu.c mmu/mmu.c firmware/uefi.c graphics/directx.c main.c
