
void testlines(uint16_t color) {
  tft.fillScreen(ST77XX_BLACK);
  for (int16_t x = 0; x < tft.width(); x += 6) {
    tft.drawLine(0, 0, x, tft.height() - 1, color);
    delay(0);
  }
  for (int16_t y = 0; y < tft.height(); y += 6) {
    tft.drawLine(0, 0, tft.width() - 1, y, color);
    delay(0);
  }

  tft.fillScreen(ST77XX_BLACK);
  for (int16_t x = 0; x < tft.width(); x += 6) {
    tft.drawLine(tft.width() - 1, 0, x, tft.height() - 1, color);
    delay(0);
  }
  for (int16_t y = 0; y < tft.height(); y += 6) {
    tft.drawLine(tft.width() - 1, 0, 0, y, color);
    delay(0);
  }

  tft.fillScreen(ST77XX_BLACK);
  for (int16_t x = 0; x < tft.width(); x += 6) {
    tft.drawLine(0, tft.height() - 1, x, 0, color);
    delay(0);
  }
  for (int16_t y = 0; y < tft.height(); y += 6) {
    tft.drawLine(0, tft.height() - 1, tft.width() - 1, y, color);
    delay(0);
  }

  tft.fillScreen(ST77XX_BLACK);
  for (int16_t x = 0; x < tft.width(); x += 6) {
    tft.drawLine(tft.width() - 1, tft.height() - 1, x, 0, color);
    delay(0);
  }
  for (int16_t y = 0; y < tft.height(); y += 6) {
    tft.drawLine(tft.width() - 1, tft.height() - 1, 0, y, color);
    delay(0);
  }
}

void testdrawtext(char *text, uint16_t color) {
  tft.setCursor(100, 100);
  tft.setTextColor(color);
  tft.setTextWrap(true);
  tft.print(text);
}

void testfastlines(uint16_t color1, uint16_t color2) {
  tft.fillScreen(ST77XX_BLACK);
  for (int16_t y = 0; y < tft.height(); y += 5) {
    tft.drawFastHLine(0, y, tft.width(), color1);
  }
  for (int16_t x = 0; x < tft.width(); x += 5) {
    tft.drawFastVLine(x, 0, tft.height(), color2);
  }
}

void testdrawrects(uint16_t color) {
  tft.fillScreen(ST77XX_BLACK);
  for (int16_t x = 0; x < tft.width(); x += 6) {
    tft.drawRect(tft.width() / 2 - x / 2, tft.height() / 2 - x / 2, x, x, color);
  }
}

void testfillrects(uint16_t color1, uint16_t color2) {
  tft.fillScreen(ST77XX_BLACK);
  for (int16_t x = tft.width() - 1; x > 6; x -= 6) {
    tft.fillRect(tft.width() / 2 - x / 2, tft.height() / 2 - x / 2, x, x, color1);
    tft.drawRect(tft.width() / 2 - x / 2, tft.height() / 2 - x / 2, x, x, color2);
  }
}

void testfillcircles(uint8_t radius, uint16_t color) {
  for (int16_t x = radius; x < tft.width(); x += radius * 2) {
    for (int16_t y = radius; y < tft.height(); y += radius * 2) {
      tft.fillCircle(x, y, radius, color);
    }
  }
}

void testdrawcircles(uint8_t radius, uint16_t color) {
  for (int16_t x = 0; x < tft.width() + radius; x += radius * 2) {
    for (int16_t y = 0; y < tft.height() + radius; y += radius * 2) {
      tft.drawCircle(x, y, radius, color);
    }
  }
}

void testtriangles() {
  // tft.fillScreen(ST77XX_BLACK);
  uint16_t color = 0xF800;
  int t;
  int w = tft.width() / 2;
  int x = tft.height() - 1;
  int y = 0;
  int z = tft.width();
  for (t = 0; t <= 15; t++) {
    tft.drawTriangle(w, y, y, x, z, x, color);
    x -= 4;
    y += 4;
    z -= 4;
    color += 200;
    delay(100);
  }
}

