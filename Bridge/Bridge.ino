#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const int MOSI_PIN = 7;
const int MISO_PIN = 6;
const int SCK_PIN = 5;

RF24 radio(9, 10, SCK_IN, MISO_PIN, MOSI_PIN); // CE, CSN, SCK, MISO, MOSI
const byte address[6] = "50015";

void setup() {
  Serial.begin(9600);
  
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_HIGH);
}

void loop() {
  if (Serial.available()) {
    String sendData = Serial.readString();
    
    while (Serial.available()) { // wait until all data is received
      delay(5); // delay to allow buffer to fill 
      sendData += Serial.readString();
    }
    
    radio.write(&sendData, sizeof(sendData));
  }

  if (radio.available()) {
    String receivedData = "";
    bool messageComplete = false;
    
    while (!messageComplete) {
      String temp = "";
      radio.read(&temp, sizeof(temp));
      
      receivedData += temp;
      
      // Check if the message is complete
      if (temp.indexOf('\n') >= 0) { // assuming '\n' is the end-of-message character
        messageComplete = true;
      }
    }
    
    Serial.println(receivedData);
  }
}
