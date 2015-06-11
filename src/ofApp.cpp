#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(60);
    }

//--------------------------------------------------------------
void ofApp::update(){
    radius =hypotf(mouseX-ofGetWidth()/2, mouseY-ofGetHeight()/2);
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
    ofSetLineWidth(2);
    
    //外側の円を書く
    ofSetColor(0);
    ofNoFill();//塗りつぶしなし
    ofCircle(0, 0, radius);
    
    //内側の円を書く
    ofFill();
    ofCircle(0,0,radius/4);
    
    //マウスと座標系の中心を直線でつなぐ
    ofLine(0,0, mouseX-ofGetWidth()/2 , mouseY-ofGetHeight()/2);
    
    //マウスの位置に十字を書く
    ofLine(mouseX-ofGetWidth()/2, -ofGetHeight()/2, mouseX-ofGetWidth()/2 , ofGetHeight()/2);
    ofLine(-ofGetWidth()/2 , mouseY-ofGetHeight()/2 , ofGetWidth()/2, mouseY-ofGetHeight()/2);
    

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
