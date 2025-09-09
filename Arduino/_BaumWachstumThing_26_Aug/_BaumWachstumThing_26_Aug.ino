/******************************************************************************
QRD1114_Proximity_Example.ino
Example sketch for SparkFun's QRD1114 Reflectance Proximity Sensor
  (https://www.sparkfun.com/products/246)
Jim Lindblom @ SparkFun Electronics
May 2, 2016

Connect a QRD1114, 330 resistor and 10k resistor as follows:

QRD1114 Pin ---- Arduino ---- Resistors
    1              A0      10k Pull-up to 5V
    2              GND
    3                      330 Resistor to 5V
    4              GND

As an object comes closer to the QRD1114, the voltage on A0 should go down.

1) Sensor wird detektiert.
2) random, bzw. URN zahl von 1-4 auswaehlen
    dies entspricht dem Baum: abhaengig vom vom gewaehlten Baum 
    wachsen leuchten dann die Jahresringe.
3) Baumscheibe laufen lassen
    a) ganz schnell von aussen nach innen
    b) alle 2 sek. ein neuer Jahresring - dauert also 24 sec.
    c) 10 sek. leuchten lassen
    d) innert 2 sek von innen nach aussen ausschalten

******************************************************************************/
const int sens1 = A0;
const int sens2 = A1;// Sensor output voltage
const int sendRND = A2;
int counter;
int SensorCounter;
// SendToVideo varaiable
const int SendPin =  51;      // the number of the Send pin
int VideoSelect;             // es ist kein random video, sondern geht alle einmal durch
int SendVideo = 0;
int Thrsld_01 = 0;
int Thrsld_02 = 0;
int Calib_01 = 0;
int Calib_02 = 0;

// Mosfet pins ......der pin2 duerfte da ueberhaupt kaputt sein, am arduino
const int ring01 = 52;
const int ring02 = 50;
const int ring03 = 48;
const int ring04 = 46;
const int ring05 = 44;
const int ring06 = 42;
const int ring07 = 40;
const int ring08 = 38;
const int ring09 = 36;
const int ring10 = 34;
const int ring11 = 32;
const int ring12 = 30;
// serial com
char receivedChar;
// timing
int ContractSpeed = 33;

void setup() 
{
  Serial.begin(9600);
  Serial.println("Die Leuchtende Baumscheibe All good :-)");
  pinMode(sens1, INPUT);
  pinMode(sens2, INPUT);
  pinMode(sendRND, OUTPUT);
  pinMode(ring01, OUTPUT);
  pinMode(ring02, OUTPUT);
  pinMode(ring03, OUTPUT);
  pinMode(ring04, OUTPUT);
  pinMode(ring05, OUTPUT);
  pinMode(ring06, OUTPUT);
  pinMode(ring07, OUTPUT);
  pinMode(ring08, OUTPUT);
  pinMode(ring09, OUTPUT);
  pinMode(ring10, OUTPUT);
  pinMode(ring11, OUTPUT);
  pinMode(ring12, OUTPUT);
  pinMode(SendPin, OUTPUT);
  counter = 0;
  SensorCounter = 0;
  digitalWrite(SendPin, LOW);

// thresholds
  Thrsld_01 = analogRead(sens1);
  Thrsld_02 = analogRead(sens2);
  Calib_01 = Thrsld_01 - 70;
  Calib_02 = Thrsld_02 - 70;
  Serial.println((String)"Calibration_1 "+Calib_01);
  Serial.println((String)"Calibration_2 "+Calib_02);
}

void loop() 
{
  // Read in the ADC and convert it to a voltage:
  int sens2_val = analogRead(sens2); // 190
  int sens1_val = analogRead(sens1); // 130
  // Serial.println((String)"Sensor1 "+sens1_val);
  // Serial.println((String)"Sensor2 "+sens2_val);
  
  //Serial.println(sens1_val);
  
  if (sens1_val <= Calib_01 || sens2_val <= Calib_02)  {
        SensorCounter++;
        receivedChar = 'g';         // sets variable to high, reset only when video is done
        SendVideo = 1;
        Serial.println(SensorCounter);
        Serial.println((String)"Sensor1 "+sens1_val);
        Serial.println((String)"Sensor2 "+sens2_val); 
        delay(150);             // um nicht im vorbeifliegen doppelt auszuloesen
  }
  if (Serial.available() > 0) {
    receivedChar = Serial.read();
  }
  if (receivedChar == 'g') {
    counter++;
    SendToVideo();
    BaumscheibeAnimation();
     delay(1);
          
    
}
  
}
//
//
//void loop(){
//  digitalWrite(ring01, 1);
//  delay(1000);
//    digitalWrite(ring01, 0);
//  delay(1000);
//}
