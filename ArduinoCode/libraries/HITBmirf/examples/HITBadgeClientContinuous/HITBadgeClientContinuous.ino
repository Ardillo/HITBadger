#include <SPI.h>
#include <HITBmirf.h>

#include "HITBadge.h"

//#define DEBUG
//#define OPERATIONAL

unsigned long time;
HITBadge badge;
char nick[] = "     "; //only first 5 chars of nickname
char sender[] = "     ";
char receiver[] = "     ";
byte location = 10;
byte newLocation;
char print_buf[256];

/// SETUP
void setup() {

  // initialise SPI driver for nrf module
  HITBmirf.init();
  // set receiving address
  HITBmirf.setRADDR((byte *)nick);
  // writes channel, payload size and rec.address to nrf
  HITBmirf.config();

  // init serial connection
  Serial.begin(9600);
  Serial.println("Listening...");
  Serial.println();
  //badge.circle(); // Fun for startup sequence.
}

/// PROGRAM
void loop() {
  // A 32 byte buffer to store the data.
  byte data[HITBmirf.payload];
  for (int i = 0; i < HITBmirf.payload; i++)data[i] = 0x0; //incremented data

  /*
   * If a packet has been received.
   *
   * isSending also restores listening mode when it
   * transitions from true to false.
   */
  if (!HITBmirf.isSending() && HITBmirf.dataReady()) {
    Serial.println("Got packet");
    HITBmirf.getData((byte *)&data);

    #ifdef DEBUG
      Serial.println("Data received:");
      printData(data);
      Serial.println("=============================");
    #endif

    //extract data from packet......
    extractData(data);

    if (strcmp(nick, receiver) == 0) {
      location = newLocation;
    }
    else {
      Serial.print("Failed compare: ");
      Serial.println(strcmp(nick, receiver));
    }
  }

  switch ( location) {
    case 0:
      badge.fadeAll();
      return;
    case 1:
      badge.blinkOne();
      return;
    case 2:
      badge.blinkTwo();
      return;
    case 3:
      badge.blinkThree();
      return;
    case 4:
      badge.flashAll();
      return;
    case 5:
      badge.circle();
      return;
    case 6:
      badge.knightRider();
      return;
    case 7:
      badge.arrow();
      return;
    case 8:
      for (int i = 0; i < 3; i++)
        badge.flashAll(50);
      return;
    case 9:
      for (int i = 0; i < 3; i++)
        badge.knightRider(2);
      return;
    default:
      return;
  }
}

void printData(byte* data) {
  Serial.println("Data:");
  for (int i = 0; i < HITBmirf.payload; i++) { //HITBadge.payload
    byte tmp = data[i];
    Serial.print(tmp, HEX);
    Serial.print("\t");
    if (i % 4 == 3) Serial.println();
  }
}

void extractData(byte* data) {
  //byte location;
  for (int i = 0; i < HITBmirf.payload; i++) {
    if (i < 5)
      sender[i] = data[i];
    else if (i < 10)
      receiver[i - 5] = data[i];
    else if (i < 11)
      newLocation = data[i];
  }
  #ifdef OPERATIONAL
    Serial.print("Location: ");
    Serial.println(location);
    sprintf(print_buf, "%s wants %s to got to location %d", sender, receiver, newLocation);
    Serial.println(print_buf);
  #endif
}

String charArrayToString(char arr[]) {
  return String(arr);
}
