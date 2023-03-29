#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(0);
	ofSetCircleResolution(100);
	ofSetDepthTest(true);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	float time = ofGetElapsedTimef(); //retrieves the elapsed time in seconds since the application started runningand assigns it to a variable named time
	//starts a for loop that will run 19 times.The loop variable x starts at 1 and increases by 1 until it reaches 19
	for (int x = 1; x < 20; x++) {
	    // starts another for loop that will run 180 times. The loop variable i starts at 0 and increases by 5 until it reaches 895
		for (int i = 0; i < 900; i += 5) {
            //sets colour of graphics, colour variation controlled by sin and time functions
            //Draws circle movement controlled by tan and time functions
			ofSetColor(127 + 127 * sin(i * 0.04 + time), 127 + 127 * sin(i * 0.05 + time), 127 + 127 * sin(i * 0.012 + time));
			ofDrawCircle(50 * x + 100 * tan(i * 0.01 + time + x), 50 + i, 50 + 30 * tan(i * 0.005 + time));
			
			//Other Variations
			//ofDrawCircle(ofGetWidth() / 2, i, 100);
			//ofDrawCircle(ofGetWidth() / 2 + 100 * sin(i * 0.01 + time), 50 + i, 50 + 40 * sin(i * 0.005 + time));


		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
