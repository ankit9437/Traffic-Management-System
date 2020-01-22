#include <SPI.h>
#include <LoRa.h>
#include <MFRC522.h>
#include <math.h>
char temp;


double t=0;
#define SS_PIN 35
#define RST_PIN 36
MFRC522 mfrc522(SS_PIN, RST_PIN);
int Lane1[] = {33,32,31}; // Lane 1 Red, Yellow and Green
int Lane2[] = {30,29,28};// Lane 2 Red, Yellow and Green
int Lane3[] = {27,26,25};// Lane 3 Red, Yellow and Green
int Lane4[] = {24,23,22};// Lane 4 Red, Yellow and Green
int t1=3;
int t2=3;
int t3=3;
int t4=3;
int x1=0,x2=0,x3=0,x4=0,y1=0,y2=0,y3=0,y4=0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Receiver");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }



  for (int i = 0; i < 3; i++)
  {
    pinMode(Lane1[i], OUTPUT);
    pinMode(Lane2[i], OUTPUT);
    pinMode(Lane3[i], OUTPUT);
    pinMode(Lane4[i], OUTPUT);
  }






   for (int i = 0; i < 3; i++)
  {
    digitalWrite(Lane1[i], LOW);
    digitalWrite(Lane2[i], LOW);
    digitalWrite(Lane3[i], LOW);
    digitalWrite(Lane4[i], LOW);
  }






 attachInterrupt(digitalPinToInterrupt(21), blink, CHANGE);
