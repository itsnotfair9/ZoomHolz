/*
int ledPin = 13;      // LED connected to digital pin 9
int receivePin = 2;   // potentiometer connected to analog pin 3
int val = 0;         // variable to store the read value
int video = 0;
int counter;
unsigned long timestamp;
unsigned long duration;
// Relay switch
int Play_01;
int Play_02;
int Play_03;
int Play_04;

int TrigPlay_01 = 4;
int TrigPlay_02 = 5;
int TrigPlay_03 = 6;
int TrigPlay_04 = 7;

void setup() {
  // relay switch
  pinMode(TrigPlay_01, OUTPUT);  // sets the pin as output
  pinMode(TrigPlay_02, OUTPUT);  
  pinMode(TrigPlay_03, OUTPUT);  
  pinMode(TrigPlay_04, OUTPUT); 
  
  digitalWrite(TrigPlay_01, HIGH); 
  digitalWrite(TrigPlay_02, HIGH);
  digitalWrite(TrigPlay_03, HIGH); 
  digitalWrite(TrigPlay_04, HIGH); 
  
  pinMode(ledPin, OUTPUT);  // sets the pin as output
  pinMode(receivePin, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("waiting for time-encodes input on pin 2");
}

void loop() {
  counter = 0;
  val = digitalRead (receivePin);
  while(val) {
    counter++;
    
    //Serial.println(counter);
    val = digitalRead (receivePin);
    delay(10);
    }
    if (counter == 2) 
      {
        video = 1;
        Serial.println(video);
        digitalWrite(TrigPlay_01, LOW);
        delay(100);
        digitalWrite(TrigPlay_01, HIGH);
      }
    if (counter == 3) 
      {
        video = 2;
        Serial.println(video);
        digitalWrite(TrigPlay_02, LOW);
        delay(100);
        digitalWrite(TrigPlay_02, HIGH);
      
      }
    if (counter == 4)
      {
        video = 3;
        Serial.println(video);
        digitalWrite(TrigPlay_03, LOW);
        delay(100);
        digitalWrite(TrigPlay_03, HIGH);
        }
    if (counter == 5) 
      {
         video = 4;
         Serial.println(video);
         digitalWrite(TrigPlay_04, LOW);
        delay(100);
        digitalWrite(TrigPlay_04, HIGH);
         }
  }

*/
