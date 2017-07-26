#include<FastLED.h>

#define NUM_LEDS 64

#define DATA_PIN 6

CRGB leds[NUM_LEDS];

int WackyBird = 33;

int count = 1;

int boardState[64] = {
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0
  };

int newColumn[8] = {7,15,23,31,39,47,55,63};

void obstacleCreation(){
  int hole = random(1,7);

  int obstacleRow[8] = {1,1,1,1,1,1,1,1};

  obstacleRow[hole -1] = 0;
  obstacleRow[hole] = 0;
  obstacleRow[hole + 1] = 0;

  boardState[7] = obstacleRow[0];
  boardState[15] = obstacleRow[1];
  boardState[23] = obstacleRow[2];
  boardState[31] = obstacleRow[3];
  boardState[39] = obstacleRow[4];
  boardState[47] = obstacleRow[5];
  boardState[55] = obstacleRow[6];
  boardState[63] = obstacleRow[7];

  for (int i = 0; i < 7; i++){
    if(i+ 1 != WackyBird)
      leds[i] = leds[i + 1];
    if (i+9 != WackyBird)
    leds[i+8] = leds[i+9];
    if (i+17 != WackyBird)
    leds[i + 16] = leds[i+ 17];
    if (i+25 != WackyBird)
    leds[i + 24] = leds[i + 25];
    if (i+33 != WackyBird)
    leds[i + 32] = leds[i + 33];
    if (i+41 != WackyBird)
    leds[i + 40] = leds[i + 41];
    if (i+49 != WackyBird)
    leds[i + 48] = leds[i + 49];
    if (i+57 != WackyBird)
    leds[i + 56] = leds[i + 57];
  }
  
  if(count == 3){
    createPillars();
    count = 1;
  }
  else{
    createSpace();
    count++;
  }
}

void createPillars(){
  for (int i = 7; i <64; i+=8){
    if (boardState[i] == 1){
      leds[i] = CRGB::Green;
    }
    else{
      leds[i] = CRGB::Black;
    }
  }
}

void createSpace(){
  for (int i = 7; i <64; i+=8){
      leds[i] = CRGB::Black;
  }
}

void drawWacky(){
  leds[WackyBird] = CRGB::White;
}

void setup() {
  // put your setup code here, to run once:
 FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
 FastLED.setBrightness(32);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  obstacleCreation();
  drawWacky();
  FastLED.show();
  delay(300);
  
}
