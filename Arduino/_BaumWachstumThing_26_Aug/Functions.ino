void SendToVideo() {
  while ( SendVideo >= 1) {
  VideoSelect++;
  VideoSelect = VideoSelect%5;
  
   if (VideoSelect == 1) {               // 200 ms pulse
      //receivedChar = 'm';
      Serial.println((String)"Video "+VideoSelect);
       digitalWrite(SendPin, HIGH);
       delay(10);
       digitalWrite(SendPin, LOW);
       SendVideo = 0;
      }
        if (VideoSelect == 2) {               // 400 ms pulse
          //receivedChar = 'm';
        Serial.println((String)"Video "+VideoSelect);
         digitalWrite(SendPin, HIGH);
         delay(20);
         digitalWrite(SendPin, LOW);
         SendVideo = 0;
        }
          if (VideoSelect == 3) {               // 400 ms pulse
            //receivedChar = 'm';
          Serial.println((String)"Video "+VideoSelect);
           digitalWrite(SendPin, HIGH);
           delay(30);
           digitalWrite(SendPin, LOW);
           SendVideo = 0;
          }
             if (VideoSelect == 4) {               // 600 ms pulse
              //receivedChar = 'm';
            Serial.println((String)"Video "+VideoSelect);
             digitalWrite(SendPin, HIGH);
             delay(40);
             digitalWrite(SendPin, LOW);
             SendVideo = 0;
            }
  
        else {
        // turn LED off:
        digitalWrite(SendPin, LOW);
        //Serial.println(buttonState);
        }
  }
}
