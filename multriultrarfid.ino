#include <SPI.h>
#include <MFRC522.h>
#include<LoRa.h>
 
#define SS_PIN 25
#define RST_PIN 5
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
volatile int state = HIGH;

#define trigPin1 27
#define echoPin1 33
#define trigPin2 26
#define echoPin2 32
#define trigPin3 28
#define echoPin3 34

#define trigPin4 29
#define echoPin4 35
#define trigPin5 30
#define echoPin5 36
#define trigPin6 31
#define echoPin6 37

long duration, distance, RightSensor1,TopSensor1,LeftSensor1,RightSensor2,TopSensor2,LeftSensor2;
int counter1 = 0,counter2 = 0;
int current1Statefor2 = 0,current1Statefor4 = 0,current1Statefor8 = 0,current2Statefor2 = 0,current2Statefor4 = 0,current2Statefor8 = 0;
int previousState = 0;
int x=0,y=0,m=0,n=0;

void setup()
{
Serial.begin (9600);
while (!Serial);

  Serial.println("LoRa Sender");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);

pinMode(trigPin4, OUTPUT);
pinMode(echoPin4, INPUT);
pinMode(trigPin5, OUTPUT);
pinMode(echoPin5, INPUT);
pinMode(trigPin6, OUTPUT);
pinMode(echoPin6, INPUT);

  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
  pinMode(3, OUTPUT);//Interrupt
  pinMode(3, HIGH);


  
}

void loop() {
 readSensor1();
 readSensor2();
 readRFID();
 }
void readSensor1(){
SonarSensor(trigPin1, echoPin1);
RightSensor1 = distance;
SonarSensor(trigPin2, echoPin2);
TopSensor1 = distance;
SonarSensor(trigPin3, echoPin3);
LeftSensor1 = distance;

/*Serial.print(LeftSensor1);
Serial.print(" - ");
Serial.print(TopSensor1);
Serial.print(" - ");
Serial.print(RightSensor1);
Serial.print(" - ");
Serial.print(LeftSensor2);
Serial.print(" - ");
Serial.print(TopSensor2);
Serial.print(" - ");
Serial.println(RightSensor2);*/
//Serial.println("c1");
int width = 14 - (LeftSensor1+RightSensor1);
int height = 18-TopSensor1;

if(width>=0){
  x=1;
}

if ((width <= 6)&&(width>=0)){ 
 current1Statefor2 = 1;
 }
 else if((width <= 14)&&(width > 6)) 
 {
 if((height >= 12)&&(height <= 20)){
    current1Statefor8 = 1;
 }
 else
    current1Statefor4 = 1;
 }
 else{
  current1Statefor2 = 0;
  current1Statefor4 = 0;
  current1Statefor8 = 0;
 }
 //delay(100);
 
if(width<=0){
  y=1;
}

if(current1Statefor2 != previousState){
if(current1Statefor2 == 1){
  if((x==1)&&(y==1)){
    counter1 = counter1 + 1;
    x=0;y=0;
    }

Serial.println(counter1);
    }
  }
 if(current1Statefor4 != previousState){
if(current1Statefor4 == 1){
 if((x==1)&&(y==1)){
    counter1 = counter1 + 2;
    x=0;y=0;
    }
Serial.println(counter1);
    }
  }
 if(current1Statefor8 != previousState){
if(current1Statefor8 == 1){
 if((x==1)&&(y==1)){
    counter1 = counter1 + 4;
    x=0;y=0;
    }
Serial.println(counter1);
    }
  }
LoRa.beginPacket();
  //LoRa.print("hello ");
  LoRa.print(counter1*10+1);
  LoRa.endPacket();
//delay(2000);

}

void readSensor2(){
SonarSensor(trigPin4, echoPin4);
RightSensor2 = distance;
SonarSensor(trigPin5, echoPin5);
TopSensor2 = distance;
SonarSensor(trigPin6, echoPin6);
LeftSensor2 = distance;
//Serial.println("c2");
/*Serial.print(LeftSensor1);
Serial.print(" - ");
Serial.print(TopSensor1);
Serial.print(" - ");
Serial.print(RightSensor1);
Serial.print(" - ");
Serial.print(LeftSensor2);
Serial.print(" - ");
Serial.print(TopSensor2);
Serial.print(" - ");
Serial.println(RightSensor2);*/

int width = 14 - (LeftSensor2+RightSensor2);
int height = 18-TopSensor2;

if(width>=0){
  m=1;
}

if ((width <= 6)&&(width>=0)){ 
 current2Statefor2 = 1;
 }
 else if((width <= 14)&&(width > 6)) 
 {
 if((height >= 12)&&(height <= 20)){
    current2Statefor8 = 1;
 }
 else
    current2Statefor4 = 1;
 }
 else{
  current2Statefor2 = 0;
  current2Statefor4 = 0;
  current2Statefor8 = 0;
 }
 //delay(100);
 
if(width<=0){
  n=1;
}

if(current2Statefor2 != previousState){
if(current2Statefor2 == 1){
  if((m==1)&&(n==1)){
    counter2 = counter2 + 1;
    m=0;n=0;
    }

Serial.println(counter2);
    }
  }
 if(current2Statefor4 != previousState){
if(current2Statefor4 == 1){
 if((m==1)&&(n==1)){
    counter2 = counter2 + 2;
    m=0;n=0;
    }
Serial.println(counter2);
    }
  }
 if(current2Statefor8 != previousState){
if(current2Statefor8 == 1){
 if((m==1)&&(n==1)){
    counter2 = counter2 + 4;
    m=0;n=0;
    }
Serial.println(counter2*10+1);
    }
  }
  LoRa.beginPacket();
  //LoRa.print("hello ");
  LoRa.print(counter2*10+2);//lora2222222222222222222222222222
  LoRa.endPacket();


//delay(2000);
}
void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(100000);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;

}

void readRFID()
{
  Serial.print("qwerty");
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "60 41 80 A6") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println(state);
    state=!state;
    Serial.println(state);
    pinMode(3, state);
    delay(3000);
    
  }
 
 else   {
    Serial.println(" Access denied");
    //delay(3000);
  }
}
