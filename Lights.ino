#include <FastLED.h>
#include <Firmata.h>

#define LED_PIN     3
#define NUM_LEDS    150
#define BRIGHTNESS  64
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

#define SET_HUE 0x01
#define SET_RGB 0x02
#define QUEUE_COLOR 0x03
#define FLUSH_COLOR 0x04
#define SET_LED_CNT 0x05

CRGB leds[NUM_LEDS];
CLEDController *controller;

void sysexCallback(byte command, byte argc, byte *argv) {
  switch (command) {
    case SET_HUE:
      if (argc < 1)
        return;
      FastLED.showColor(CHSV(argv[0], 255, 255));
      break;
    case SET_RGB:
      if (argc < 3)
        return;
      FastLED.showColor(CRGB(argv[0], argv[1], argv[2]));
      break;
    case QUEUE_COLOR:
      if (argc < 4)
        return;
      leds[argv[0]] = CRGB(argv[1], argv[2], argv[3]);
      break;
    case FLUSH_COLOR:
      FastLED.show();
      break;
    case SET_LED_CNT:
      if (argc < 1)
        return;
      setupFastLed(argv[0]);
      break;
  }
}

void setupFastLed(byte cnt) {
  FastLED.clear(true);
  if (controller == NULL)
    controller = &FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, cnt).setCorrection(TypicalLEDStrip);
  else
    controller->setLeds(leds, cnt);

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
}

void setupFirmata() {
  Firmata.setFirmwareVersion(FIRMATA_FIRMWARE_MAJOR_VERSION, FIRMATA_FIRMWARE_MINOR_VERSION);
  Firmata.attach(START_SYSEX, sysexCallback);
  Firmata.begin(57600);
}

void setup() {
  delay( 3000 ); // power-up safety delay
  setupFastLed(NUM_LEDS);
  setupFirmata();
}


void loop()
{
  while (Firmata.available())
    Firmata.processInput();
}
