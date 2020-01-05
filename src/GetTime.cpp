#include "main.h"

void StartTime()
{
  struct tm timeinfo;
  configTime(0, 0, NTPSERVER);
  setenv("TZ", TIMEZONE, 1); // Set for your locale
  delay(200);
  if(!getLocalTime(&timeinfo)) {
    time_set = false;
  } else {
    time_set = true;
  }
}

String GetTime()
{
  char output[50] = "";
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo))
  {
    time_set = false;
    StartTime();
  } else {
    time_set = true;
    strftime(output, 50, "%H:%M:%S %Z", &timeinfo); // Format needed for Google Charts is "11/12/17 22:01:00"; //dd/mm/yy hh:hh:ss
  }
  return output;
}
