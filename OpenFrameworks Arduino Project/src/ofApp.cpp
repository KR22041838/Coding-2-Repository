//Arduino connected to OpenFrameworks, mouse clicks change the colour of the output window
//The colour changes between green and red
//The corresponding colour LED will light up or turn off according to the mouse click. 

#include "ofApp.h"
bool isBackgroundGreen = false; // Variable to keep track of the background color
int sendData = 0; // Variable to send data to Arduino



void ofApp::setup() {
    serialMessage = false; // Set a boolean variable called "serialMessage" to false

    serial.listDevices(); // List all available serial devices on the computer
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList(); 
    // Retrieve a vector of device information objects for all available serial devices
    int baud = 9600; // Set the baud rate for serial communication to 9600 bits per second
    serial.setup(0, baud); //open the first device

}

void ofApp::update() {
    if (serialMessage) { //check for serialMessage
        serialMessage = false; //set to false
        serial.writeByte(sendData); // send the data to arduino

        serial.readBytes(receivedData, 5); // Getting the data from Arduino
        printf("receivedData is %d \n", receivedData);    // Printing in ASCII format
    }
}

void ofApp::draw() {

    ofSetColor(0);	// Text color is black

    if (isBackgroundGreen) { //if background colour is green change to red
        ofColor colorOne(255, 0, 0);
        ofColor colorTwo(30, 0, 0);

        ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
        // Sets the background to a circular gradient
    }
    else { // if background is red change to green
        ofColor colorOne(0, 255, 0);
        ofColor colorTwo(200,255,200);

        ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
        // Sets the background to a circular gradient
    }

    string msg; //message to appear in ouput window
    msg += "Click to change background color\n";
    msg += receivedData; //print to console 
   
    
    ofDrawBitmapString(msg, 200, 300); // Write the data on the output window
}

void ofApp::mousePressed(int x, int y, int button) {
    isBackgroundGreen = !isBackgroundGreen; // Toggle the background color
    serialMessage = true; // Send data to Arduino
   // sendData = isBackgroundBlue ? 1 : 0; // Set the data to be sent to Arduino
}
