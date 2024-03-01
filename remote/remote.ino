#include "sumedh_garage.h"
#include <ELECHOUSE_CC1101_SRC_DRV.h>

// M1101
#define PIN_GDO0 12
#define PIN_GDO2 4

#define FREQUENCY (318.00)

void setup() {
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);

  // CC1101 SETUP
  initCC1101(FREQUENCY);

  if (ELECHOUSE_cc1101.getCC1101()) {
    // Check the CC1101 Spi connection.
    Serial.println("Connection OK");
  }

  Serial.println("Setup done.");
}

void initCC1101(float mhz) {
  ELECHOUSE_cc1101.Init();
  ELECHOUSE_cc1101.setGDO(PIN_GDO0, PIN_GDO2);
  ELECHOUSE_cc1101.setMHZ(
      mhz); // Here you can set your basic frequency. The lib calculates the
            // frequency automatically (default = 433.92).The cc1101 can:
            // 300-348 MHZ, 387-464MHZ and 779-928MHZ. Read More info from
            // datasheet.
  ELECHOUSE_cc1101.SetTx();          // set Transmit on
  ELECHOUSE_cc1101.setModulation(2); // set modulation mode. 0 = 2-FSK, 1 =
                                     // GFSK, 2 = ASK/OOK, 3 = 4-FSK, 4 = MSK.
  ELECHOUSE_cc1101.setDRate(512); // Set the Data Rate in kBaud. Value from 0.02
                                  // to 1621.83. Default is 99.97 kBaud!
  ELECHOUSE_cc1101.setPktFormat(
      3); // Format of RX and TX data. 0 = Normal mode, use FIFOs for RX and TX.
          // 1 = Synchronous serial mode, Data in on GDO0 and data out on either
          // of the GDOx pins. 2 = Random TX mode; sends random data using PN9
          // generator. Used for test. Works as normal mode, setting 0 (00), in
          // RX. 3 = Asynchronous serial mode, Data in on GDO0 and data out on
          // either of the GDOx pins.

  if (!ELECHOUSE_cc1101.getCC1101()) { // Check the CC1101 Spi connection.
    Serial.println("CC1101 Connection Error");
  }
}

void loop() {
  sendSamples(FREQUENCY);

  delay(1000);
}

void sendSamples(float mhz) {
  uint32_t sum = 0;
  initCC1101(mhz);
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.print("Transmitting ");
  Serial.print(NUM_SAMPLES);
  Serial.println(" Samples");

  int32_t delay_us = 0;
  unsigned long time;
  byte n = 0;

  for (int i = 0; i < NUM_SAMPLES; i++) {
    // TRANSMIT
    n = 1;
    delay_us = (int32_t)pgm_read_dword_near(signal + i);
    if (delay_us < 0) {
      // DONT TRANSMIT
      delay_us = delay_us * -1;
      n = 0;
    }

    digitalWrite(PIN_GDO0, n);
    digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN) == 0 ? HIGH : LOW);

    long start = micros();
    if (delay_us < 10000) {
        delayMicroseconds(delay_us);
    }
    else {
        delay(delay_us/1000);
        delayMicroseconds(delay_us%1000);
    }
    
  }

  // STOP TRANSMITTING
  digitalWrite(PIN_GDO0, 0);

  Serial.println("Transmission completed.");
  digitalWrite(LED_BUILTIN, LOW);
}