void testroundrects() {
  tft.fillScreen(ST77XX_BLACK);
  uint16_t color = 100;
  int i;
  int t;
  for (t = 0; t <= 4; t += 1) {
    int x = 0;
    int y = 0;
    int w = tft.width() - 2;
    int h = tft.height() - 2;
    for (i = 0; i <= 16; i += 1) {
      tft.drawRoundRect(x, y, w, h, 5, color);
      x += 2;
      y += 3;
      w -= 4;
      h -= 6;
      color += 1100;
    }
    color += 100;
  }
}

void tftPrintTest() {
  tft.setTextWrap(false);
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0, 30);
  tft.setTextColor(ST77XX_RED);
  tft.setTextSize(1);
  tft.println("Hello World!");
  tft.setTextColor(ST77XX_YELLOW);
  tft.setTextSize(2);
  tft.println("Hello World!");
  tft.setTextColor(ST77XX_GREEN);
  tft.setTextSize(3);
  tft.println("Hello World!");
  tft.setTextColor(ST77XX_BLUE);
  tft.setTextSize(4);
  tft.print(1234.567);
  delay(1500);
  tft.setCursor(0, 0);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(0);
  tft.println("Hello World!");
  tft.setTextSize(1);
  tft.setTextColor(ST77XX_GREEN);
//   tft.print(p, 6);
  tft.println(" Want pi?");
  tft.println(" ");
  tft.print(8675309, HEX);  // print 8,675,309 out in HEX!
  tft.println(" Print HEX!");
  tft.println(" ");
  tft.setTextColor(ST77XX_WHITE);
  tft.println("Sketch has been");
  tft.println("running for: ");
  tft.setTextColor(ST77XX_MAGENTA);
  tft.print(millis() / 1000);
  tft.setTextColor(ST77XX_WHITE);
  tft.print(" seconds.");
}

void mediabuttons() {
  // play
  tft.fillScreen(ST77XX_BLACK);
  tft.fillRoundRect(25, 10, 78, 60, 8, ST77XX_WHITE);
  tft.fillTriangle(42, 20, 42, 60, 90, 40, ST77XX_RED);
  delay(500);
  // pause
  tft.fillRoundRect(25, 90, 78, 60, 8, ST77XX_WHITE);
  tft.fillRoundRect(39, 98, 20, 45, 5, ST77XX_GREEN);
  tft.fillRoundRect(69, 98, 20, 45, 5, ST77XX_GREEN);
  delay(500);
  // play color
  tft.fillTriangle(42, 20, 42, 60, 90, 40, ST77XX_BLUE);
  delay(50);
  // pause color
  tft.fillRoundRect(39, 98, 20, 45, 5, ST77XX_RED);
  tft.fillRoundRect(69, 98, 20, 45, 5, ST77XX_RED);
  // play color
  tft.fillTriangle(42, 20, 42, 60, 90, 40, ST77XX_GREEN);
}


static const unsigned char PROGMEM image_battery_90_bits[] = {0x00,0x00,0x00,0x0f,0xff,0xfe,0x10,0x00,0x01,0x11,0x55,0x55,0x71,0x55,0x55,0x81,0x55,0x55,0x81,0x55,0x55,0x85,0x55,0x55,0x85,0x55,0x55,0x85,0x55,0x55,0x75,0x55,0x55,0x15,0x55,0x55,0x10,0x00,0x01,0x0f,0xff,0xfe,0x00,0x00,0x00,0x00,0x00,0x00};

