bool ledState1 = false; // Variable for storing the state of the first LED
bool ledState2 = false; // Variable for storing the state of the second LED
int ledPin1 = 12; // green Pin number for the first LED
int ledPin2 = 11; // red Pin number for the second LED

void setup() {
  // Start the serial communication
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);  // Declare the first LED pin as output
  pinMode(ledPin2, OUTPUT);  // Declare the second LED pin as output
}

void loop() {
  if (Serial.available()) { // If there is any data available
    char inByte = Serial.read(); // Store the incoming data
    if (inByte == 1) {    // Whether the received data is '1'
      ledState1 = !ledState1; // Toggle the state of the first LED
      digitalWrite(ledPin1, ledState1); // Change the state of the first LED

      if (ledState1 == true) { // If the first LED is turned on
        ledState2 = false; // Turn off the second LED
        digitalWrite(ledPin2, ledState2); // Change the state of the second LED
      }

       if (ledState1 == false) { // If the first LED is turned on
        ledState2 = true; // Turn off the second LED
        digitalWrite(ledPin2, ledState2); // Change the state of the second LED
      }
    }

    if (ledState1) {
      char mystr[5] = "RED  "; // Create a response string for the first LED
      Serial.write(mystr, 5); // Send the response in return
    }
    else {
      char mystr[5] = "GREEN"; // Create a response string for the first LED
      Serial.write(mystr, 5); // Send the response in return
    }
  }
  
}
