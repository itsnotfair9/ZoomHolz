void BlinkLED(uint32_t color, int startLED, int lengthLED) {
  const long interval = 12;
  unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      if (BlinkState == LOW) {
      BlinkState = HIGH;
    } else {
      BlinkState = LOW;
    }
    }
      if (BlinkState == HIGH) {
        strip.fill(color, startLED, lengthLED);
        strip.show();
    }
    else if (BlinkState == LOW) {
        strip.fill(off, startLED, lengthLED);
        strip.show();
    }
}




void PixelRun(uint32_t color, int startPixel, int lengthPixel) {
   unsigned long currentMillis = millis();
   unsigned long previousMillis;
   const long interval = 5; // der wartet ja nur einmal bis das interval ueberschritten...
      if (currentMillis - previousMillis >= interval) {
        // der ganze if block updated jedes "interval" also 250 ms
        // idee ist: von startPixel bis startPixel+lengthPixel wird raufgezaehlt
      previousMillis = currentMillis;
      strip.fill(off, (startPixel), (lengthPixel));
            counter = counter % lengthPixel;   // von 0 bis length
            pixel = counter + startPixel;
            strip.setPixelColor(pixel, color);
            strip.setPixelColor((pixel+1), color);
            strip.setPixelColor((pixel+2), color);
            strip.show();
            counter++;
  }
}

void RapidHueChange(uint32_t color, int startPixel, int lengthPixel) {
  

    randNumber = random(16);
    // randNumber = randNumber%16;
    RndColor = ColorArray[randNumber];
    // Serial.println((String)"RND "+RndColor);
    color = strip.ColorHSV(RndColor*256, 255, 255);
    strip.fill(color, startPixel, lengthPixel);
    strip.show();
    // randNumber++;
  }


void EnergyRun() {
  const long interval = 12;
     unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= interval) {
          // der ganze if block updated jedes "interval" also 250 ms
        previousMillis = currentMillis;
    strip.fill(off, 128, 99);
             counter01 = counter01 % 73;      // 73 = ast(45_led)+stammUnten(28_led)
              if (counter01 < 45) {           // solange es am ast ist, keine spaltung
              pixel = (counter01 % 99) + 128; // 99 sind alle Energy LEDs (45+28+26), angefangen bei led# 144
                 strip.setPixelColor(pixel, red);
              }
               
              if (counter01 >= 45) {             // nach Ast, spaltung oben/unten
              pixel_2 = counter01 + 155;        //227 = ganzer Strip - 72 (energy part)
              //Serial.println((String)"count "+counter01);
              strip.setPixelColor(pixel_2, red);
              pixel_3 = 198 - (counter01 - 45); // 128 + 45 + 26 - 1
              if (pixel_3 >= 173) {             // 128 (enery start) + 45 (ast portion) = 
              strip.setPixelColor(pixel_3, red);
              }
                }
              strip.show();
              counter01++;
    }
  }
/* die blob idee: zaehl von 1 bis 5 ... 5 ist die blob distance
 wenn 5 erreicht ist, addiere 5 dazu, zaehle also von 6 - 10 und von 1 - 5
*/
void BlobRun(uint32_t color, int startPixel, int lengthPixel, int blobDistance) {
   currentMillis = millis();
   const long interval = 75;
      if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
       while (b_count <= blobDistance){
        while (a_count <= lengthPixel) {
           
          a_count = a_count+blobDistance;
          pixel = ((a_count + b_count) - blobDistance) + startPixel;
          if ((pixel >= startPixel) || (pixel <= startPixel + lengthPixel)) {
              strip.setPixelColor(pixel, blue);
              strip.show();
              //Serial.print(pixel+(String)' ');
          }
        
          a_count++;    
        }
        a_count = 0;
//        Serial.println();
        b_count++;
        //strip.show();
        strip.fill(off, startPixel, lengthPixel);
       }
       b_count = 0;
      }
}

