#define M1 11
#define M2 12
#define Reset 2
int command = 0;
int terminate = 0;
void setup() {
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(Reset, OUTPUT);
  digitalWrite(Reset, HIGH);
  Serial.begin(9600);
  delay(5000);
  Serial.println("Shell is ready");
}

void loop() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    command = Serial.read();

    //Run the command:
    if (command == "forward"){
      digitalWrite(M1, HIGH);
      digitalWrite(M2, HIGH);
    } if (command == "right"){
      digitalWrite(M1, HIGH);
      digitalWrite(M2, LOW);
    } if (command == "left"){
      digitalWrite(M1, LOW);
      digitalWrite(M2, HIGH);
    } if (command == "stop"){
      digitalWrite(M1, LOW);
      digitalWrite(M2, LOW);
    } if (command == "reboot"){
      digitalWrite(Reset, LOW);
      Serial.println("Failed to reboot");
    } if (command == "terminate"){
      Serial.println("Are you sure you want to terminate? (y/n)");
      if (Serial.available() > 0) {
        if (terminate == "y") {
          digitalWrite(M1, LOW);
          digitalWrite(M2, LOW);
          exit(0);
          Serial.println("Failed to shut down");
        }
      }
    } else {
      Serial.println("Invalid command");
    }
  }
}