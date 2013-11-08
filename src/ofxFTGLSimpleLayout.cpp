#include "ofxFTGLSimpleLayout.h"

ofxFTGLSimpleLayout::ofxFTGLSimpleLayout()
{
    loaded = false;
    font = NULL;
    layout = NULL;
}

ofxFTGLSimpleLayout::~ofxFTGLSimpleLayout()
{
//	unload();
}

void ofxFTGLSimpleLayout::unload()
{
    if (font != NULL) {
        delete font;
        font = NULL;
    }
    if (layout != NULL) {
        delete layout;
        layout = NULL;
    }
    
    loaded = false;
}

bool ofxFTGLSimpleLayout::loadFont(string filename, float fontsize, float depth, bool bUsePolygons)
{
	unload();
    
    fontsize *= 2;
    
    layout = new FTSimpleLayout();
    
    if (depth != 0) {
        font = new FTExtrudeFont(ofToDataPath(filename).c_str());
        font->Depth(depth);
    }
    else if (bUsePolygons) {
        font = new FTPolygonFont(ofToDataPath(filename).c_str());
    }
    else {
        font = new FTTextureFont(ofToDataPath(filename).c_str());
    }
    
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


float ofxFTGLSimpleLayout::stringWidth(string c)
{
    if (c.compare(" ") == 0) {
        // FTGL won't measure a space width properly, so we
        // have to use this hack to get that value.
        return (stringWidth("A A") - stringWidth("AA"));
    }
    else {
        ofRectangle rect = getStringBoundingBox(c, 0,0);
        return rect.width;
    }
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

float ofxFTGLSimpleLayout::getLineHeight() const
{
    if (loaded) {
        return font->LineHeight();
    }
    return 0;
}

float ofxFTGLSimpleLayout::getAscender() const
{
    if (loaded) {
        return font->Ascender();
    }
    return 0;
}

float ofxFTGLSimpleLayout::getDescender() const
{
    if (loaded) {
        return font->Descender();
    }
    return 0;
}

float ofxFTGLSimpleLayout::getXHeight() const
{
    if (loaded) {
        return font->LineHeight() - font->Ascender() - font->Descender();
    }
    return 0;
}

float ofxFTGLSimpleLayout::getLineLength() const
{
	return layout->GetLineLength();
}

void ofxFTGLSimpleLayout::setLineLength(float length)
{
    layout->SetLineLength(length);
}

float ofxFTGLSimpleLayout::getLineSpacing() const
{
	return layout->GetLineSpacing();
}

void ofxFTGLSimpleLayout::setLineSpacing(float spacing)
{
    layout->SetLineSpacing(spacing);
}

ofxFTGLTextAlignment ofxFTGLSimpleLayout::getAlignment() const
{
    return layout->GetAlignment();
}

void ofxFTGLSimpleLayout::setAlignment(ofxFTGLTextAlignment alignment)
{
    layout->SetAlignment(alignment);
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
