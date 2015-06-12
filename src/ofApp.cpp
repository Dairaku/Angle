#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(60);
    KeyPressed = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    mousePos.x =mouseX-ofGetWidth()/2;
    mousePos.y =mouseY-ofGetHeight()/2;
    
    radius = hypotf(mousePos.x, mousePos.y);
    angle = atan2(-mousePos.y, mousePos.x)*180/pi;//atan2はポイントとx軸によって表される角度(radian)を返す。
    if(angle < 0){
        angle = angle + 360;
    }

    if(KeyPressed){
        radius = radius + ofRandom(-10, 10);
    }
    
    color.setHsb(angle/360*255.0, 255, 255);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //方眼紙を書く
    ofPushStyle();
    ofSetColor(128);
    ofSetLineWidth(1);
    for(int i=0;i<30;i++){
        ofLine(i*ofGetWidth()/30, 0, i*ofGetWidth()/30, ofGetHeight());
        ofLine(0, i*ofGetWidth()/30, ofGetWidth(), i*ofGetWidth()/30);
    }
    ofPopStyle();
    
    //座標系の中心をスクリーンの中心に
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    //外側の円を書く
    ofSetColor(color);
    ofSetLineWidth(2);
    ofNoFill();//塗りつぶしなし
    ofCircle(0, 0, radius);
    
    //内側の円を書く
    ofFill();
    ofCircle(0,0,radius/4);
    
    //マウスと座標系の中心を直線でつなぐ
    ofLine(0,0, mousePos.x, mousePos.y);
    
    //マウスの位置に十字を書く(黒色)
    ofSetColor(0);
    ofLine(mousePos.x, -ofGetHeight()/2, mousePos.x , ofGetHeight()/2);
    ofLine(-ofGetWidth()/2 , mousePos.y , ofGetWidth()/2, mousePos.y);
    
    //スペースキーが押されたとき
    if (KeyPressed){
        ofSetColor(100);
        ofDrawBitmapString("radius: " + ofToString(radius), mousePos.x + 5, mousePos.y + 15);
        ofDrawBitmapString("angle: " + ofToString(angle), mousePos.x + 5, mousePos.y + 35);
        //ofDrawBitmapString:(文字列,x座標の場所,y座標の場所)
        //扇型を描写
        ofSetColor(150, 150, 150, 200);
        
        ofBeginShape();
        ofVertex(0,0);
        ofVertex(radius, 0);
        for(int i= 1;i< (int)angle; i++){
            ofVertex(radius*cosf(i*pi/180), -radius*sinf(i*pi/180));//angleをラジアンに変換→cos、sinに代入 ofVertaxはなぜ-?
        }//angleはintではないのでキャスト
        ofEndShape();
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key){
        case ' ' :
            KeyPressed = !KeyPressed;
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
