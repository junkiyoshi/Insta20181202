#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(39);
	ofEnableDepthTest();
	ofSetLineWidth(3);
}
//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(180);

	int radius = 150;
	for (int i = 0; i < 8; i++) {

		float noise_param_1 = ofRandom(360);
		float noise_param_2 = ofRandom(360);
		glm::vec3 prev = glm::vec3();
		for (int len = 0; len < 200; len += 1) {

			int deg = noise_param_1 + ofNoise(noise_param_2, (ofGetFrameNum() + len) * 0.005) * 360;
			deg = (deg / 30) * 30;
			glm::vec3 location = glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), len * 3);

			if (len != 0) {

				ofDrawLine(location, prev);
			}

			prev = location;
		}

		ofDrawSphere(prev, 3);
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}