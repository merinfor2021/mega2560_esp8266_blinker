// Initial setup
void setup()
{
 /*
  * It is recommended to use the lower baud rate. The higher the baud rate,
  * the higher the bit error rate will be, and the control action might fail.
  */
  Serial.begin(4800); // Initialize the ESP8266 <=> MEGA2560 serial port
}

// The loop function runs over and over again forever
void loop() {
  Serial.print("0"); // Command for MEGA2560 to turn off MEGA2560's L LED
  delay(5000); // wait 5 seconds
  Serial.print("1"); // Command for MEGA2560 to turn on  MEGA2560's L LED
  delay(5000); // wait 5 seconds
}