static const unsigned char PROGMEM image_camera_bits[] = {0x00,0x78,0x00,0x30,0x84,0x00,0x7f,0x7b,0x00,0xc0,0x00,0x80,0x91,0xc6,0x80,0x86,0x30,0x80,0x85,0xd0,0x80,0x8a,0x28,0x80,0x8a,0x28,0x80,0x8a,0x28,0x80,0x85,0xd0,0x80,0x86,0x30,0x80,0x91,0xc6,0x80,0xc0,0x00,0x80,0x7f,0xff,0x00,0x00,0x00,0x00};

static const unsigned char PROGMEM image_folder_open_file_bits[] = {0x00,0x00,0x00,0x7c,0x00,0x00,0x83,0xfc,0x00,0x80,0x02,0x00,0x80,0x02,0x00,0x8f,0xff,0x00,0x90,0x00,0x80,0x97,0xff,0xc0,0xa4,0x00,0x40,0xa8,0x00,0x40,0xc8,0x00,0x80,0xd0,0x00,0x80,0x90,0x01,0x00,0xa0,0x01,0x00,0x7f,0xfe,0x00,0x00,0x00,0x00};

static const unsigned char PROGMEM image_image_3_bits[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf8,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xfc,0x00,0x20,0x00,0x02,0xa0,0x00,0x00,0x00,0x02,0xaa,0xaa,0xab,0xfe,0x00,0x20,0x00,0x02,0xa8,0x00,0x00,0x00,0x02,0xaa,0xaa,0xaf,0xfe,0x00,0x20,0x00,0x15,0xea,0x00,0x00,0x00,0x04,0xaa,0xaa,0xaf,0xff,0x00,0x20,0x00,0x57,0xfa,0x80,0x00,0x00,0x04,0xff,0xff,0xaf,0xff,0x00,0x20,0x01,0x5f,0xfe,0xa0,0x00,0x00,0x05,0xff,0xff,0xaf,0xff,0x00,0x20,0x01,0x7f,0xff,0xa8,0x00,0x00,0x05,0xff,0xff,0xaf,0xfe,0x00,0x20,0x09,0x7f,0xff,0xe8,0x00,0x00,0x05,0xff,0xff,0xab,0xfe,0x00,0x20,0x09,0x5f,0xff,0xfa,0x00,0x00,0x05,0xff,0xff,0xab,0xfc,0x00,0x20,0x09,0x5f,0xff,0xfa,0xfc,0x00,0x05,0xff,0xff,0xaa,0xf8,0x00,0x20,0x0a,0x57,0xff,0xf5,0xff,0x00,0x05,0xff,0xff,0xaa,0xa8,0x00,0x20,0x02,0x55,0xff,0xd7,0xff,0x80,0x05,0xff,0xff,0xaa,0xa8,0x00,0x20,0x02,0x95,0x7f,0x97,0xff,0x80,0x05,0xff,0xff,0xaa,0xa8,0x00,0x20,0x00,0xa5,0x5d,0x57,0xff,0x80,0x05,0xff,0xff,0xaa,0xa8,0x00,0x20,0x00,0x29,0x55,0xd5,0xff,0x80,0x05,0xff,0xff,0xae,0xb4,0x00,0x20,0x00,0x0a,0x55,0xd5,0xff,0x00,0x05,0xff,0xff,0x5e,0xf4,0x00,0x20,0x00,0x02,0x95,0xda,0xbf,0x00,0x05,0x55,0x55,0x5e,0xf4,0x00,0x20,0x00,0x00,0xa5,0x7c,0xa9,0x00,0x05,0x55,0x55,0x4e,0xb4,0x00,0x20,0x00,0x00,0x29,0x5c,0xa8,0x00,0x05,0x55,0x55,0x4a,0xa4,0x00,0x20,0x00,0x00,0x15,0x55,0x40,0x00,0x05,0x55,0x55,0x4a,0xa4,0x00,0x20,0x00,0x00,0x0a,0x55,0x00,0x00,0x01,0x55,0x55,0x4a,0xa4,0x00,0x20,0x00,0x00,0x02,0x95,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0xa8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x26,0xa9,0x7d,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0xa4,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3e,0xf7,0xf7,0xff,0xff,0xff,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x0a,0xa8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x2a,0xfa,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0xab,0xff,0xd0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x02,0xaf,0xff,0xa8,0x00,0x00,0x00,0x00,0x0f,0xfe,0x00,0x20,0x00,0x0a,0xbf,0xff,0x48,0x00,0x02,0xaa,0xaa,0xaa,0xaf,0x00,0x20,0x01,0x4e,0xff,0xfe,0xa8,0x00,0x0a,0xaa,0xaa,0xaa,0xab,0x00,0x20,0x05,0x5e,0xbf,0xfc,0xa8,0x00,0x0a,0xaa,0xaa,0xaa,0xa8,0x00,0x20,0x15,0x7e,0xaa,0xea,0xa0,0x00,0x0a,0xaa,0xaa,0xaa,0xa8,0x00,0x20,0x15,0xf5,0x7f,0xaa,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x15,0x75,0xff,0xea,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x09,0x55,0xff,0xf5,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x0a,0x55,0xff,0xf4,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x0a,0xab,0xff,0xf4,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x02,0xab,0xff,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x55,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x05,0x7f,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x01,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x2a,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00};

