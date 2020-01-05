#ifndef _GLOBALS_H
#define _GLOBALS_H

extern bool eth_connected;

extern bool data_changed;
extern bool status_changed;
extern bool time_set;

extern bool s_net;
extern bool s_dns;
extern bool s_ccc;
extern bool s_ccr;

// extern char* d_con, D_CON;
// extern char* D_CON;
extern String d_con;

extern String d_ip4;
extern String d_nm4;
extern String d_cdr;
extern String d_ns1;
extern String d_ns2;
extern String d_gw4;
extern String d_bc4;

extern String d_ntp;
extern String d_tcn;

#endif
