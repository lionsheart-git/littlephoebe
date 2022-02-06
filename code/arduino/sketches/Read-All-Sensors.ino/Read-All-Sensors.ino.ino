/*  
 * senseBox:home sensor test
 * 
 * Institute for Geoinformatics, University of Muenster
 * Sept. 2017
*/

#include <Wire.h>
#include <HDC100X.h>
#include <BMP280.h>
#include <Makerblog_TSL45315.h>
#include <VEML6070.h>
#include <SPI.h>
#include <SD.h>

#define I2C_ADDR 0x38
#define IT_1   0x1 //1T
#define P0 1011

const int chipSelect = 4;

HDC100X HDC(0x43);
BMP280 BMP;
VEML6070 VEML;
Makerblog_TSL45315 TSL = Makerblog_TSL45315(TSL45315_TIME_M4);

void setupSD()
{
  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }
  Serial.println("card initialized.");
}

void initializeLogger() {
  File logFile = SD.open("datalog.txt", FILE_WRITE);

  if (logFile) {
    Serial.println("Log file successfuly opened!");
    logFile.println("-----New run-----");
    logFile.close();
  }
  else {
    Serial.println("Error opening log file!");
  }
}


void setup()
{
  Serial.begin(9600);
  Serial.println("Starting test...\n");
  scan();
  setupSD();
  initializeLogger();
  
  HDC.begin(HDC100X_TEMP_HUMI, HDC100X_14BIT, HDC100X_14BIT, DISABLE);
  VEML.begin();
  TSL.begin();
  BMP.begin();
  BMP.setOversampling(4);
}

void logAndPrint(String const & toWrite)
{

  File logFile = SD.open("datalog.txt", FILE_WRITE);

  if (logFile) {
    logFile.println(toWrite);
    logFile.close();
  }
  else {
    Serial.println("Error opening log file!");
  }

  Serial.println(toWrite);
}


void loop()
{
  char result;
  double T=0, P=0;
  uint32_t lux;
  byte msb=0, lsb=0;
  uint16_t uv;

  String dataString = "";

  //HDC1080
  dataString += "Humidity: "; 
  dataString += HDC.getHumi();
  dataString += " %";

  logAndPrint(dataString);
  dataString = "";

  dataString += "Temperature: "; 
  dataString += HDC.getTemp();
  dataString +=" C";

  logAndPrint(dataString);
  dataString = "";

  //BMP280
  result = BMP.startMeasurment();
  delay(result);

  BMP.getTemperatureAndPressure(T, P);
  dataString += "Air pressure: "; 
  dataString += P;
  dataString += " hPa";

  logAndPrint(dataString);
  dataString = "";
  
  dataString += "Temperature: "; 
  dataString += T;
  dataString += " C";

  logAndPrint(dataString);
  dataString = "";

  dataString += "Altitude: ";
  dataString += BMP.altitude(P, P0);
  dataString += " m";

  logAndPrint(dataString);
  dataString = "";

  //TSL45315
  lux = TSL.readLux();
  dataString += "Illuminance: ";
  dataString += lux;
  dataString += " lx";

  logAndPrint(dataString);
  dataString = "";

  //VEML6070
  uv = VEML.getUV();
  dataString += "UV radiation: "; 
  dataString += uv;
  dataString += " uW/cm2";

  logAndPrint(dataString);
  dataString = "";

  logAndPrint(dataString);
  delay(5000);
}

void scan(void)
{
  byte error, address;

  Serial.println("Looking for devices...");

  Wire.begin();
  for(address = 1; address < 127; address++ )
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
 
    if(error == 0)
    {
      Serial.print("Device found: 0x");
      if(address<16)
        Serial.print("0");
      Serial.println(address,HEX);
    }
    else if(error==4)
    {
      Serial.print("Error: 0x");
      if(address<16)
        Serial.print("0");
      Serial.println(address,HEX);
    }
  }
  Serial.println("");
}
