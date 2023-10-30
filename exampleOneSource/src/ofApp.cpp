#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCoordHandedness(OF_LEFT_HANDED);
    keyIsDown = false;
    
    lvelocity = glm::vec3(0, 0, 0);
    lup = glm::vec3(0, 0, 1);
    lforward = glm::vec3(0, 1, 0);
    lpositionScreen = glm::vec3(ofGetWidth()/2.f*scale, ofGetHeight()/2.f*scale, 0);
    lposition = lpositionScreen;
    int intialXPos = ofRandom(ofGetWidth());
    int intialYPos = ofRandom(ofGetHeight());
    spositionScreen = glm::vec3(intialXPos*scale, intialYPos*scale, 0);
    svelocityScreen = glm::vec3(0, 0, 0);
    
    sposition = glm::vec3((ofGetWidth() - intialXPos) *scale, (ofGetHeight() - intialYPos) * scale, 0);;
    svelocity = svelocityScreen;
    player.load(ofToDataPath("organ.wav"));
    player.setLoop(true);
    player.setVolume(0.75);
    player.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    ofxFmod3DUpdateListener(lposition, lvelocity, lforward, lup);
    if (mouseIsDown) {
        if(keyIsDown) {
            lpositionScreen.x = mouseX * scale;
            lpositionScreen.y = mouseY * scale;
            lposition.x = (ofGetWidth() - mouseX) *scale;
            lposition.y = (ofGetHeight() - mouseY) *scale;
        } else {
            spositionScreen.x = mouseX*scale;
            spositionScreen.y = mouseY*scale;
            sposition.x = (ofGetWidth() - mouseX) *scale;
            sposition.y = (ofGetHeight() - mouseY) *scale;
        }
    }
    player.update(sposition, svelocity);
    ofSoundUpdate();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetHexColor(0xff0000);
    ofDrawEllipse(spositionScreen.x*(1/scale), spositionScreen.y*(1/scale), 10, 10);
    ofSetHexColor(0x0000ff);
    ofDrawEllipse(lpositionScreen.x*(1/scale), lpositionScreen.y*(1/scale), 10, 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    keyIsDown = true;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    keyIsDown = false;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (button == 0) {
        mouseIsDown = true;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if (button == 0) {
        mouseIsDown = false;
    }
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
