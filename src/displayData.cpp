#include "main.h"

String GetTime();

void displayData() {
  if(time_set) {
    d_ntp = GetTime();
  }
  if(status_changed || data_changed) {
    oledWriteString(0,NET_X,STAT_L,(char *)NET_S,FONT_LARGE,s_net,1);
    oledWriteString(0,DNS_X,STAT_L,(char *)DNS_S,FONT_LARGE,s_dns,1);
    oledWriteString(0,CCC_X,STAT_L,(char *)CCC_S,FONT_LARGE,s_ccc,1);
    oledWriteString(0,CCR_X,STAT_L,(char *)CCR_S,FONT_LARGE,s_ccr,1);
    status_changed = false;
  }
  if(data_changed) {
    char d_char[20];
    d_con.toCharArray(d_char, 20);
    oledWriteString(0,DATA_X,CONN_L,d_char,FONT_SMALL,0,1);
    d_ip4.toCharArray(d_char, 20);
    oledWriteString(0,DATA_X,IPAD_L,d_char,FONT_SMALL,0,1);
    d_nm4.toCharArray(d_char, 20);
    oledWriteString(0,DATA_X,IPNM_L,d_char,FONT_SMALL,0,1);
    d_ntp.toCharArray(d_char, 20);
    oledWriteString(0,DATA_X,NTPT_L,d_char,FONT_SMALL,0,1);
    data_changed = false;
  } else if(time_set) {
    char d_char[20];
    d_ntp.toCharArray(d_char, 20);
    oledWriteString(0,DATA_X,NTPT_L,d_char,FONT_SMALL,0,1);
  }
}
