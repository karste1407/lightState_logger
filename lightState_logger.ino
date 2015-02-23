
#include <SPI.h>
#include <SD.h>


const int chipSelect = 4;
int ledPin = 8;
File myfile;
String ledState; 

void setup(){
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
  
  
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  pinMode(10, OUTPUT);
}

void loop(){
  Serial.println("turn on LED?");
  Serial.println("enter 1.....?");
  Serial.println("");
  Serial.println("turn off LED?");
  Serial.println("enter 0.....?");
  
  while (Serial.available() == 0);
  
  int val = Serial.read() - '0'; 
  
  if (val == 1) {
    digitalWrite(ledPin, HIGH);
    ledState = "led is on";
  } 
  
  else if (val == 0) {
    digitalWrite(ledPin, LOW);
    ledState = "led is off";
  }
  
  
 
  myfile = SD.open("test.txt", FILE_WRITE);
  Serial.println("///////////////////////////////");
  
  if (myfile) {
    myfile.println(ledState);
    myfile.close();
    Serial.println("sucessfully logged!.");
  
  } else {
    Serial.println("error opening test.txt");
  }
  
 
    Serial.println("");
    Serial.println("////read from SD-card////");
    Serial.println("");
    
    myfile = SD.open("test.txt", FILE_READ);
    
    while (myfile.available()) {
        Serial.write(myfile.read());
      }
    
    myfile.close();
    
    Serial.println("//////////////////////////////");
}



 
