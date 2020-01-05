#include "main.h"

void initDataScreen();
void clearData();
void StartTime();

void EthEvent(WiFiEvent_t event)
{
  IPAddress ip = ETH.localIP();
  IPAddress nm = ETH.networkID();
  switch (event) {
    case SYSTEM_EVENT_ETH_START:
      initDataScreen();
      clearData();
      //set eth hostname here
      ETH.setHostname(NETNAME);
      data_changed = true;
      break;
    case SYSTEM_EVENT_ETH_CONNECTED:
      // sprintf(d_con, "%iMB/s %i", ETH.linkSpeed(), ETH.fullDuplex());
      d_con = String(ETH.linkSpeed()) + "Mb/s " + String(ETH.fullDuplex()?'F':'H') + "  ";
      data_changed = true;
      break;
    case SYSTEM_EVENT_ETH_GOT_IP:
      d_ip4 = ip.toString() + "    ";
      d_nm4 = nm.toString() + "/" + String(ETH.subnetCIDR()) + "    ";
      StartTime();
      s_net = true;
      status_changed = true;
      data_changed = true;
      eth_connected = true;
      break;
    case SYSTEM_EVENT_ETH_DISCONNECTED:
      clearData();
      s_net = false;
      s_dns = false;
      s_ccc = false;
      s_ccr = false;
      time_set = false;
      status_changed = true;
      data_changed = true;
      eth_connected = false;
      break;
    case SYSTEM_EVENT_ETH_STOP:
      clearData();
      data_changed = true;
      eth_connected = false;
      break;
    default:
      break;
  }
}
