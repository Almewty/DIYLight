#include <FastLED.h>
#include <Firmata.h>

#define LED_PIN     3
#define NUM_LEDS    27
#define BRIGHTNESS  64
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

#define SET_HUE       0x01
#define SET_RGB       0x02
#define QUEUE_COLOR   0x03
#define FLUSH_COLORS  0x04
#define SET_LEDS      0x05

CRGB leds[NUM_LEDS];

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
    case FLUSH_COLORS:
      FastLED.show();
      break;
    case SET_LEDS:
      if (argc < 1)
        return;
      byte cnt = argv[0];
      if (argc < 1 + (cnt * 4))
        return;
      for (byte i = 0; i < cnt; ++i) {
        int offset = i * 4 + 1;
        leds[argv[offset]] =
          CRGB(argv[offset + 1],
               argv[offset + 2],
               argv[offset + 3]);
      }
      FastLED.show();
      break;
  }
}

void setupFastLed() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

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
  setupFastLed();
  setupFirmata();
}


void loop()
{
  while (Firmata.available())
    Firmata.processInput();
}
