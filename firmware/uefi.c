#include "../graphics/ui_driver.h"
#include "../apps/steam.h"
#include "../apps/ets2.h"
#include "../apps/omsi1.h"
#include "../apps/omsi2.h"

void uefi_show_driver_console(void) {
    ui_driver_init();
    ui_driver_draw_header("KanalAdi"); // YouTube kanal ismi
    ui_driver_draw_left_panel(true, true, true, true);
    ui_driver_draw_center_status("ETS2", "Profil yukleniyor...");
    ui_driver_draw_right_metrics(0, 0, 0, "Son Anons: Beklemede");
    ui_driver_draw_footer();
    ui_driver_present();
}
