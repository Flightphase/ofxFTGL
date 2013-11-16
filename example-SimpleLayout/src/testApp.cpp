#include "testApp.h"

int margin;
string alignment;

//--------------------------------------------------------------
void testApp::setup()
{	
	ofSetFrameRate(30);
	ofSetVerticalSync(true);
    
    // Layout will wrap your text depending on the line length you set,
    // or when you insert line breaks into the text manually (\n).

    margin = 20;
    alignment = "LEFT";
    
    layoutInfo.loadFont("mplus-1c-regular.ttf", 8);
    layoutInfo.setLineLength(ofGetWidth() - margin * 2);
    
    layoutText.loadFont("mplus-1c-regular.ttf", 12);
    layoutText.setLineLength(ofGetWidth() - margin * 2);
    
	str = "初音ミク. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Phasellus gravida quam ut aliquet rhoncus. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Mauris ornare felis vitae enim fringilla, at pulvinar quam venenatis.\n \nSed facilisis malesuada nisi vitae gravida. Sed id nulla sit amet dolor luctus dignissim vel sit amet augue. Integer mi dolor, cursus non felis vitae, euismod sollicitudin enim. Suspendisse turpis orci, rhoncus eu metus eget, semper ornare purus. Donec quam tellus, varius a ligula vel, dignissim blandit dolor. Duis rutrum nisl felis, in tempor nulla gravida vitae.";
}

//--------------------------------------------------------------
void testApp::update()
{
    layoutText.setLineLength(MAX(margin * 2, ofGetMouseX() - margin));
    layoutText.setLineSpacing(ofMap(ofGetMouseY(), 0, ofGetHeight(), 0.0f, 2.0f, true));
}

//--------------------------------------------------------------
void testApp::draw()
{
	ofBackground(255);
	
    ofSetColor(128);
    layoutInfo.drawString("FPS: " + ofToString(ofGetFrameRate(), 2) + "\n" +
                          "Line Length (Mouse X): " + ofToString(layoutText.getLineLength()) + "\n" +
                          "Line Spacing (Mouse Y): " + ofToString(layoutText.getLineSpacing()) + "\n" +
                          "Alignment (1-4): " + alignment,
                          margin, 20);
    
    ofSetColor(0);
	layoutText.drawString(str, margin, 120);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
    switch (key) {
        case '1':
            layoutText.setAlignment(FTGL_ALIGN_LEFT);
            alignment = "LEFT";
            break;
        case '2':
            layoutText.setAlignment(FTGL_ALIGN_CENTER);
            alignment = "CENTER";
            break;
        case '3':
            layoutText.setAlignment(FTGL_ALIGN_RIGHT);
            alignment = "RIGHT";
            break;
        case '4':
            layoutText.setAlignment(FTGL_ALIGN_JUSTIFY);
            alignment = "JUSTIFY";
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