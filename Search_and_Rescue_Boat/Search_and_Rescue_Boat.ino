#include <Arduino.h>
#include <IRremote.h>

// Declarations for functions in other .ino files
// This isn't strictly required but is good practice for clarity.
void initIRSender();
void initIRReceiver();
void sendIRBeacon();
void readIRData();

void setup() {
  // Start the serial monitor to display the results
  Serial.begin(9600);
  
  // Start the IR sender
  initIRSender();
  // Start the IR receiver
  initIRReceiver();
  Serial.println("IR Sender/Receiver Ready.");
}

void loop() {
  Serial.println("Sending beacon...");
  sendIRBeacon(); // Send an IR signal

  Serial.println("Listening for data...");
  readIRData();

  delay(3000); // Wait 3 seconds before repeating
}

