#include <Arduino.h>
#include <IRremote.h>

// Define the pin the IR sender's data line is connected to
#define IR_SEND_PIN D3

void initIRSender() {
  // Start the IR sender on pin D3. 
  // ENABLE_LED_FEEDBACK will blink the Nucleo's built-in LED on send.
  IrSender.begin(IR_SEND_PIN, ENABLE_LED_FEEDBACK);
  
  // Optional: Start serial monitor to see a confirmation message
  // Serial.begin(9600);
  // Serial.println("IR Beacon activated.");
}

void sendIRBeacon() {
  // Repeatedly send a simple, arbitrary NEC signal.
  // The address (0x10) and command (0x5A) don't matter for a beacon,
  // as long as they are consistent.
  // The last parameter (0) means it will not send repeats.
  IrSender.sendNEC(0x10, 0x5A, 0);

  // Wait a short time between pulses. 100ms is a good starting point.
  // delay(100); 
}