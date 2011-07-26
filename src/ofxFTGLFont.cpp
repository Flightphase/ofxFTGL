#include "ofxFTGLFont.h"

bool ofxFTGLFont::loadFont(string filename, float fontsize, bool _bAntiAliased, bool _bFullCharacterSet, bool makeContours){
    font = new FTTextureFont(ofToDataPath(filename).c_str());
    font->Outset(0.0f, fontsize);

    font->CharMap(ft_encoding_unicode);

    if(font->Error()){
        ofLog(OF_LOG_ERROR, "error loading font");
		return false;
    }    
    
    if(!font->FaceSize(fontsize)){
        ofLog(OF_LOG_ERROR, "Failed to set size");
		return false;
    }
    return true;
    //layout.SetFont(font);
    //layout.SetLineLength(0.0);
    //layout.SetAlignment(FTGL::ALIGN_JUSTIFY);
}
void ofxFTGLFont::setSize(int size){
    font->FaceSize(size);
}

void ofxFTGLFont::setLineHeight(float height){
   // layout.SetLineLength(height);
}

ofRectangle ofxFTGLFont::getStringBoundingBox(string s, float x, float y){
    FTBBox bbox = font->BBox(s.c_str());
    return ofRectangle(x + bbox.Lower().Xf(), y + bbox.Lower().Yf(), bbox.Upper().Xf(), bbox.Upper().Yf());
}

void ofxFTGLFont::drawString(string s, float x, float y){
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(1,-1,1);
    font->Render(s.c_str(), s.length(), FTPoint(), FTPoint(), FTGL::RENDER_FRONT | FTGL::RENDER_BACK);
    //layout.Render(s.c_str(), -1, FTPoint(0, 0), FTGL::RENDER_FRONT | FTGL::RENDER_BACK);
    glPopMatrix();
}
