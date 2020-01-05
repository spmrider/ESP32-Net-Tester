#include "main.h"

void checkConnect() {
  WiFiClient conntest;
  if(conntest.connect(CONNTEST, CONNPORT)) {
    s_ccc = true;
    status_changed = true;
    conntest.stop();
  }
}
