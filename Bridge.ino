#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const int MOSI_PIN = 7;
const int MISO_PIN = 6;
const int SCK_PIN = 5;

RF24 radio(9, 10, SCK_
IN, MISO_PIN, MOSI_PIN); // CE, CSN, SCK, MISO, MOSI
const byte address[6] = "50015";

void setup() {
  Serial.begin(9600);
  
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_HIGH);
}

void loop() {
  if (radio.available()) {
    String receivedData = "";
    radio.read(&receivedData, sizeof(receivedData));
    
    Serial.println(receivedData);
  }

  if (Serial.available()) {
    String sendData = Serial.readString();
    
    radio.write(&sendData, sizeof(sendData));
  }
}