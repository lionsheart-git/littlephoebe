/**\
 * Use this sketch to talk directly to the gps module.\
 * \
 * In Serial Monitor, select "Both NL & CR" and "115200 baud\'93.\
 */

#include <HardwareSerial.h>

#define GPS_RX 12
#define GPS_TX 34

#define debugSerial Serial
HardwareSerial gpsSerial(1);

void setup()
{
  while (!debugSerial || !gpsSerial)
    ;

  debugSerial.begin(115200);
  delay(1000);

  gpsSerial.begin(9600, SERIAL_8N1, GPS_TX, GPS_RX);

}

void loop()
{
  while (debugSerial.available())
  {
    gpsSerial.write(debugSerial.read());
  }
  while (gpsSerial.available())
  {
    debugSerial.write(gpsSerial.read());
  }
}