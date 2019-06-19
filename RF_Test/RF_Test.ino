#include <VirtualWire.h>


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_set_rx_pin(12);
  vw_setup(4000); // Bits per sec
  vw_rx_start();
}

void loop() {
  // put your main code here, to run repeatedly:
uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;

if (vw_get_message(buf, &buflen)) // Non-blocking
  {
   
     buf[0]=buf[0]-48;
     Serial.print(buflen);
     Serial.print("      |          ");
     Serial.print(buf[0]);
     Serial.print("       |         ");
     Serial.print(buf[1]);
     Serial.print("        |        ");
     Serial.println(buf[3]);
  }
}
