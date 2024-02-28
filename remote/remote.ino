#include <ELECHOUSE_CC1101_SRC_DRV.h>

// M1101
#define PIN_GDO0 12
#define PIN_GDO2 4

#define FREQUENCY (318.00)

// const int signal[] = {
//     913, -16934, 981, -2034, 947, -5040, 941, -5016, 973, -7988, 951, -5010,
//     969, -2040,  961, -4994, 963, -5022, 949, -5044, 941, -5040, 939, -5038,
//     937, -5020,  953, -7998, 941, -5026, 941, -5016, 981, -2046, 943, -5016,
//     973, -7968,  959, -2060, 939, -5036, 935, -5024, 961, -8000, 939, -2048,
//     973, -16886, 863, -2276, 717};

const int signal[] = {
    913, -16934, 981, -2034, 947, -5040, 941, -5016, 973, -7988, 951, -5010,
    969, -2040,  961, -4994, 963, -5022, 949, -5044, 941, -5040, 939, -5038,
    937, -5020,  953, -7998, 941, -5026, 941, -5016, 981, -2046, 943, -5016,
    973, -7968,  959, -2060, 939, -5036, 935, -5024, 961, -8000, 939, -2048,
    973, -16886, 863, -2276, 717, -5176, 855, -5094, 903, -8034, 913, -5054,
    937, -2042,  971, -5002, 971, -5020, 953, -5030, 951, -5010, 969, -5020,
    943, -5016,  951, -7992, 959, -5024, 949, -5006, 973, -2036, 963, -5000,
    959, -8002,  943, -2058, 945, -5040, 939, -5026, 943, -7990, 973, -2036,
    963, -16882, 847, -2294, 699, -5214, 849, -5080, 899, -8038, 939, -5014,
    939, -2066,  967, -5016, 941, -5022, 979, -5012, 943, -5028, 945, -5012,
    981, -5020,  937, -7982, 983, -5012, 939, -5022, 943, -2068, 941, -5026,
    943, -7978,  965, -2074, 935, -5024, 955, -5028, 953, -7988, 945, -2066,
    943, -16874, 871, -2280, 727};

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
  sendSamples(signal, sizeof(signal) / sizeof(int), FREQUENCY);

  delay(1000);
}

void sendSamples(const int samples[], int samplesLenght, float mhz) {
  initCC1101(mhz);
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.print("Transmitting ");
  Serial.print(samplesLenght);
  Serial.println(" Samples");

  int delay = 0;
  unsigned long time;
  byte n = 0;

  for (int i = 0; i < samplesLenght; i++) {
    // TRANSMIT
    n = 1;
    delay = samples[i];
    if (delay < 0) {
      // DONT TRANSMIT
      delay = delay * -1;
      n = 0;
    }

    digitalWrite(PIN_GDO0, n);

    delayMicroseconds(delay);
  }

  // STOP TRANSMITTING
  digitalWrite(PIN_GDO0, 0);

  Serial.println("Transmission completed.");
  digitalWrite(LED_BUILTIN, LOW);
}