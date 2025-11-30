#ifndef UI_DRIVER_H
#define UI_DRIVER_H

void ui_driver_init(void);
void ui_driver_draw_header(const char* channel_name);
void ui_driver_draw_left_panel(bool ets2_installed, bool omsi1_installed, bool omsi2_installed, bool steam_installed);
void ui_driver_draw_center_status(const char* app_name, const char* status);
void ui_driver_draw_right_metrics(int speed_kmh, int gear, int doors_open, const char* last_announce);
void ui_driver_draw_footer(void);
void ui_driver_present(void);

#endif
