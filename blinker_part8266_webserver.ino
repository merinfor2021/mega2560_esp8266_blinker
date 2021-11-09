#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

/* Set up your SSID and Password */
const char*      ssid = "NodeMCU"; // SSID
const char* password = "19216811"; // Password

/* Set up your IP addresses */
IPAddress local_ip(192,168,1,1);
IPAddress  gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80);

bool LED1status = LOW;

// Initial setup
void setup()
{
 /*
  * It is recommended to use the lower baud rate. The higher the baud rate,
  * the higher the bit error rate will be, and the control action might fail.
  */
  Serial.begin(4800); // Initialize the ESP8266 <=> MEGA2560 serial port

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);

  delay(100);

  server.on("/",        handle_OnConnect);
  server.on("/led1on",  handle_led1on);
  server.on("/led1off", handle_led1off);
  server.onNotFound(handle_NotFound);

  server.begin();
  //// Serial.println("HTTP server started");
}

// The loop function runs over and over again forever
void loop()
{
  server.handleClient();
  if (LED1status)
    Serial.print("1"); // Command for MEGA2560 to turn on  MEGA2560's L LED
  else
    Serial.print("0"); // Command for MEGA2560 to turn off MEGA2560's L LED
}

void handle_OnConnect()
{
  /*
   * Serial.print("LED1status: ");
   * if (LED1status)
   *   Serial.println("ON");
   * else
   *   Serial.println("OFF");
   */
  server.send(200, "text/html", SendHTML(LED1status));
}

void handle_led1on()
{
  LED1status = HIGH;
  //// Serial.println("LED1status: ON");
  server.send(200, "text/html", SendHTML(true));
}

void handle_led1off()
{
  LED1status = LOW;
  //// Serial.println("LED1status: OFF");
  server.send(200, "text/html", SendHTML(false));
}

void handle_NotFound()
{
  server.send(404, "text/plain", "ERROR 404: Not Found");
}

String SendHTML(uint8_t led1stat)
{
  String ptr = "";
  ptr += "<!DOCTYPE html>\n";
  ptr += "<html>\n";
  ptr += "<head>\n";
  ptr += "<meta charset=\"utf-8\">\n";
  ptr += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr += "<title>LED Control</title>\n";
  ptr += "<style>html { background-color: white; color: black; display: inline-block; font-family: \"Liberation Mono\", monospace; font-size: 20px; text-align: center; position: absolute; left: 0px; }\n";
  ptr += "body { color: black; }\n";
  ptr += "h1 { color: darkgray; }\n";
  ptr += "h2 { color: gray; }\n";
  ptr += "h3 { color: lightgray; }\n";
  ptr += ".button { background-color: white; color: white; border: none; border-radius: 5px; cursor: pointer; text-decoration: none; margin: 5px 5px 5px 5px; padding: 3px 3px 3px 3px; }\n";
  ptr += ".button-on { background-color: green; }\n";
  ptr += ".button-on:active { background-color: darkgreen; }\n";
  ptr += ".button-off { background-color: blue; }\n";
  ptr += ".button-off:active { background-color: darkblue; }\n";
  ptr += "p { font-size: 15px; }\n";
  ptr += "</style>\n";
  ptr += "</head>\n";
  ptr += "<body>\n";
  //// ptr += "<h1>ESP8266 Web Server</h1>\n";
  //// ptr += "<h3>Using Access Point(AP) Mode</h3>\n";

  if (led1stat)
    ptr += "<p>LED1 Status: ON</p><a class=\"button button-off\" href=\"/led1off\"><button>OFF</button></a>\n";
  else
    ptr += "<p>LED1 Status: OFF</p><a class=\"button button-on\" href=\"/led1on\"><button>ON</button></a>\n";

  ptr += "</body>\n";
  ptr += "</html>\n";
  return ptr;
}
