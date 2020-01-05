#ifndef _MAIN_H
#define _MAIN_H

#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>
#include <time.h>
#include <ss_oled.h>
#include <string>

#include "netconf.h"

#ifndef _GLOBALS_CPP
#include "globals.h"
#endif //_GLOBALS_CPP

// ss_oled BACKBUFFER
#define USE_BACKBUFFER

// to be tuned
#define STACK_SIZE 8192

// Olimex ESP32 PoE Etehrnet
#define ETH_CLK_MODE ETH_CLOCK_GPIO17_OUT
#define ETH_PHY_POWER 12

#include "ETH.h"

// General Clients
#include <WiFiClientSecure.h>
#include <ESPmDNS.h>

// define display positions

#define DATA_X 12

#define STATUS_OFFSET 22
#define NET_X 24
#define DNS_X (NET_X+STATUS_OFFSET)
#define CCC_X (DNS_X+STATUS_OFFSET)
#define CCR_X (CCC_X+STATUS_OFFSET)

#define CONN_L 4
#define IPAD_L 5
#define IPNM_L 6
#define NTPT_L 7
#define STAT_L 0

#define CONN_T "C"
#define IPAD_T "I"
#define IPNM_T "M"
#define NTPT_T "T"

#define D_CON "--Mb/s *       "
#define D_IP4 "-.-.-.-        "
#define D_NM4 "-.-.-.-/-      "
#define D_NS1 "-.-.-.-        "
#define D_NS2 "-.-.-.-        "
#define D_GW4 "-.-.-.-        "
#define D_BC4 "-.-.-.-        "
#define D_NTP "--:--:--       "
#define D_TCN "--             "

#define NET_S "N"
#define DNS_S "D"
#define CCC_S "C"
#define CCR_S "R"

#endif // _MAIN_H
