#include "main.h"

void checkResponse() {
  WiFiClient response;
  if(response.connect(RESPSERV, RESPPORT)) {
    response.print(String("GET ") + RESPRSRC + " HTTP/1.1\r\n" +
               "Host: " + RESPSERV + "\r\n" +
               "Connection: close\r\n\r\n");
    unsigned long lasttime = millis();
    while (!response.available() && millis() - lasttime < 1000) {delay(1);}
    while(response.available()){
      char readchar = response.read();
    }

    s_ccr = true;
    status_changed = true;
    response.stop();
  }
}