void draw(void) {
    // tft.clearDisplay();

    // battery_90
    tft.drawBitmap(124, 8, image_battery_90_bits, 24, 16, 0xAAA0);

    // camera
    tft.drawBitmap(26, 21, image_camera_bits, 17, 16, 0x4D85);

    // folder_open_file
    tft.drawBitmap(122, 45, image_folder_open_file_bits, 18, 16, 0xA815);

    // image
    tft.drawBitmap(8, 59, image_image_3_bits, 100, 59, 0xA800);

    // tft.display();
}



static const unsigned char PROGMEM image_battery_0_bits[] = {0x00,0x00,0x00,0x0f,0xff,0xfe,0x10,0x00,0x01,0x10,0x40,0x41,0x70,0x20,0x81,0x80,0x11,0x01,0x80,0x0a,0x01,0x80,0x04,0x01,0x80,0x0a,0x01,0x80,0x11,0x01,0x70,0x20,0x81,0x10,0x40,0x41,0x10,0x00,0x01,0x0f,0xff,0xfe,0x00,0x00,0x00,0x00,0x00,0x00};

static const unsigned char PROGMEM image_file_film_dia_bits[] = {0xff,0xfe,0xbf,0xfa,0xe0,0x0e,0xa0,0x0a,0xe0,0x0e,0xa0,0x0a,0xe0,0x0e,0xbf,0xfa,0xff,0xfe,0xa0,0x0a,0xe0,0x0e,0xa0,0x0a,0xe0,0x0e,0xa0,0x0a,0xff,0xfe,0xbf,0xfa};

static const unsigned char PROGMEM image_wifi_2_bars_bits[] = {0x01,0xf0,0x00,0x06,0x0c,0x00,0x18,0x03,0x00,0x21,0xf0,0x80,0x46,0x0c,0x40,0x88,0x02,0x20,0x10,0xe1,0x00,0x23,0x18,0x80,0x04,0x04,0x00,0x08,0x42,0x00,0x01,0xf0,0x00,0x03,0xb8,0x00,0x01,0x50,0x00,0x00,0xe0,0x00,0x00,0x40,0x00,0x00,0x00,0x00};