// attachInterrupt(digitalPinToInterrupt(3), ISRR, CHANGE);
 // attachInterrupt(digitalPinToInterrupt(3), blink2, CHANGE);



}
void loop(){
  long long int i;
  int j;
  loraa();
  tim1(x1-y1);
 


 digitalWrite(Lane1[0], LOW);
   digitalWrite(Lane1[1], LOW);
   digitalWrite(Lane1[2], HIGH);
   digitalWrite(Lane3[0], HIGH);
   digitalWrite(Lane3[1], LOW);
   digitalWrite(Lane3[2], LOW);
   digitalWrite(Lane4[0], HIGH);
   digitalWrite(Lane4[1], LOW);
   digitalWrite(Lane4[2], LOW);
   digitalWrite(Lane2[0], HIGH);
   digitalWrite(Lane2[1], LOW);
   digitalWrite(Lane2[2], LOW);
   Serial.println("state 1");
   
   for(j=0;j<t1;j++){
    Serial.print("t1-");
    Serial.println(t1);
  for(i=0;i<11428;i++)
  loraa();}
  digitalWrite(Lane1[0], LOW);
   digitalWrite(Lane1[1], HIGH);
   digitalWrite(Lane1[2], LOW);
   digitalWrite(Lane3[0], HIGH);
   digitalWrite(Lane3[1], LOW);
   digitalWrite(Lane3[2], LOW);
   digitalWrite(Lane4[0], HIGH);
   digitalWrite(Lane4[1], LOW);
   digitalWrite(Lane4[2], LOW);
   digitalWrite(Lane2[0], HIGH);
   digitalWrite(Lane2[1], LOW);
   digitalWrite(Lane2[2], LOW);
   Serial.println("state 2");
  for(j=0;j<3;j++){
  for(i=0;i<11428;i++)
  loraa();}

  if((x1-y1)>=5){
    y1=5+y1;
    }
    else{
      y1=x1;
    }
  tim2(x2-y2);
  digitalWrite(Lane1[0], HIGH);
   digitalWrite(Lane1[1], LOW);
   digitalWrite(Lane1[2], LOW);
   digitalWrite(Lane3[0], LOW);
   digitalWrite(Lane3[1], LOW);
   digitalWrite(Lane3[2], HIGH);
   digitalWrite(Lane4[0], HIGH);
   digitalWrite(Lane4[1], LOW);
   digitalWrite(Lane4[2], LOW);
   digitalWrite(Lane2[0], HIGH);
   digitalWrite(Lane2[1], LOW);
   digitalWrite(Lane2[2], LOW);
   Serial.println("state 3");
  for(j=0;j<t2;j++){
  for(i=0;i<11428;i++)
  loraa();}
  digitalWrite(Lane1[0], HIGH);
   digitalWrite(Lane1[1], LOW);
   digitalWrite(Lane1[2], LOW);
   digitalWrite(Lane3[0], LOW);
   digitalWrite(Lane3[1], HIGH);
   digitalWrite(Lane3[2], LOW);
   digitalWrite(Lane4[0], HIGH);
   digitalWrite(Lane4[1], LOW);
   digitalWrite(Lane4[2], LOW);
   digitalWrite(Lane2[0], HIGH);
   digitalWrite(Lane2[1], LOW);
   digitalWrite(Lane2[2], LOW);
   Serial.println("state 4");
  for(j=0;j<3;j++){
  for(i=0;i<11428;i++)
  loraa();}

  if((x2-y2)>=10){
    y2=5+y2;
    }
    else{
      y2=x2;
    }
   tim3(x3-y3); 
  digitalWrite(Lane1[0], HIGH);
   digitalWrite(Lane1[1], LOW);
   digitalWrite(Lane1[2], LOW);
   digitalWrite(Lane3[0], HIGH);
   digitalWrite(Lane3[1], LOW);
   digitalWrite(Lane3[2], LOW);
   digitalWrite(Lane4[0], LOW);
   digitalWrite(Lane4[1], LOW);
   digitalWrite(Lane4[2], HIGH);
   digitalWrite(Lane2[0], HIGH);
   digitalWrite(Lane2[1], LOW);
   digitalWrite(Lane2[2], LOW);
   Serial.println("state 5");
  for(j=0;j<t3;j++){
  for(i=0;i<11428;i++)
  loraa();}

  digitalWrite(Lane1[0], HIGH);
   digitalWrite(Lane1[1], LOW);
   digitalWrite(Lane1[2], LOW);
   digitalWrite(Lane3[0], HIGH);
   digitalWrite(Lane3[1], LOW);
   digitalWrite(Lane3[2], LOW);
   digitalWrite(Lane4[0], LOW);
   digitalWrite(Lane4[1], HIGH);
   digitalWrite(Lane4[2], LOW);
   digitalWrite(Lane2[0], HIGH);
   digitalWrite(Lane2[1], LOW);
   digitalWrite(Lane2[2], LOW);
   Serial.println("state 6");
  for(j=0;j<3;j++){
  for(i=0;i<11428;i++)
  loraa();}

  if((x3-y3)>=5){
    y3=5+y3;
    }
    else{
      y3=x3;
    }
    tim4(x4-y4);
  digitalWrite(Lane1[0], HIGH);
   digitalWrite(Lane1[1], LOW);
   digitalWrite(Lane1[2], LOW);
   digitalWrite(Lane3[0], HIGH);
   digitalWrite(Lane3[1], LOW);
   digitalWrite(Lane3[2], LOW);
   digitalWrite(Lane4[0], HIGH);
   digitalWrite(Lane4[1], LOW);
   digitalWrite(Lane4[2], LOW);
   digitalWrite(Lane2[0], LOW);
   digitalWrite(Lane2[1], LOW);
   digitalWrite(Lane2[2], HIGH);
   Serial.println("state 7");
   for(j=0;j<t4;j++){
  for(i=0;i<11428;i++)
  loraa();}
  digitalWrite(Lane1[0], HIGH);
   digitalWrite(Lane1[1], LOW);
   digitalWrite(Lane1[2], LOW);
   digitalWrite(Lane3[0], HIGH);
   digitalWrite(Lane3[1], LOW);
   digitalWrite(Lane3[2], LOW);
   digitalWrite(Lane4[0], HIGH);
   digitalWrite(Lane4[1], LOW);
   digitalWrite(Lane4[2], LOW);
   digitalWrite(Lane2[0], LOW);
   digitalWrite(Lane2[1], HIGH);
   digitalWrite(Lane2[2], LOW);
   Serial.println("state 8");
  for(j=0;j<3;j++){
  for(i=0;i<11428;i++)
  loraa();}
  if((x4-y4)>=5){
    y4=5+y4;
    }
    else{
      y4=x4;
    }  
}












void loraa() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  int sizee = packetSize;
  
  if (packetSize) {
    // received a packet
    //Serial.println("Received packet ");

    // read packet
    while (LoRa.available()) {
     // Serial.print((char)LoRa.read());
      double q = 0;      
      temp=(char)LoRa.read();
      q = temp - '0';
      sizee--;
      t = t + q*(pow(10,sizee));  

    }
    //Serial.print("t");
    //Serial.println(t);

    int q = (int)t;
    //Serial.println(q);
    if((q%10==0)){q=q+1;}
    //Serial.println(q);
    if(q%10==1){
      //Serial.println(t);
      t=t/10;
      //Serial.println("lane1-");
      //Serial.println(floor(t));
      x1 = floor(t);
      Serial.println("");
      Serial.println(x1);
      }
      if(q%10==2) {
         //Serial.println(t);
        t=t/10;
        //Serial.print("lane2-");
      //Serial.println(floor(t));
      x2 = floor(t);
        }
       if(q%10==3) {
         //Serial.println(t);
        t=t/10;
        //Serial.print("lane3-");
      //Serial.println(floor(t));
      x3 = floor(t);
        }
        if(q%10==4) {
         //Serial.println(t);
        t=t/10;
        //Serial.print("lane4-");
      //Serial.println(floor(t));
      x4 = floor(t);
        }
     
    t=0;
   }



}







