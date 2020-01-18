#include "main.h"

void checkResponse() {
  String reply;
  WiFiClient response;
  if(response.connect(RESPSERV, RESPPORT)) {
    response.print(String("GET ") + RESPRSRC + " HTTP/1.0\r\n" +
               "Host: " + RESPSERV + "\r\n" +
               "Connection: close\r\n\r\n");
    unsigned long lasttime = millis();
    while (!response.available() && millis() - lasttime < 1000) {delay(1);}
    while(response.available()){
      reply += String((char)response.read());
      // char readchar = response.read();
    }
    if (reply.endsWith(RESPSUCS)) {
      s_ccr = true;
      status_changed = true;
    }
    response.stop();
  }
}
