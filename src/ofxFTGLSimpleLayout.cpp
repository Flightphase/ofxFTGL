#include "ofxFTGLSimpleLayout.h"

ofxFTGLSimpleLayout::ofxFTGLSimpleLayout(){
    loaded = false;
    font = NULL;
}

ofxFTGLSimpleLayout::~ofxFTGLSimpleLayout(){
	if(font != NULL){
        //delete font;
    }
}

bool ofxFTGLSimpleLayout::loadFont(string filename, float fontsize, bool _bAntiAliased, bool _bFullCharacterSet, bool makeContours, float simplifyAmnt, int dpi){
	fontsize *= 2;
    layout = new FTSimpleLayout();
    font = new FTTextureFont(ofToDataPath(filename).c_str());
//	lineHeight = fontsize * 1.43f;
  	lineHeight = fontsize;
  
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
    
    layout->SetFont(font);
    
    return true;
}


bool ofxFTGLSimpleLayout::setLineLength(float l){
    layout->SetLineLength(l);
}

float ofxFTGLSimpleLayout::stringWidth(string c){
    ofRectangle rect = getStringBoundingBox(c, 0,0);
    return rect.width;
}

float ofxFTGLSimpleLayout::stringHeight(string c) {
    ofRectangle rect = getStringBoundingBox(c, 0,0);
    return rect.height;
}

bool ofxFTGLSimpleLayout::isLoaded(){
    return loaded;
}

void ofxFTGLSimpleLayout::setSize(int size){
    if(loaded){
	    font->FaceSize(size);
    }
}

float ofxFTGLSimpleLayout::getLineHeight(){
	return lineHeight;
}

void ofxFTGLSimpleLayout::setLineHeight(float newHeight){
    lineHeight = newHeight;
}

ofRectangle ofxFTGLSimpleLayout::getStringBoundingBox(string s, float x, float y){
    if(loaded){
    	FTBBox bbox = layout->BBox(s.c_str());
	    return ofRectangle(x + bbox.Lower().Xf(), y + bbox.Lower().Yf(), bbox.Upper().Xf(), bbox.Upper().Yf());
    }
	return ofRectangle();
}

ofRectangle ofxFTGLSimpleLayout::getStringBoundingBox(wstring s, float x, float y){
    if(loaded){
    	FTBBox bbox = layout->BBox((wchar_t*)s.c_str());
	    return ofRectangle(x + bbox.Lower().Xf(), y + bbox.Lower().Yf(), bbox.Upper().Xf(), bbox.Upper().Yf());
    }
	return ofRectangle();
}

void ofxFTGLSimpleLayout::drawString(string s, float x, float y){
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(1,-1,1);

    layout->Render(s.c_str());
    glPopMatrix();
}

void ofxFTGLSimpleLayout::drawString(wstring s, float x, float y){
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(1,-1,1);
    layout->Render((wchar_t*)s.c_str());
    glPopMatrix();
}
