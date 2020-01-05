#include "main.h"

void checkDNS();
void checkConnect();
void checkResponse();

void doChecks() {
  if(!s_dns) checkDNS();
  if(!s_ccc) checkConnect();
  if(!s_ccr) checkResponse();
}
