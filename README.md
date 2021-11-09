# mega2560_esp8266_blinker_v0
Simple blinker: Robotdyn "mega2560 + esp8266" "WiFi R3" AliExpress board. Over a serial, ESP8266 tells MEGA2560 to blink a LED. 

Usage and flashing settings:
1) blinker_part2560.ino for MEGA2560. DIP switches: only 3 and 4 are enabled, and RXD3/TXD3.
2) blinker_part8266.ino for ESP8266. DIP switches: only 5 and 6 and 7 are enabled, and RXD3/TXD3.
https://arduino-esp8266.readthedocs.io/en/latest/installing.html - downgrade the ESP8266 library to 2.7.4 
3) DIP switches: to connect MEGA2560 with ESP8266, only 1 and 2 are enabled (and RXD3/TXD3).
Now ESP8266 tells MEGA2560 to blink a LED every 5 seconds.

More information about this board:
https://iotdiary.blogspot.com/2017/11/esp-link-on-atmega2560esp8266-board.html

EDIT:
Now there is a blinker_part8266_webserver.ino: web server with a button, based on a code from https://radioprog.ru/post/866 (scroll down a bit). Now you can control this LED using another device connected to this WiFi network and a web server: open 192.168.1.1 page and click this button.
