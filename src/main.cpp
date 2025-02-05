#include <Arduino.h>

#include <Adafruit_GFX.h>     // Core graphics library
#include <Adafruit_ST7735.h>  // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h>  // Hardware-specific library for ST7789
#include <SPI.h>


#define TFT_CS 4
#define TFT_RST 6
#define TFT_DC 8
#define TFT_SCLK 21
#define TFT_MOSI 10


// OPTION 1 (recommended) is to use the HARDWARE SPI pins, which are unique
// to each board and not reassignable. For Arduino Uno: MOSI = pin 11 and
// SCLK = pin 13. This is the fastest mode of operation and is required if
// using the breakout board's microSD card.

// For 1.44" and 1.8" TFT with ST7735 use:
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
#include "Test.h"
// For 1.14", 1.3", 1.54", 1.69", and 2.0" TFT with ST7789:
//Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);


// OPTION 2 lets you interface the display using ANY TWO or THREE PINS,
// tradeoff being that performance is not as fast as hardware SPI above.
//#define TFT_MOSI 11  // Data out
//#define TFT_SCLK 13  // Clock out

// For ST7735-based displays, we will use this call
//Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

// OR for the ST7789-based displays, we will use this call
//Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);


float p = 3.1415926;

void setup(void) {
  SPI.begin(TFT_SCLK, TFT_DC, TFT_MOSI, TFT_CS);
  Serial.begin(115200);
  Serial.print(F("Hello! ST77xx TFT Test"));

  // Use this initializer if using a 1.8" TFT screen:
  // tft.initR(INITR_BLACKTAB);  // Init ST7735S chip, black tab

  // OR use this initializer if using a 1.8" TFT screen with offset such as WaveShare:
  // tft.initR(INITR_GREENTAB);      // Init ST7735S chip, green tab

  // OR use this initializer (uncomment) if using a 1.44" TFT:
  //tft.initR(INITR_144GREENTAB); // Init ST7735R chip, green tab

  // OR use this initializer (uncomment) if using a 0.96" 160x80 TFT:
  //tft.initR(INITR_MINI160x80);  // Init ST7735S mini display
  // OR use this initializer (uncomment) if using a 0.96" 160x80 TFT with
  // plug-in FPC (if you see the display is inverted!)
  //tft.initR(INITR_MINI160x80_PLUGIN);  // Init ST7735S mini display

  // OR use this initializer (uncomment) if using a 1.3" or 1.54" 240x240 TFT:
  //tft.init(240, 240);           // Init ST7789 240x240

  // OR use this initializer (uncomment) if using a 1.69" 280x240 TFT:
  //tft.init(240, 280);           // Init ST7789 280x240

  // OR use this initializer (uncomment) if using a 2.0" 320x240 TFT:
  //tft.init(240, 320);           // Init ST7789 320x240

  // OR use this initializer (uncomment) if using a 1.14" 240x135 TFT:
  //tft.init(135, 240);           // Init ST7789 240x135

  // OR use this initializer (uncomment) if using a 1.47" 172x320 TFT:
  //tft.init(172, 320);           // Init ST7789 172x320

  // SPI speed defaults to SPI_DEFAULT_FREQ defined in the library, you can override it here
  // Note that speed allowable depends on chip and quality of wiring, if you go too fast, you
  // may end up with a black screen some times, or all the time.
  //tft.setSPISpeed(40000000);

  // Serial.println(F("Initialized"));

  // uint16_t time = millis();
  // tft.fillScreen(ST77XX_BLACK);
  // time = millis() - time;

  // Serial.println(time, DEC);
  // delay(500);

  // // large block of text
  // tft.fillScreen(ST77XX_BLACK);
  // testdrawtext("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, fringilla sed malesuada et, malesuada sit amet turpis. Sed porttitor neque ut ante pretium vitae malesuada nunc bibendum. Nullam aliquet ultrices massa eu hendrerit. Ut sed nisi lorem. In vestibulum purus a tortor imperdiet posuere. ", ST77XX_WHITE);
  // delay(1000);

  // // tft print function!
  // tftPrintTest();
  // delay(4000);

  // // a single pixel
  // tft.drawPixel(tft.width()/2, tft.height()/2, ST77XX_GREEN);
  // delay(500);

  // // line draw test
  // testlines(ST77XX_YELLOW);
  // delay(500);

  // // optimized lines
  // testfastlines(ST77XX_RED, ST77XX_BLUE);
  // delay(500);

  // testdrawrects(ST77XX_GREEN);
  // delay(500);

  // testfillrects(ST77XX_YELLOW, ST77XX_MAGENTA);
  // delay(500);

  // tft.fillScreen(ST77XX_BLACK);
  // testfillcircles(10, ST77XX_BLUE);
  // testdrawcircles(10, ST77XX_WHITE);
  // delay(500);

  // testroundrects();
  // delay(500);

  // testtriangles();
  // delay(500);

  // mediabuttons();
  // delay(500);

  // Serial.println("done");
  // delay(1000);
  tft.setRotation(3);
}

void loop() {
  // testtriangles();
  // // tft.invertDisplay(true);

  delay(500);
    Serial.print(F("Hello! ST77xx TFT Test"));
  tft.fillScreen(0xd7a428);
  // testdrawtext("Doraemon", ST77XX_BLUE);
  testtriangles();
  // tft.invertDisplay(false);
  delay(1000);
  tft.fillScreen(ST77XX_BLACK);
  draw();
  delay(15000);
  tft.fillScreen(ST77XX_BLACK);
  draw1();
  delay(15000);
}
