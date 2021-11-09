String Serial_String = "";

// Initial setup
void setup() {
  Serial.begin(9600); // Initialize the debug serial port
 /*
  * It is recommended to use the lower baud rate. The higher the baud rate,
  * the higher the bit error rate will be, and the control action might fail.
  */
  Serial3.begin(4800); // Initialize the ESP8266 <=> MEGA2560 serial port
  pinMode(LED_BUILTIN, OUTPUT); // Initialize the digital pin LED_BUILTIN as an output
}

// Read a command from ESP8266 over serial
void read_string() {
  while (Serial3.available() > 0) {
    Serial_String += (char)(Serial3.read());
    delay(2);
  }
}

// The loop function runs over and over again forever
void loop() {
  if (Serial3.available() > 0) {
    Serial_String = "";
    read_string();
    Serial.println(Serial_String);
  }
  if (Serial_String == "1")
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  if (Serial_String == "0")
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
}
