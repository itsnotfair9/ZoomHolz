/*
0 - 26 _ wasserloecher
26 - 96 wasserader
96 - 112 (also 16) adern blau oder rot
112 bis 128 (also 16) chloroblaster
128 + 99 = 227 energy (ast 45, stamm unten 28 stamm oben 26

// use strip.fill(color, starnum, number) to work with segments in a strip
 Wasserloch*/
int WasserLochIn_1 = 52;
int WasserLochIn_2 = 50;
int WasserLochIn_3 = 48;
int WasserLochIn_4 = 46;
int WasserLochIn_5 = 44;
int WasserLochIn_6 = 38;

int WasserSensor_1 = 0;
int WasserSensor_2 = 0;
int WasserSensor_3 = 0;
int WasserSensor_4 = 0;
int WasserSensor_5 = 0;
int WasserSensor_6 = 0;
// sonne & wolke
// int WolkeInput = A0;
int WolkenSwitch = 34;
int WolkenSwitchSens = 0;
int AstWachstum = 53;
int WolkenMagnet = 49;
// int KuckBatterie = 45;    // batterie strom
// int KuckTrigger = 43;    // kuckuckTrigger...muss in der zeit ohne batterie kurz geoffnet werden
int PolSchalter = 32;
int StromVersorger = 31;
int BirdMove = 33;
int KuckuckSound = 35;
int sec = 0;
int RunEnergy = 0;

int WolkenSensor; 
int Calibration;
int Threshold;
int countDown;

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN        42 
#define NUMPIXELS 227 
// declare the pixel strip object
Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

uint32_t white = strip.ColorHSV(512, 0, 255); // noSaturation = white?
uint32_t yello = strip.ColorHSV(10922, 255, 150); // yello 43
uint32_t green = strip.ColorHSV(21845, 255, 150); // green  85
uint32_t blue = strip.ColorHSV(43690, 255, 255);   // 170
uint32_t red = strip.ColorHSV(65536, 255, 255);// rot 256
uint32_t magenta = strip.ColorHSV(54613, 255, 255);// magenta 213
uint32_t cyan = strip.ColorHSV(32768, 255, 255);// cyan 128
uint32_t off = strip.ColorHSV(512, 255, 0); // off
uint32_t color;
int RndColor;
int ColorArray[] = {43, 85, 170, 256, 213, 128, 170, 43, 128, 85, 213, 43, 128, 213, 170}; // yello, green, blue, red, magenta, cyan
int wait = 10;
int blobDistance = 48;
int counter = 0;
int pixel = 0;
// timing

int BlinkState = 0;
int OverallState = 1;
int Wasserstand = 0;
char receivedChar;
unsigned long currentMillis = millis();
unsigned long previousMillis = 0;
unsigned long BirdCurrentMillis = millis();
unsigned long BirdPreviousMillis = 0;
const long interval = 12;
const long BirdInterval = 15;
int a_count = 0;
int b_count = 0;
int Nahrung = 0;
int Sonne = 0;
int randNumber;
int colorCount;
  int counter01;
  int pixel_2;
  int pixel_3;


void setup() {
  Serial.begin(9600);
  Serial.println((String)"Setup "+BirdInterval);
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(255); // Set BRIGHTNESS to about 1/5 (max = 255)

  // WasserSensor setup
pinMode(WasserLochIn_1, INPUT_PULLUP);
pinMode(WasserLochIn_2, INPUT_PULLUP);
pinMode(WasserLochIn_3, INPUT_PULLUP);
pinMode(WasserLochIn_4, INPUT_PULLUP);
pinMode(WasserLochIn_5, INPUT_PULLUP);
pinMode(WasserLochIn_6, INPUT_PULLUP);
// Sonne
pinMode(AstWachstum, OUTPUT);
pinMode(WolkenMagnet, OUTPUT);
pinMode(WolkenSwitch, INPUT_PULLUP);
pinMode(13, OUTPUT);
OverallState = 1;   

// sonne & wolke
  digitalWrite(WolkenMagnet, HIGH);
  digitalWrite(AstWachstum, HIGH);

pinMode(PolSchalter, OUTPUT);
pinMode(StromVersorger, OUTPUT);
pinMode(BirdMove, OUTPUT);
pinMode(KuckuckSound, OUTPUT);


digitalWrite(PolSchalter, HIGH);
digitalWrite(StromVersorger, HIGH);
digitalWrite(BirdMove, HIGH);
digitalWrite(KuckuckSound, HIGH);
  
 Serial.println((String)"Counter01 "+ counter01);

}