void CuckooAntenna(int nextState) {

  BirdCurrentMillis = millis();
  
  if ((BirdCurrentMillis - BirdPreviousMillis) >= BirdInterval) {
       sec++;
       counter01++;
      //  Serial.println((String)"counter01 "+counter01);
       BirdPreviousMillis = BirdCurrentMillis;
  };
 
  

/*
sec 0) AntenneRaus + SoundTriggerOn
sec 4) ast raus -> uberall +4
sec 14) cockoo raus (pol1, strom an)
sec 15) strom aus
sec 16) cuckoo nick 1
sec 17) cockoo up
sec 20) cockoo nick 2
sec 21) cockoo up
sec 24) cockoo rein (pol2, strom an)
sec 25) strom aus
sec 30) ast rein, SoundTriggerOff
sec 80) nach wartezeit startet loop
*/

if (sec == 1) {
  digitalWrite(KuckuckSound, LOW); // sound on
  // strip.fill(off,114, 16);
  strip.fill(red, 100, 16);       // die Blatt Adern
  strip.fill(blue, 30, 69);       //  die wasser zufuhr
  strip.show();
  RunEnergy = 1;
}

if (sec == 10){
  digitalWrite(KuckuckSound, HIGH); // sound trigger off
}

if (sec == 40) { //120
  digitalWrite(AstWachstum, LOW); //Ast ausfahren
  // Serial.println((String)"counter "+sec);
}

if (sec == 120) {
  // Serial.println((String)"counter "+sec);
  digitalWrite(PolSchalter, LOW);  // motor rausfahren
  digitalWrite(StromVersorger, LOW);// strom an
};

if (sec == 130) {
  digitalWrite(StromVersorger, HIGH);// strom aus
};
// Bird outside
if (sec == 180){
  digitalWrite(BirdMove, LOW); // Bird nick
};
if (sec == 190){
  digitalWrite(BirdMove, HIGH); // Bird up
};
if (sec == 215){
  digitalWrite(BirdMove, LOW); // Bird nick
};
if (sec == 225){
  digitalWrite(BirdMove, HIGH); // Bird up
};

if (sec == 260) {
  digitalWrite(PolSchalter, HIGH);  // motor reinfahren
  digitalWrite(StromVersorger, LOW);// strom an
};

if (sec == 270) {
  digitalWrite(StromVersorger, HIGH);// strom aus
};
if (sec == 310) {
  digitalWrite(AstWachstum, HIGH); // Ast reinfahren
  // digitalWrite(WolkenMagnet, HIGH); // wolke rueckfahren, wird aber ohnein abgefragt bei "sonne"   
};
  
if (sec == 450){
  RunEnergy = 0;
  strip.fill(off, 0, 227);
  strip.show();
};

if (sec == 490){//wartezeit vor begin
  sec = 0;
  Nahrung = 0;
  Sonne = 0;
  Wasserstand = 0;
  OverallState = nextState;
};

if (RunEnergy) {
    // strip.fill(off, 128, 99);
    strip.fill(off, 114, 115);
             counter01 = counter01 % 73;      // 73 = ast(45_led)+stammUnten(28_led)
              if (counter01 < 45) {           // solange es am ast ist, keine spaltung
              pixel = (counter01 % 99) + 128; // 99 sind alle Energy LEDs (45+28+26), angefangen bei led# 144
                 strip.setPixelColor(pixel, red);
              }
               
              if (counter01 >= 45) {             // nach Ast, spaltung oben/unten
              pixel_2 = counter01 + 155;        //227 = ganzer Strip - 72 (energy part)
              
              strip.setPixelColor(pixel_2, red);
              pixel_3 = 198 - (counter01 - 45); // 128 + 45 + 26 - 1
              if (pixel_3 >= 173) {             // 128 (enery start) + 45 (ast portion) = 
              strip.setPixelColor(pixel_3, red);
              }
                }
              randNumber = random(16);
              RndColor = ColorArray[randNumber];
              color = strip.ColorHSV(RndColor*256, 255, 255);
              strip.fill(color, 114, 16);
              strip.show();
              
  }

}
