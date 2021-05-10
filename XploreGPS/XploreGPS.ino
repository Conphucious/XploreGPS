
/*
 * SD CARD PINOUT
 * --------------
 * MOSI - PIN 11
 * MISO - PIN 12
 * CLK - PIN 13
 * CS - PIN 10
 * VCC - 5V
 * GND
 */

 /*
 * GPS PINOUT
 * --------------
 * RX - 0
 * TX - 1
 * GND
 * 3.3V
 */
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

static const uint32_t GPS_BAUD = 9600;
static const int RX_PIN = 0, TX_PIN = 1;
static const long GPS_DELAY_TIME = 1000L;

TinyGPSPlus gps;
SoftwareSerial gpsSerial(RX_PIN, TX_PIN);

void setup() {
  Serial.begin(115200);
  gpsSerial.begin(GPS_BAUD);
}

void loop() {
  
}

void readGps() {
  while (gpsSerial.available() > 0) {
    if (gps.encode(gpsSerial.read())) {
      // toggle LED
      logGpsData();
      delay(GPS_DELAY_TIME);
    }
  }
}

void logGpsData() {
  if (gps.location.isValid()) {
//    gps.location.lat();
//    gps.location.lng();
  }

  if (gps.date.isValid()) {
//    gps.date.month();
//    gps.date.day();
//    gps.date.year();
  }

  if (gps.time.isValid()) {
    // in HHMMSSCC format u32
//    gps.time.value();
  }

  if (gps.speed.isValid()) {
//    gps.speed.mph
  }

  if (gps.satellites.isValid()) {
    // number of satellites in use
//    gps.satellites.value();
  }

}
