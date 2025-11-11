#include <Arduino.h>
#include <IRremote.h>

// Define the pin the IR receiver's signal pin is connected to
#define IR_RECEIVE_PIN D2

void initIRReceiver() {
  // Start the serial monitor to display the results
  Serial.begin(9600);
  
  // Start the IR receiver
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // ENABLE_LED_FEEDBACK blinks the built-in LED on receive

  Serial.println("IR Receiver is ready to decode signals.");
}

void readIRData() {
  // Check if the IR receiver has decoded a signal
  if (IrReceiver.decode()) {
    Serial.println("Received Signal: ");
    
    // The printIRResultShort function is a handy way to print the summary
    IrReceiver.printIRResultShort(&Serial);
    Serial.println(); // Extra newline for readability

    // You can also get the raw data if needed
    Serial.print("Raw Data: 0x");
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    
    // IMPORTANT: Resume listening for the next signal
    IrReceiver.resume(); 
  }
}