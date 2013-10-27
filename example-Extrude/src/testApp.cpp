#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{	
	ofSetFrameRate(30);
	ofSetVerticalSync(true);
    glEnable(GL_DEPTH_TEST);
    
    str = "初音ミク";
    
    // The third parameter is depth, use it to extrude the shape.
    font.loadFont("mplus-1c-regular.ttf", 100, 20);
    
    light.setDiffuseColor(ofColor(200, 64, 64));
    light.setSpecularColor(ofColor(255, 255, 255));
    light.setPosition(ofGetWidth() / 2, ofGetHeight() / 2, 200);
    
    material.setShininess(64);
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw()
{
	ofBackground(255);
    
    ofEnableLighting();
    
    light.enable();
    material.begin();
    cam.begin();
	{
        ofScale(1, -1, 1);  // Flip back since we're in 3D.
        font.drawString(str, font.stringWidth(str) * -0.5f, font.stringHeight(str) * 0.5f);
    }
    cam.end();
    material.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}