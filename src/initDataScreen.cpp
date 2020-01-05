#include "main.h"

void initDataScreen() {
  oledFill(0,1);
  oledWriteString(0,0,CONN_L,(char *)CONN_T,FONT_NORMAL,0,1);
  oledWriteString(0,0,IPAD_L,(char *)IPAD_T,FONT_NORMAL,0,1);
  oledWriteString(0,0,IPNM_L,(char *)IPNM_T,FONT_NORMAL,0,1);
  oledWriteString(0,0,NTPT_L,(char *)NTPT_T,FONT_NORMAL,0,1);
  delay(500);
}