void loop() { 
while (OverallState == 1) {
  while (Nahrung != 3) {
  //Serial.println((String)"Status "+OverallState);
  strip.show();
  WasserSensor_1 = digitalRead(WasserLochIn_1);
  WasserSensor_2 = digitalRead(WasserLochIn_2);
  WasserSensor_3 = digitalRead(WasserLochIn_3);
  WasserSensor_4 = digitalRead(WasserLochIn_4);
  WasserSensor_5 = digitalRead(WasserLochIn_5);
  WasserSensor_6 = digitalRead(WasserLochIn_6);
    if (!WasserSensor_1 == 0 && Wasserstand != 3) {                   //Sensoren 1, 3 und 5 bei Status 1
      BlinkLED(blue, 0, 5);           
      } 
   else { 
        strip.fill(blue, 0, 5);
          strip.show();
      } 
   if (!WasserSensor_3 == 0 && Wasserstand != 3) {        
      BlinkLED(blue, 10, 5);                      // also LED 10 - 15
      } 
   else { 
        strip.fill(blue, 10, 5);
          strip.show();
      } 
   if (!WasserSensor_5 == 0 && Wasserstand != 3) {
      BlinkLED(blue, 20, 5);
      } 
   else { 
        strip.fill(blue, 20, 5);
          strip.show();
      }

  Wasserstand = !WasserSensor_1 + !WasserSensor_3 + !WasserSensor_5;        // ! wasserloch 1, 3 und 5

    if (Wasserstand == 0) {                     
      PixelRun(blue, 30, 17);           // standard wasser stand von 30 bis 47
      strip.show();
    }
    if (Wasserstand == 1) {
        PixelRun(blue, 30, 34);         // run von 30 an 34 pixel
        strip.fill(off, 65, 51);        // von 100 + 16 pxl sind blatt adern
        strip.show();
        } 
    if (Wasserstand == 2) {
        PixelRun(blue, 30, 52);
        strip.fill(off, 83, 33);        
        
        } 
      if (Wasserstand == 3) {     // && (Nahrung == 0)
        PixelRun(blue, 30, 69);     // nur wenn sonne nicht strahlt isses blau
        strip.show();
        } 
        if ((Wasserstand == 3) && (Nahrung == 0)) {
          strip.fill(blue, 100, 16);   
           strip.show();          
        }
// Sonne

WolkenSwitchSens = digitalRead(WolkenSwitch);

  if (!WolkenSwitchSens) {           //  negation des Schalters
      Sonne = 1;
      digitalWrite(WolkenMagnet, LOW);
      RapidHueChange(color,114, 16);
      strip.show();
      }
      else {
        Sonne = 0;
        strip.fill(green, 114, 16);
        // strip.fill(yello, 114, 16);
        digitalWrite(WolkenMagnet, HIGH);
        }


  Nahrung = Sonne * Wasserstand;
  }
    while (Nahrung == 3) {
      CuckooAntenna(2); // mit nextem Status als Argument
      // RapidHueChange(color,115, 16);
      // EnergyRun(); 
      // strip.show();
  
     
    }


  }
  
/*************************************************************************************/
while (OverallState == 2) {
  while (Nahrung != 3) {
  

  strip.show();
  WasserSensor_1 = digitalRead(WasserLochIn_1);
  WasserSensor_2 = digitalRead(WasserLochIn_2);
  WasserSensor_3 = digitalRead(WasserLochIn_3);
  WasserSensor_4 = digitalRead(WasserLochIn_4);
  WasserSensor_5 = digitalRead(WasserLochIn_5);
  WasserSensor_6 = digitalRead(WasserLochIn_6);
    if (!WasserSensor_2 == 0) {                     // hier jetzt 2, 4, und 6
      BlinkLED(blue, 5, 5);
      } 
   else { 
        strip.fill(blue, 5, 5);
          strip.show();
      } 
   if (!WasserSensor_4 == 0) {
      BlinkLED(blue, 15, 5);
      } 
   else { 
        strip.fill(blue, 15, 5);
          strip.show();
      } 
   if (!WasserSensor_6 == 0) {
      BlinkLED(blue, 25, 5);
      } 
   else { 
        strip.fill(blue, 25, 5);
          strip.show();
      }
// Wasserstand LED Strip
  Wasserstand = !WasserSensor_2 + !WasserSensor_4 + !WasserSensor_6;

    if (Wasserstand == 0) {                     
      PixelRun(blue, 30, 17);           // standard wasser stand von 30 bis 47
      strip.show();
    }
    if (Wasserstand == 1) {
        PixelRun(blue, 30, 34);         // run von 30 an 34 pixel
        strip.fill(off, 65, 51);        // von 100 + 16 pxl sind blatt adern
        strip.show();
        } 
    if (Wasserstand == 2) {
        PixelRun(blue, 30, 52);
        strip.fill(off, 83, 33);        
        
        } 
      if ((Wasserstand == 3)) {     // && (Nahrung == 0)
        PixelRun(blue, 30, 69);     // nur wenn sonne nicht strahlt isses blau
        strip.show();
        } 
        if ((Wasserstand == 3) && (Nahrung == 0)) {
          strip.fill(blue, 100, 16);   
           strip.show();          
        }
// Sonne

WolkenSwitchSens = digitalRead(WolkenSwitch);

  if (!WolkenSwitchSens) {          //  negation des Schalters
      Sonne = 1;
      digitalWrite(WolkenMagnet, LOW);
      RapidHueChange(color,114, 16);
      strip.show();
      }
      else {
        Sonne = 0;
        strip.fill(green, 114, 16);
        digitalWrite(WolkenMagnet, HIGH);
        }


  Nahrung = Sonne * Wasserstand;
  }
   while (Nahrung == 3) {
      CuckooAntenna(1); // mit nextem Status als Argument
      // RapidHueChange(color,115, 16);
      // EnergyRun(); 
      // strip.show();
    
    }


  }
}

  
