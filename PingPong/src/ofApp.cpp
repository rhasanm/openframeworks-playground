#include "ofApp.h"

// bar
int xLeft = 0;
int yLeft = 0;
int xRight = -1;
int yRight = 0;
int barWidth = 10;
int barHeight = 80;
int barRadius = 5;

// ball
int xBall = 45;
int yBall = 45;
int wBall = 25;
int hBall = 25;
float yMargin = ofRandom(1) * 2;
int dBall = -1;

bool leftLost = false;
bool rightLost = false;
bool leftTurn = true;
//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
    yMargin = ofRandom(1) * 2;
    
    if (xBall <= 15) {
        if (yBall >= yLeft && yBall <= yLeft + barHeight) {
            leftTurn = false;
        } else {
            leftLost = true;
        }
    }
    
    if (xBall >= ofGetWidth() - 10) {
        if (yBall >= yRight && yBall <= yRight + barHeight) {
            leftTurn = true;
        } else {
            rightLost = true;
        }
    }
    
    if (yBall >= ofGetHeight() - 10) {
        dBall *= -1;
    }
    
    if (yBall <= 0) {
        dBall *= -1;
    }
    
    yBall += yMargin * dBall;
    
    if (!leftTurn) {
        xBall += 1;
    } else {
        xBall -= 1;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (xRight == -1) xRight = ofGetWidth() - 10;
    
    if (leftLost) {
        ofDrawBitmapString("LEFT LOST", ofGetHeight() / 2, ofGetWidth() / 2);
        return;
    }
    
    if (rightLost) {
        ofDrawBitmapString("RIGHT LOST", ofGetHeight() / 2, ofGetWidth() / 2);
        return;
    }
    ofDrawRectRounded(ofRectangle(xLeft, yLeft, barWidth, barHeight), barRadius);
    ofDrawRectRounded(ofRectangle(xRight, yRight, barWidth, barHeight), barRadius);
    
    ofDrawEllipse(xBall, yBall, wBall, hBall);
    
    ofDrawLine(ofGetWidth() / 2, 0, ofGetWidth() / 2, ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case OF_KEY_DOWN:
            if (leftTurn) {
                yLeft += 10;
            } else {
                yRight += 10;
            }
            break;
        case OF_KEY_UP:
            if (leftTurn) {
                yLeft -= 10;
            } else {
                yRight -= 10;
            }
    }
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
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

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
