#include "ofApp.h"
bool isBackgroundGreen = false; // Variable to keep track of the background color
int sendData = 0; // Variable to send data to Arduino
//ofTrueTypeFont font; // Declare a font object
bool hasMouseBeenPressed = false;
int clickCount = 0;


void ofApp::setup() {
    serialMessage = false;

    serial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();

    //font.load("Helvetica", 18);


    // this should be set to whatever com port your serial device is connected to.
    // (ie, COM4 on a pc, /dev/tty.... on linux, /dev/tty... on a mac)
    // arduino users check in arduino app....
    int baud = 9600;
    serial.setup(0, baud); //open the first device
    //serial.setup("COM10", baud); // windows example
    //serial.setup("/dev/tty.usbserial-A4001JEC", baud); // mac osx example
    //serial.setup("/dev/ttyUSB0", baud); //linux example
    
    ofSetBackgroundColor(0);
    ofSetCircleResolution(100);
    ofSetDepthTest(true);
}

void ofApp::update() {
    if (serialMessage) {
        serialMessage = false;
        serial.writeByte(sendData); // sending the data to arduino

        serial.readBytes(receivedData, 5); // Getting the data from Arduino
        printf("receivedData is %d \n", receivedData);    // Printing in ASCII format
    }
}

void ofApp::draw() {

    /* can combine DrawCircle animations by just having stacking them one after the other
    Video used:
    https://www.youtube.com/watch?v=kYejiSrzFzs&list=PLWPxkLdNmFwOVBCvwLh3tiKc4G74iUe03&index=3
    Next Steps:
         1) Play/Style out case animations
         2) Have each animation in similar colours eg: case1 = blues, case2 = purples, case3 = reds 
         and a colourful 'finale' final case.
         3) Change Arduino side to RGB LED to corrispond with Case colour schemes
         4) For extra could add arduino button to add text to screen? or turn cases back one?
         5) Remove Unnessassry code
         6) Use ChatGTP to comment

    */

    ofSetColor(225);	// Text color is white
    

    switch (clickCount % 5) {
    case 0: {
        float time = ofGetElapsedTimef();
        for (int i = 0; i < 900; i += 5) {
            ofDrawCircle(ofGetWidth() / 2, i, 100);
        }
        break;
    }
    case 1: {
        float time = ofGetElapsedTimef();
        for (int i = 0; i < 900; i += 5) {
            ofDrawCircle(ofGetWidth() / 2 + 100 * sin(i * 0.01 + time), 50 + i, 50 + 40 * sin(i * 0.005 + time));
        }
        break;
    }
    case 2: {
        float time = ofGetElapsedTimef();
        for (int i = 0; i < 900; i += 5) {
            ofSetColor(127 + 127 * sin(i * 0.04 + time), 127 + 127 * sin(i * 0.05 + time), 127 + 127 * sin(i * 0.012 + time));
            ofDrawCircle(ofGetWidth() / 2 + 100 * sin(i * 0.01 + time), 50 + i, 50 + 40 * sin(i * 0.005 + time));
        }
        break;
    }
    case 3: {
        float time = ofGetElapsedTimef();
        for (int x = 1; x < 20; x++) {
            for (int i = 0; i < 900; i += 5) {
                ofSetColor(127 + 127 * sin(i * 0.04 + time), 127 + 127 * sin(i * 0.05 + time), 127 + 127 * sin(i * 0.012 + time));
                //ofDrawCircle(ofGetWidth() / 2 + 100 * sin(i * 0.01 + time), 50 + i, 50 + 40 * sin(i * 0.005 + time + x));
                //ofDrawCircle(ofGetWidth() / 2 + 100 * sin(i * 0.01 + time + x), 50 + i, 50 + 40 * sin(i * 0.005 + time + x));
                //ofDrawCircle(50 * x + 100 * sin(i * 0.01 + time + x), 50 + i, 50 + 40 * sin(i * 0.005 + time + x));
                ofDrawCircle(50 * x + 100 * sin(i * 0.01 + time), 50 + i, 50 + 40 * sin(i * 0.005 + time));

            
            }

        }
        break;
    }
    case 4: {
        ofColor colorOne(0, 5, 255); // green
        ofColor colorTwo(0, 0, 0);   // black
        ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
        break;
    }


    }


    }

   // string msg;
   // msg += "Click to change background color\n";
   // msg += receivedData;
   
    
   // ofDrawBitmapString(msg, 200, 300); // Write the data on the output window
   // font.drawString(msg, 400, 600);


void ofApp::mousePressed(int x, int y, int button) {
    isBackgroundGreen = !isBackgroundGreen; // Toggle the background color
    serialMessage = true; // Send data to Arduino
   // sendData = isBackgroundBlue ? 1 : 0; // Set the data to be sent to Arduino
    hasMouseBeenPressed = true;
    if (button == OF_MOUSE_BUTTON_LEFT) {
        clickCount++;
    }
   
}
