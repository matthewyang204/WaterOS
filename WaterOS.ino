#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const int M1=11;
const int M2=12;
const int Reset=2;
const int indicator=13;
int command = 0;
int terminate = 0;
#define shell() Serial.print("shell>")
#define received() Serial.println(command)
#define processing() Serial.println("Running...")

RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";

void setup() {
  digitalWrite(indicator, LOW);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(Reset, OUTPUT);
  digitalWrite(Reset, HIGH);
  Serial.begin(9600);
  delay(5000);
  digitalWrite(indicator, HIGH);
  Serial.println("WaterOS v1.4 2024 © @matthewyang204 & @13-JA");
  Serial.println("WaterOS Shell Starting...");
  shell();

  // NRF24L01 setup
  radio.begin();
  radio.openReadingPipe(1, address);
  radio.setPALevel(RF24_PA_HIGH);
}

void loop() {
  if (radio.available()) {
    String command = "";
    radio.read(&command, sizeof(command));
    received();
    processing();

    //Run the command:
    if (command.equals("forward\n")){
      digitalWrite(M1, HIGH);
      digitalWrite(M2, HIGH);
      Serial.println("Both motors started; boat is moving forward");
    } else if (command.equals("right\n")){
      digitalWrite(M1, HIGH);
      digitalWrite(M2, LOW);
      Serial.println("Left motor started, right motor stopped; boat is moving right");
    } else if (command.equals("left\n")){
      digitalWrite(M1, LOW);
      digitalWrite(M2, HIGH);
      Serial.println("Left motor stopped, right motor started; boat is moving left");
    } else if (command.equals("stop\n")){
      digitalWrite(M1, LOW);
      digitalWrite(M2, LOW);
      Serial.println("Both motors stopped; boat is parked");
    } else {
      Serial.println("Invalid command");
    }
    shell();
  }
}
