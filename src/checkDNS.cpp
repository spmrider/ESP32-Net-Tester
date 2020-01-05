#include "main.h"

void checkDNS() {
  IPAddress dnscheck;
  if(WiFi.hostByName(CONNTEST, dnscheck)) {
    s_dns = true;
    status_changed = true;
  }
}
