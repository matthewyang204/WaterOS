const int M1 = 11;
const int M2 = 12;
const int Reset = 2;
const int indicator = 13;

int command = 0;
int terminate = 0;

#define shell() Serial.print("shell>")
#define received() Serial.println(command)
#define processing() Serial.println("Running...")

void setup() {
  pinMode(indicator, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(Reset, OUTPUT);

  digitalWrite(Reset, HIGH);
  Serial.begin(9600);
  delay(5000);
  digitalWrite(indicator, HIGH);

  Serial.println("WaterOS v1.6 2024 © @matthewyang204 & @13-JA");
  Serial.println("WaterOS Shell Starting...");
  shell();
}

void loop() {
  if (Serial.available()) {
    String command = Serial.readString();  // Read the entire incoming string
    command.trim();                        // Clean up any extra spaces or newlines
    received();
    processing();

    // Run the command:
    if (command.equals("forward") || command.equals("w")) {
      digitalWrite(M1, HIGH);
      digitalWrite(M2, HIGH);
      Serial.println("Both motors started; boat is moving forward");
    } else if (command.equals("right") || command.equals("d")) {
      digitalWrite(M1, HIGH);
      digitalWrite(M2, LOW);
      Serial.println("Left motor started, right motor stopped; boat is moving right");
    } else if (command.equals("left") || command.equals("a")) {
      digitalWrite(M1, LOW);
      digitalWrite(M2, HIGH);
      Serial.println("Left motor stopped, right motor started; boat is moving left");
    } else if (command.equals("stop") || command.equals("s")) {
      digitalWrite(M1, LOW);
      digitalWrite(M2, LOW);
      Serial.println("Both motors stopped; boat is parked");
    } else {
      Serial.println("Invalid command");
    }
    shell();
  }
}
