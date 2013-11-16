#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{	
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
    
	str = "Hey, how's it going?";
    textFont.loadFont("mplus-1c-regular.ttf", 36);
    infoFont.loadFont("mplus-1c-regular.ttf", 8);
}

//--------------------------------------------------------------
void testApp::update()
{

}

//--------------------------------------------------------------
void testApp::draw()
{
	ofBackground(120);

    float posY = ofGetHeight() / 2;
    float textY;
    
    float baseline = posY;
    float ascenderY = posY - textFont.getAscender();
    float descenderY = posY - textFont.getDescender();
    float xHeightY = posY - textFont.getXHeight();
    float lineHeight = textFont.getLineHeight();
    
    ofSetColor(180);
    ofRect(0, ascenderY, ofGetWidth(), lineHeight);
    
    ofSetColor(220);
    ofRect(0, posY, ofGetWidth(), -textFont.getXHeight());
    
    ofSetColor(200, 0, 0);
    ofLine(0, baseline, ofGetWidth(), baseline);
    infoFont.drawString("baseline", ofGetWidth() - infoFont.stringWidth("baseline") - 10, baseline);
    
    ofSetColor(0);
    ofLine(0, ascenderY, ofGetWidth(), ascenderY);
    textY = xHeightY - ((textFont.getAscender() - textFont.getXHeight()) - infoFont.stringHeight("ascender")) / 2;
    infoFont.drawString("ascender", 10, textY);

    ofLine(0, descenderY, ofGetWidth(), descenderY);
    textY = baseline + (infoFont.stringHeight("descender") - textFont.getDescender()) / 2;
    infoFont.drawString("descender", 10, textY);

    ofSetColor(0);
    ofLine(0, xHeightY, ofGetWidth(), xHeightY);
    textY = baseline - (textFont.getXHeight() - infoFont.stringHeight("x-height")) / 2;
    infoFont.drawString("x-height", 10, textY);

    ofSetColor(0);
	textFont.drawString(str, (ofGetWidth() - textFont.stringWidth(str)) / 2, posY);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
    
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