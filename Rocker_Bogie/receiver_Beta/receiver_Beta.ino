#include <VirtualWire.h>
#include <VirtualWire_Config.h>


void setup()
{
vw_set_ptt_inverted(true); // Required for DR3100
vw_set_rx_pin(12);
vw_setup(4000); // Bits per sec
pinMode(13, OUTPUT);
Serial.begin(9600);
vw_rx_start(); // Start the receiver PLL running
}


void loop()
{
uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;

if (vw_get_message(buf, &buflen)) // Non-blocking
{
if(buf[0]=='1')
{
  Serial.println(buf[0]);
//backward();
}
if(buf[0]=='0')
{
  Serial.println(buf[0]);
//forward();
}
if(buf[0]=='2')
{
  Serial.println(buf[0]);
 // left();
}
if(buf[0]=='3')
{
Serial.println(buf[0]);
 // right();
}
if(buf[0]=='4')
{
  Serial.println(buf[0]);
 // tiltup();
}
if(buf[0]=='5')
{
  Serial.println(buf[0]);
//  tiltdown();
}
if(buf[0]=='6')
{
  Serial.println(buf[0]);
 // panright();
}
if(buf[0]=='7')
{
  Serial.println(buf[0]);
 // panleft();
}

}

}


