#include <main.h>

#ifdef USE_BACKBUFFER
static uint8_t ucBackBuffer[1024];
#else
static uint8_t *ucBackBuffer = NULL;
#endif

void EthEvent(WiFiEvent_t event);
void displayData();
void doChecks();

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  int rc = oledInit(OLED_128x64, 0, 0, -1, -1,400000L); // use standard I2C bus at 400Khz
  if (rc != OLED_NOT_FOUND)
  {
    oledFill(0, 1);
    oledWriteString(0,18,0,(char *)"DB S&S", FONT_LARGE, 0, 1);
    oledWriteString(0,22,3,(char *)"Network Tester", FONT_SMALL,0,1);
    oledWriteString(0, 0,7,(char *)"Version:",FONT_NORMAL,0,1);
    oledWriteString(0,80,7,(char *)PROGVERSION,FONT_NORMAL,0,1);
    oledSetBackBuffer(ucBackBuffer);
    delay(3000);
    oledFill(0, 1);
  }
  WiFi.onEvent(EthEvent);
  ETH.begin();
}

void loop() {
  displayData();
  if (eth_connected) doChecks();
  delay(1000);
}
