#include <Servo.h>

#define S0 2 // RGB sensor
#define S1 3 // RGB sensor
#define S2 4 // RGB sensor
#define S3 5 // RGB sensor
#define sensorOut 6 // RGB sensor
Servo microServo; // Khai báo biến servo

int frequency = 0; // Đọc tần số
int color=0; // Biến lưu màu
String dulieu= ""; // Biến lưu dữ liệu từ máy tính
int myList[] = {0, 0, 0, 0, 0}; // Mảng lưu số lượng mỗi màu
int listSize = sizeof(myList) / sizeof(myList[0]); // Lấy kích thước mảng myList

const int dirPin = 12; // Dây cam, động cơ bước chân DIR
const int stepPin = 13; // Dây Tím, động cơ bước chân DIR

void setup() {
    // Setting RGB sensor pins as OUTPUT, INPUT
    pinMode(S0, OUTPUT);
    pinMode(S1, OUTPUT);
    pinMode(S2, OUTPUT);
    pinMode(S3, OUTPUT);
    pinMode(sensorOut, INPUT);

    digitalWrite(S0, HIGH);
    digitalWrite(S1, LOW);
    
    // Cài đặt servo vào chân 9
    microServo.attach(9);
    Serial.begin(9600);

    // Cài đặt STEP và DIR của động cơ bước
    pinMode(stepPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
    digitalWrite(dirPin, LOW); //STEP motor (Low ngược chiều, Hight cùng chiều)
}

int runcode() {
    
    //Quay đôngj cơ bước
    for(int x = 0; x < 25; x++)
    {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(5000);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(5000);
    }
    delay(1000); // Delay 1s
  
    switch (color) {
      case 1:
      microServo.write(40); // Góc quay của servo màu xanh lá
      break;
      case 2:
      microServo.write(70); // Góc quay của servo màu đỏ
      break;
      case 3:
      microServo.write(100); // Góc quay của servo màu vàng
      break;
      case 4:
      microServo.write(130); // Góc quay của servo màu xanh dương
      break;
      case 0:
      microServo.write(0); // Góc quay của servo màu không xác định
      break;
  }
  myList[color] += 1; // Tăng số lượng màu lên 1

  // Nếu số lượng màu đạt 100 thì reset về 0
  if (myList[color] == 100){ 
    myList[color] = 0;
  }
  color=0; // Reset màu về 0
  delay(500); // Delay 0.5s
}

// Hàm lặp
void loop() {
  String dulieu_temp= Serial.readString(); // Đọc dữ liệu từ máy tính
  if (dulieu_temp != "") {
    dulieu = dulieu_temp;
  }
  
  color = readColor(); // Gọi hàm đọc màu

  // In ra màn hình màu đọc được
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
    
  // Nếu nhận được dữ liệu từ máy tính thì chạy hàm runcode()
  if(dulieu.startsWith("B")) { 
    runcode();
  }
  // Nếu nhận được dữ liệu từ máy tính thì reset số lượng màu về 0
  if(dulieu.startsWith("R")) { 
    for (int i = 0; i < listSize; i++) {
      myList[i] = 0;
      }
    }
}


int readColor() {
  // Đọc màu đỏ
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
  delay(50);

  
  // Đọc màu xanh lá
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  delay(50);

  
  // Đọc màu xanh dương
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;

  // In ra màn hình giá trị RGB
  Serial.print("R= ");
  Serial.print(R); //Màu đỏ
  Serial.print("  ");
  Serial.print("G= ");
  Serial.print(G); //Màu xanh lá
  Serial.print("  ");
  Serial.print("B= ");
  Serial.print(B); //Màu xanh dương
  Serial.println("  ");

  delay(50);

  
  if( R>240 & R<270 & G>200 & G<240  & B > 250 & B< 290){
    color = 1; // green, xanh la
  }
  if(R>190 & R<220 & G>330 & G < 360 & B > 290 & B< 330){
    color = 2; // red, đỏ
  }
  if(R>100 & R <130& G>150 & G < 190 & B > 200 & B<240){
    color = 3; // yellow, vàng
  }
  if(R > 300 & R<390 & G > 200 & G< 400 & B>250 & B<330){
    color = 4; // blue, xanh da troi
  }
  return color;  
}