static const unsigned char PROGMEM image_passport_okay1_bits[] = {0x7f,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xfc,0xff,0xff,0xfe,0x00,0xff,0xfc,0xff,0xff,0xf1,0xff,0x1f,0xfc,0xff,0xff,0xce,0x00,0xe7,0xfc,0xff,0xff,0x30,0x00,0x19,0xfc,0xff,0xfe,0xc0,0x00,0x06,0xfc,0xff,0xfd,0x00,0x00,0x01,0x7c,0xff,0xfa,0x00,0x00,0x00,0xbc,0xff,0xf4,0x00,0x00,0x00,0x5c,0xff,0xe8,0x00,0x00,0x00,0x5c,0xff,0xe8,0x00,0x00,0x00,0x2c,0xff,0xd0,0x00,0x00,0x00,0x2c,0xff,0xd0,0x00,0x00,0x00,0x14,0xff,0xa0,0x00,0x00,0x00,0x14,0xff,0xa0,0x00,0x0f,0x80,0x0c,0xff,0x40,0x00,0x17,0xc0,0x0c,0xff,0x40,0x00,0x2f,0xe0,0x0c,0xff,0x40,0x00,0x48,0xf0,0x04,0xff,0x40,0x00,0x49,0xf0,0x04,0xff,0x40,0x00,0x4f,0xf0,0x04,0xff,0x40,0x00,0x4f,0xf0,0x04,0xff,0x40,0x00,0x47,0xd0,0x04,0xff,0x40,0x00,0x20,0x30,0x04,0xff,0x40,0x00,0x17,0xe0,0x04,0xff,0xa0,0x00,0x08,0x10,0x04,0xff,0xa0,0x00,0x10,0x08,0x04,0xff,0xa1,0xf0,0x00,0x08,0x04,0xff,0xbe,0x00,0x00,0x00,0x04,0xfe,0x60,0x00,0x00,0x00,0x04,0xf9,0x80,0x00,0x01,0x00,0x04,0xf6,0x00,0x00,0x01,0x00,0x04,0xe8,0x00,0x00,0x02,0x00,0x04,0xd0,0x00,0x00,0x04,0x00,0x04,0xd0,0x00,0x00,0x08,0x00,0x04,0xa0,0x00,0x00,0x70,0x00,0x04,0xa0,0x00,0x03,0x80,0x00,0x04,0xa7,0xf0,0x3c,0x00,0x00,0x04,0xd8,0x0f,0xc0,0x00,0x00,0x04,0xe8,0x00,0x00,0x00,0x00,0x04,0xf4,0x00,0x00,0x00,0x00,0x04,0xfb,0x00,0x07,0xf0,0x00,0x04,0xfc,0xff,0xff,0xc0,0x00,0x04,0xff,0x07,0xff,0x00,0x00,0x04,0xff,0xf7,0xf8,0x00,0x00,0x04,0xff,0xf7,0xf0,0x00,0x00,0x04,0xff,0xf7,0x80,0x00,0x00,0x04,0xff,0xf4,0x00,0x00,0x00,0x04,0x7f,0xff,0xff,0xff,0xff,0xf8};

static const unsigned char PROGMEM image_BatteryBody_bits[] = {0x03,0x3f,0xff,0xff,0xff,0xff,0xf0,0x03,0xf0,0x00,0x00,0x00,0x00,0x10,0x02,0xb3,0xff,0x27,0xff,0x9e,0x90,0x03,0x50,0x00,0x00,0x00,0x00,0x10,0x02,0xb0,0x00,0x00,0x00,0x00,0x50,0x7f,0x50,0x00,0x00,0x00,0x00,0x50,0xee,0xb0,0x00,0x00,0x00,0x00,0x10,0xc7,0x50,0x00,0x00,0x00,0x00,0x10,0xee,0xb0,0x00,0x00,0x00,0x00,0x50,0x7f,0x50,0x00,0x00,0x00,0x00,0x50,0x02,0xb0,0x00,0x00,0x00,0x00,0x50,0x03,0x50,0x00,0x00,0x00,0x00,0x50,0x02,0xb0,0x00,0x00,0x00,0x00,0x50,0x03,0x50,0x00,0x00,0x00,0x00,0x50,0x02,0xb0,0x00,0x00,0x00,0x00,0x50,0x03,0x50,0x00,0x00,0x00,0x00,0x50,0x02,0xb0,0x00,0x00,0x00,0x00,0x50,0x7f,0x50,0x00,0x00,0x00,0x00,0x50,0xfe,0xb0,0x00,0x00,0x00,0x00,0x50,0xc7,0x50,0x00,0x00,0x00,0x00,0x10,0xfe,0xb0,0x00,0x00,0x00,0x00,0x10,0x7f,0x50,0x00,0x00,0x00,0x00,0x50,0x02,0xb0,0x00,0x00,0x00,0x00,0x50,0x03,0x50,0x00,0x00,0x00,0x00,0x50,0x02,0xb0,0x00,0x00,0x00,0x00,0x50,0x03,0x52,0x8f,0xa7,0xfe,0x6f,0x10,0x03,0xf0,0x00,0x00,0x00,0x00,0x10,0x03,0x3f,0xff,0xff,0xff,0xff,0xf0};

