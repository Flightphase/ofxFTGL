#include "ofxFTGLFont.h"

ofxFTGLFont::ofxFTGLFont(){
    loaded = false;
    font = NULL;
}

ofxFTGLFont::~ofxFTGLFont(){
    if(loaded){
//        delete font;
    }
}

bool ofxFTGLFont::loadFont(string filename, float fontsize, bool _bAntiAliased, bool _bFullCharacterSet, bool makeContours){

    font = new FTTextureFont(ofToDataPath(filename).c_str());
	lineHeight = fontsize * 1.43f;
    
    font->Outset(0.0f, fontsize);

    font->CharMap(ft_encoding_unicode);

    if(font->Error()){
        ofLogError("ofxFTGLFont") << "Error loading font " << filename;
        delete font;
		return false;
    }    
    
    if(!font->FaceSize(fontsize)){
        ofLogError("ofxFTGLFont") << "Failed to set font size";
        delete font;
		return false;
    }
    
    loaded = true;
    return true;
}

bool ofxFTGLFont::isLoaded(){
    return loaded;
}

void ofxFTGLFont::setSize(int size){
    if(loaded){
	    font->FaceSize(size);
    }
}

float ofxFTGLFont::getLineHeight(){
	return lineHeight;
}
    

void ofxFTGLFont::setLineHeight(float newHeight){
    lineHeight = newHeight;
}

ofRectangle ofxFTGLFont::getStringBoundingBox(string s, float x, float y){
    if(loaded){
    	FTBBox bbox = font->BBox(s.c_str());
	    return ofRectangle(x + bbox.Lower().Xf(), y + bbox.Lower().Yf(), bbox.Upper().Xf(), bbox.Upper().Yf());
    }
	return ofRectangle();
}

void ofxFTGLFont::drawString(string s, float x, float y){
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(1,-1,1);
    font->Render(s.c_str());
    glPopMatrix();
}
