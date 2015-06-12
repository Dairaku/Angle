#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(60);
    spacekeypressed = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    mousePos.x =mouseX-ofGetWidth()/2;
    mousePos.y =mouseY-ofGetHeight()/2;
    
    radius =hypotf(mousePos.x, mousePos.y);
    angle = atan2(-mousePos.y, mousePos.x)*180/pi;//atan2はポイントとx軸によって表される角度(radian)を返す。
    color.setHsb((atan2(mousePos.y, mousePos.x)+pi)/(2*pi)*255.0, 255, 255);
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
    //外側の円を書く
    ofSetColor(color);
    ofSetLineWidth(2);
    ofNoFill();//塗りつぶしなし
    ofCircle(0, 0, radius);
    
    //内側の円を書く
    ofFill();
    ofCircle(0,0,radius/4);
    
    //マウスと座標系の中心を直線でつなぐ
    ofLine(0,0, mousePos.x , mousePos.y);
    
    //マウスの位置に十字を書く(黒色)
    ofSetColor(0);
    ofLine(mousePos.x, -ofGetHeight()/2, mousePos.x , ofGetHeight()/2);
    ofLine(-ofGetWidth()/2 , mousePos.y , ofGetWidth()/2, mousePos.y);
    
    if (spacekeypressed){
        // 半径と角度を表示
        ofSetColor(100);
        ofDrawBitmapString("radius: " + ofToString(radius), mousePos.x + 5, mousePos.y + 15);
        ofDrawBitmapString("angle: " + ofToString(angle), mousePos.x + 5, mousePos.y + 25);
        
        //ofDrawBitmapString:(文字列,x座標の場所,y座標の場所
        
        ofSetColor(150, 150, 150, 200);
        for(int i= 1;i< 100;i++){
            ofBeginShape();
            ofVertex(0,0);
            ofVertex(radius, 0);
            ofVertex(mousePos.x/i, mousePos.y/i);
            ofVertex(0,0);
            ofEndShape();
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key){
        case ' ' :
            spacekeypressed = true;
            break;
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