static const unsigned char PROGMEM image__4E31D6EE_4B54_4CC6_8D8B_AC82C3D62C1F_bits[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xff,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0xff,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0xff,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xff,0xff,0xff,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xff,0xff,0xff,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0xff,0xff,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0xff,0xff,0xff,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0xff,0xff,0xff,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0xfe,0x8b,0xff,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0xf8,0x40,0xff,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0xf8,0x00,0x7f,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0xf0,0x00,0x3f,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0xf0,0x00,0x2f,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xe0,0x00,0x1f,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x80,0x00,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x80,0x00,0x07,0xff,0x00,0x00,0x00,0x00,0x00,0x01,0xff,0x80,0x00,0x03,0xff,0x00,0x00,0x00,0x00,0x00,0x01,0xff,0x00,0x00,0x01,0xff,0x00,0x00,0x00,0x00,0x00,0x01,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0x00,0x00,0x01,0xfe,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0x00,0x00,0x01,0xfe,0x80,0x00,0x00,0x7f,0x00,0x00,0x00,0x00,0x00,0x01,0xff,0xb8,0x00,0x08,0x3f,0x00,0x00,0x00,0x00,0x00,0x01,0xfe,0x14,0x00,0x50,0x3f,0x00,0x00,0x00,0x00,0x00,0x01,0xfe,0x15,0x00,0x40,0x3f,0x00,0x00,0x00,0x00,0x00,0x03,0xfc,0x00,0x00,0x00,0x1f,0x00,0x00,0x00,0x00,0x00,0x03,0xfe,0xd1,0x00,0x00,0x1f,0x80,0x00,0x00,0x00,0x00,0x03,0xff,0x9d,0x00,0x7f,0x1f,0xc0,0x00,0x00,0x00,0x00,0x03,0xff,0xb2,0x00,0x5d,0x8f,0xc0,0x00,0x00,0x00,0x00,0x03,0xfb,0x02,0x00,0x5b,0x8f,0xc0,0x00,0x00,0x00,0x00,0x03,0xf0,0x28,0x80,0x00,0x07,0xc0,0x00,0x00,0x00,0x00,0x03,0xf0,0x00,0x80,0x30,0x07,0xc0,0x00,0x00,0x00,0x00,0x03,0xe0,0x00,0x00,0x00,0x07,0x80,0x00,0x00,0x00,0x00,0x03,0xe0,0x00,0x00,0x00,0x07,0xc0,0x00,0x00,0x00,0x00,0x07,0xe0,0x00,0x00,0x00,0x07,0x80,0x00,0x00,0x00,0x00,0x07,0xe0,0x00,0x00,0x00,0x07,0x80,0x00,0x00,0x00,0x00,0x07,0xe0,0x00,0x00,0x00,0x07,0x80,0x00,0x00,0x00,0x00,0x07,0xe0,0x00,0x00,0x00,0x07,0x80,0x00,0x00,0x00,0x00,0x07,0xe0,0x00,0x00,0x00,0x07,0x80,0x00,0x00,0x00,0x00,0x03,0xe0,0x00,0x00,0x00,0x07,0x80,0x00,0x00,0x00,0x00,0x03,0xa0,0x01,0xc6,0x00,0x06,0x80,0x00,0x00,0x00,0x00,0x03,0x20,0x00,0x00,0x00,0x06,0x80,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x1f,0xff,0xf0,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x07,0xff,0xc0,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0x03,0xf6,0x80,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x01,0xf6,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0x00,0x02,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x00,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xfc,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xff,0x41,0x75,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xff,0xeb,0xc0,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xdf,0xff,0x00,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xd5,0xf8,0x00,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0x50,0x00,0x00,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0x80,0x00,0x00,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0x80,0x00,0x01,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0x80,0x00,0x01,0xf8,0x00,0x00,0x00,0x00,0x00,0x03,0xff,0x80,0x00,0x01,0xfc,0x00,0x00,0x00,0x00,0x00,0x3f,0xff,0x80,0x00,0x01,0xf7,0x00,0x00,0x00,0x00,0x01,0xff,0xff,0xc0,0x00,0x03,0xf7,0x80,0x00,0x00,0x00,0x07,0xff,0xff,0xc0,0x00,0x03,0xff,0xe0,0x00,0x00,0x00,0x1f,0xff,0xfb,0xe0,0x00,0x07,0xef,0xf8,0x00,0x00,0x00,0xff,0xff,0xfb,0xe0,0x00,0x07,0xef,0xff,0x80,0x00,0x03,0xff,0xff,0xf7,0xa0,0x00,0x07,0xef,0x7f,0xe0,0x00,0x0f,0xff,0xff,0xf7,0x80,0x00,0x0f,0xef,0xff,0xf8,0x00,0x3f,0xff,0xff,0xf7,0x80,0x00,0x0f,0xef,0x7f,0xfe,0x00,0x7f,0xff,0xff,0xf5,0xc0,0x00,0x0f,0xef,0xff,0xff,0x80,0xff,0xff,0xff,0xf5,0xc0,0x00,0x0f,0xd6,0xff,0xff,0xe0,0xff,0xff,0xff,0xff,0xc0,0x00,0x1f,0xeb,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xc0,0x00,0x0f,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xe0,0x00,0x0f,0xfe,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xe0,0x00,0x1f,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xe0,0x00,0x3f,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xe0,0x00,0x7f,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xf0,0x00,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xf0,0x01,0x7f,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xf8,0x01,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xf8,0x02,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xfc,0x06,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xfe,0x0f,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0x5f,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0x3f,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0x1f,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0x1f,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xfb,0xff,0xff,0xfe,0x1d,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xfd,0x18,0x7f,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xfd,0x40,0xe1,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x18,0x07,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xca,0xd9,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xef,0xfb,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe4,0xf7,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0x7f,0xff,0xf7,0xef,0xff,0xf8,0xff,0xff,0xff,0xff,0xfe,0x3f,0xff,0xf9,0xbf,0xff,0xf8};

 
void draw1(void) {
    // battery_0
    tft.drawBitmap(122, 4, image_battery_0_bits, 24, 16, 0xA584);

    // file_film_dia
    tft.drawBitmap(85, 94, image_file_film_dia_bits, 15, 16, 0xFFFF);

    // wifi_2_bars
    tft.drawBitmap(100, 22, image_wifi_2_bars_bits, 19, 16, 0xA800);

    // passport_okay1
    tft.drawBitmap(105, 73, image_passport_okay1_bits, 46, 49, 0x57EA);

    // BatteryBody
    tft.drawBitmap(99, 42, image_BatteryBody_bits, 52, 28, 0xFABF);

    // _4E31D6EE_4B54_4CC6_8D8B_AC82C3D62C1F
    tft.drawBitmap(-1, -1, image__4E31D6EE_4B54_4CC6_8D8B_AC82C3D62C1F_bits, 85, 128, 0xBDAD);

}