void tim1(double cn1){
  int timee;
    if(cn1<=1){
      timee=4;
    }
    else if(cn1>5){
      timee=30;
    }
    else{
      timee=(int)30*cn1/5;
    }
      t1=timee;
    }
void tim2(double cn2){
  int timee;
    if(cn2<=1){
      timee=4;
    }
        else if(cn2>5){
      timee=30;
    }
    else{
      timee=(int)30*cn2/5;
    }
      t2=timee;
    }
  void tim3(double cn3){
  int timee;
    if(cn3<=1){
      timee=4;
    }
        else if(cn3>5){
      timee=30;
    }
    else{
      timee=(int)30*cn3/5;
    }
      t3=timee;
    }
 void tim4(double cn4){
  int timee;
    if(cn4<=1){
      timee=4;
    }
        else if(cn4>5){
      timee=30;
    }
    else{
      timee=(int)30*cn4/5;
    }
      t4=timee;
    } 


    











void blink() {
  int j;
  long long int i;
   //ISR function
  //Serial.println("state");
   digitalWrite(Lane1[2], HIGH);
   digitalWrite(Lane1[0], LOW);
   digitalWrite(Lane1[1], LOW);
   digitalWrite(Lane3[0], HIGH);
   digitalWrite(Lane3[1], LOW);
   digitalWrite(Lane3[2], LOW);
   digitalWrite(Lane4[0], HIGH);
   digitalWrite(Lane4[1], LOW);
   digitalWrite(Lane4[2], LOW);
   digitalWrite(Lane2[0], HIGH);
   digitalWrite(Lane2[2], LOW);
   digitalWrite(Lane2[1], LOW);
  for(j=0;j<20;j++){
  for(i=0;i<11428;i++)
  loraa();}

  digitalWrite(Lane1[2], LOW);
   digitalWrite(Lane1[0], LOW);
   digitalWrite(Lane1[1], HIGH);
   digitalWrite(Lane3[0], HIGH);
   digitalWrite(Lane3[1], LOW);
   digitalWrite(Lane3[2], LOW);
   digitalWrite(Lane4[0], HIGH);
   digitalWrite(Lane4[1], LOW);
   digitalWrite(Lane4[2], LOW);
   digitalWrite(Lane2[0], HIGH);
   digitalWrite(Lane2[2], LOW);
   digitalWrite(Lane2[1], LOW);
  for(j=0;j<3;j++){
  for(i=0;i<11428;i++)
  loraa();}
  // Serial.println("state");
  }




  
  






//void ISRR() {
//  int j;
//  long long int i;
//   //ISR function
//  //Serial.println("state");
//   digitalWrite(Lane1[2], LOW);
//   digitalWrite(Lane1[0], HIGH);
//   digitalWrite(Lane1[1], LOW);
//   digitalWrite(Lane3[0], LOW);
//   digitalWrite(Lane3[1], LOW);
//   digitalWrite(Lane3[2], HIGH);
//   digitalWrite(Lane4[0], HIGH);
//   digitalWrite(Lane4[1], LOW);
//   digitalWrite(Lane4[2], LOW);
//   digitalWrite(Lane2[0], HIGH);
//   digitalWrite(Lane2[2], LOW);
//   digitalWrite(Lane2[1], LOW);
//  for(j=0;j<7;j++){
//  for(i=0;i<11428;i++)
//  loraa();}
//}
////  digitalWrite(Lane1[2], LOW);
////   digitalWrite(Lane1[0], HIGH);
////   digitalWrite(Lane1[1], LOW);
////   digitalWrite(Lane3[0], LOW);
////   digitalWrite(Lane3[1], HIGH);
////   digitalWrite(Lane3[2], LOW);
////   digitalWrite(Lane4[0], HIGH);
////   digitalWrite(Lane4[1], LOW);
////   digitalWrite(Lane4[2], LOW);
////   digitalWrite(Lane2[0], HIGH);
////   digitalWrite(Lane2[2], LOW);
////   digitalWrite(Lane2[1], LOW);
////  for(j=0;j<3;j++){
////  for(i=0;i<11428;i++)
////  loraa();}
////  // Serial.println("state");
////}
