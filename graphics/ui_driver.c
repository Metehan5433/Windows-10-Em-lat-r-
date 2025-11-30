#include "ui_driver.h"
#include "directx.h"
#include <stdio.h>

void ui_driver_init(void) { /* gerekirse theme yükle */ }

void ui_driver_draw_header(const char* channel_name) {
    gfx_clear();
    gfx_draw_text(2, 0, "Gokbiz Yazilim - Surucu Konsolu");
    char buf[64];
    snprintf(buf, sizeof(buf), "YouTube: %s", channel_name);
    gfx_draw_text(2, 1, buf);
}

void ui_driver_draw_left_panel(bool ets2_i, bool omsi1_i, bool omsi2_i, bool steam_i) {
    gfx_draw_text(2, 3,  "Kurulu Paketler:");
    gfx_draw_text(2, 4,  ets2_i   ? "ETS2   : Kurulu"   : "ETS2   : Yok");
    gfx_draw_text(2, 5,  omsi1_i  ? "OMSI 1 : Kurulu"   : "OMSI 1 : Yok");
    gfx_draw_text(2, 6,  omsi2_i  ? "OMSI 2 : Kurulu"   : "OMSI 2 : Yok");
    gfx_draw_text(2, 7,  steam_i  ? "Steam  : Kurulu"   : "Steam  : Yok");
}

void ui_driver_draw_center_status(const char* app_name, const char* status) {
    char buf[64];
    snprintf(buf, sizeof(buf), "Aktif: %s", app_name);
    gfx_draw_text(20, 4, buf);
    gfx_draw_text(20, 5, status);
    gfx_draw_text(20, 7, "Anons/Ding: Etkin");
}

void ui_driver_draw_right_metrics(int speed_kmh, int gear, int doors_open, const char* last_announce) {
    char buf[64];
    gfx_draw_text(2, 9, "Surus Met rikleri:");
    snprintf(buf, sizeof(buf), "Hiz: %d km/h", speed_kmh);
    gfx_draw_text(2, 10, buf);
    snprintf(buf, sizeof(buf), "Vites: %d", gear);
    gfx_draw_text(20, 10, buf);
    snprintf(buf, sizeof(buf), "Kapi: %s", doors_open ? "Acik" : "Kapali");
    gfx_draw_text(32, 10, buf);
    gfx_draw_text(2, 11, last_announce);
}

void ui_driver_draw_footer(void) {
    gfx_draw_text(2, 12, "[Baslat] [Durdur] [Ayarlar] [Atolye] [Modlar]");
}

void ui_driver_present(void) { gfx_present(); }
