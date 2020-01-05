#define _GLOBALS_CPP
#include "main.h"
#undef _GLOBALS_CPP

bool eth_connected = false; // Ethernet connectivity status
bool data_changed = false;
bool status_changed = false;
bool time_set = false;

bool s_net = false;
bool s_dns = false;
bool s_ccc = false;
bool s_ccr = false;

String d_con = "";
String d_ip4 = "";
String d_nm4 = "";
String d_ns1 = "";
String d_ns2 = "";
String d_gw4 = "";
String d_bc4 = "";
String d_ntp = "";
String d_tcn = "";
