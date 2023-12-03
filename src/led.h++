#include <Adafruit_NeoPixel.h>

// How many internal neopixels do we have? some boards have more than one! GPIO48 or GPIO38

#define PIN_NEOPIXEL 48
#define NUMPIXELS 1

Adafruit_NeoPixel pixels(NUMPIXELS, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);

int led(int state)
{
    // set color to red
    switch (state)
    {
    case 1:
        pixels.fill(0x00FF00);
        pixels.show();
        break;

    case 0:
        pixels.fill(0x000);
        pixels.show();
        break;
    }
    return 0;
}
int led_shine(){
    for(int i = 0; i < 256; i++){
        pixels.setPixelColor(0,i,0,0);
        pixels.show();
        delay(1);
    }
    for(int i = 0; i < 256; i++){
        pixels.setPixelColor(0,255-i,i,0);
        pixels.show();
        delay(1);
    }
    for (int i = 0; i < 256; i++)
    {
        pixels.setPixelColor(0, 0, 255 - i, i);
        pixels.show();
        delay(1);
    }
    pixels.clear();
    pixels.show();


    return 0;
}