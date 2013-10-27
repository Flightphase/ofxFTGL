#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetFrameRate(30);
	ofSetVerticalSync(true);
	
	ofEnableAlphaBlending();
    
    margin = 20;
    
    // layout will wrap your text depending on the line length you set, or when you insert line breaks into the text manually (\n)
    layout.loadFont("mplus-1c-regular.ttf", 12, true);
    layout.setLineLength(ofGetWidth() - margin * 2);
    
	str = "初音ミク. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Phasellus gravida quam ut aliquet rhoncus. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Mauris ornare felis vitae enim fringilla, at pulvinar quam venenatis.\n \nSed facilisis malesuada nisi vitae gravida. Sed id nulla sit amet dolor luctus dignissim vel sit amet augue. Integer mi dolor, cursus non felis vitae, euismod sollicitudin enim. Suspendisse turpis orci, rhoncus eu metus eget, semper ornare purus. Donec quam tellus, varius a ligula vel, dignissim blandit dolor. Duis rutrum nisl felis, in tempor nulla gravida vitae.";
}

//--------------------------------------------------------------
void testApp::update(){
    layout.setLineLength(MAX(margin * 2, ofGetMouseX() - margin * 2));
    layout.setLineSpacing(ofMap(ofGetMouseY(), 0, ofGetHeight(), 0.0f, 2.0f, true));
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(255);
	ofSetColor(0);
	layout.drawString(str, margin, 100);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
    switch (key) {
        case '1':
            layout.setAlignment(FTGL_ALIGN_LEFT);
            break;
        case '2':
            layout.setAlignment(FTGL_ALIGN_CENTER);
            break;
        case '3':
            layout.setAlignment(FTGL_ALIGN_RIGHT);
            break;
        case '4':
            layout.setAlignment(FTGL_ALIGN_JUSTIFY);
            break;
            
        default:
            break;
    }
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