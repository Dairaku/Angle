#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(60);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //方眼紙を書く
    ofSetColor(128);
    for(int i=0;i<30;i++){
        ofLine(i*ofGetWidth()/30, 0, i*ofGetWidth()/30, ofGetHeight());
        ofLine(0, i*ofGetWidth()/30, ofGetWidth(), i*ofGetWidth()/30);
    }
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);//座標系の中心をスクリーンの中心に
    ofSetColor(0);
    ofNoFill();//塗りつぶしなし
    radius =hypotf(mouseX,mouseY);
    ofCircle(0, 0, radius);

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
