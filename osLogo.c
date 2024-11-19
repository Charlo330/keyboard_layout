static const char PROGMEM logo[][2][3] = {
	{{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
  {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
};

static void render_os_logo(void) {
		switch (detected_host_os()) {
      case OS_MACOS:
				oled_write("  ", false);
    	  oled_write_P(logo[1][0], false);
        oled_write_P(PSTR("   "), false);
        oled_write_P(logo[1][1], false);
        break;
      case OS_WINDOWS:
        oled_write_P(logo[0][0], false);
        oled_write_P(PSTR("   "), false);
        oled_write_P(logo[0][1], false);
        break;
      case OS_LINUX:
        oled_write_ln("Unix", false);
        break;
      default:
        oled_write_ln("Err", false);
        break;
      }
			oled_write_ln("\n\n", false);
}
