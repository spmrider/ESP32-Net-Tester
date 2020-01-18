# ESP32-Net-Tester
Simple Setup to test connectivity of an IP Port for defined connectivity

## Idea
The project evolved from the need to have a simple tool to test a network port for a given configuration. Is it in the correct VLAN, is DHCP enabled, can I do basic thinks like reaching mit DNS and NTP servers, am I able to connect to my backend servers? Even the basic result of tests in the backend may be reported.

The results all should be displayed in a simple form, so that field technicians, who are maybe not network or even computer specialists are able to report the state back. In the simplest form by "all green" or with a little more detail as in "the C and R tests failed".

## Hardware
### Board and Display
A compact, though powerful, PoE enabled hardware is needed to keep things handy. The board used for initial development was an

- Olimex EPS32-POE-ISO + SSD1306 based 0.96" OLED Display

The ISO variant works with PoE or USB powered, and will be safely working with both power sources being attached.

### Case
A basic case design was done, files will shortly be published on Thingiverse.

## Setup
Copy the `netconf.h.sample` file to `netconf.h` and modify the values to match your network parameters.

- `NETNAME` defines the name of the device in the networkID
- `NTPSERVER` is the NTP server to use for time setting
- `CONNTEST` and `CONNPORT` define a server and port to try a TCP connect to
- `RESPSERV` and `RESPPORT` define an HTTP server to connect for further tests
  - `RESPRSRC` is the ressource to be requested from the server
  - `RESPSUCS` is the last string of the reply from the server which denotes a successful test

## Operation
After connecting the device to either a PoE port or non-powered port and USB power it will establish a link. The link parameters (speed and duplex) are being displayed. Note that the hardware can only do 10 or 100 MBit/s.

- **DHCP Test** requests IP, netmask, router and DNS from the DHCP server, IP and network are displayed, the **N** (_N_etwork) will light on success
- **DNS Test** tries to resolve the DNS name from the `CONNTEST` definition, on success the **D** (_D_NS) will light up
- **Connect Test** makes a TCP connect to the defined target, on success the **C** (_C_onnect) will light up
- **Response Test** does an HTTP request to the defined target and will test for the expected reply. On success **R** (_R_esponse) will light up.

If the NTP server responds, the time will be displayed in the bottom line.
