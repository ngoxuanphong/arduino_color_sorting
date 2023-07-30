#include <Servo.h>
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6
Servo microServo;
int frequency = 0;
int color=0;
String dulieu= "";
int myList[] = {0, 0, 0, 0, 0};
int listSize = sizeof(myList) / sizeof(myList[0]);

const int dirPin = 12; // Cam
const int stepPin = 13; // Tim
const int stepsPerRevolution = 200;

void setup() {
    pinMode(S0, OUTPUT);
    pinMode(S1, OUTPUT);
    pinMode(S2, OUTPUT);
    pinMode(S3, OUTPUT);
    pinMode(sensorOut, INPUT);
    // Setting frequency-scaling to 20%
    digitalWrite(S0, HIGH);
    digitalWrite(S1, LOW);
    
    microServo.attach(9);
    Serial.begin(9600);

    pinMode(stepPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
    digitalWrite(dirPin, LOW); //STEP motor (Low ngược chiều, Hight cùng chiều)
}

int runcode() {
    
//     Spin motor slowly
    for(int x = 0; x < 25; x++)
    {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(5000);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(5000);
    }
    delay(1000); // Wait a second
  
    switch (color) {
      case 1:
      microServo.write(40);
      break;
      case 2:
      microServo.write(70);
      break;
      case 3:
      microServo.write(100);
      break;
      case 4:
      microServo.write(130);
      break;
      case 0:
      microServo.write(0);
      break;
  }
  myList[color] += 1;
  if (myList[color] == 100){
    myList[color] = 0;
  }
  color=0;
  delay(500);
}

void loop() {
  String dulieu_temp= Serial.readString();
  if (dulieu_temp != "") {
    dulieu = dulieu_temp;
  }
  
  color = readColor();
  Serial.print(color);
  Serial.print("---");
  for (int i = 0; i < listSize; i++) {
    if (myList[i] < 10){
      Serial.print(0);
    }
    Serial.print(myList[i]);
    if (i != listSize-1) {
      Serial.print("-");
    }
  }
  Serial.println("");
  delay(10);  
    
  if(dulieu.startsWith("B")) { 
    runcode();
  }
  if(dulieu.startsWith("R")) { 
    for (int i = 0; i < listSize; i++) {
      myList[i] = 0;
      }
    }
}
// Custom Function - readColor()

int readColor() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
  delay(50);

  
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  delay(50);

  
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;

  
//   Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(R);//printing RED color frequency
  Serial.print("  ");
  Serial.print("G= ");//printing name
  Serial.print(G);//printing RED color frequency
  Serial.print("  ");
  Serial.print("B= ");//printing name
  Serial.print(B);//printing RED color frequency
  Serial.println("  ");

  delay(50);

  
  if( R>240 & R<270 & G>200 & G<240  & B > 250 & B< 290){
    color = 1; // green // xanh la
  }
  if(R>190 & R<220 & G>330 & G < 360 & B > 290 & B< 330){
    color = 2; // red 
  }
  if(R>100 & R <130& G>150 & G < 190 & B > 200 & B<240){
    color = 3; // yellow
  }
  if(R > 300 & R<390 & G > 200 & G< 400 & B>250 & B<330){
    color = 4; // blue // xanh da troi
  }
  return color;  
}
