#include "ofApp.h"

int xs[11], ys[11];
int points = -1;

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
    if (points >= 10) {
        points = -1;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (points == -1) return;
    ofSetColor(255);
    ofDrawEllipse(xs[0], ys[0], 20, 20);
    for (int i = 1; i <= points; ++i) {
        ofSetColor(200 + i * 2, i * 6 + 135, i * 5 + 100);
        ofDrawLine(xs[i - 1], ys[i - 1], xs[i], ys[i]);
    }
    
    if (points >= 9) {
        ofSetColor(255);
        ofDrawEllipse(xs[9], ys[9], 20, 20);
        ofDrawBitmapString("Max point selection reached", ofGetWidth() / 2, ofGetHeight() / 2);
        return;
    }
}

//--------------------------------------------------------------
void ofApp::exit(){

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
    points++;
    xs[points] = x;
    ys[points] = y;
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
