

#pragma once

#include "ofMain.h"
#include "ftgl.h"

class ofxFTGLSimpleLayout {

  public:
	ofxFTGLSimpleLayout();
    ~ofxFTGLSimpleLayout();
	//the last parameters don't do anything, but are left in so that ofxFTGLFont
	//can be dropped in in place of ofTrueTypeFont without compiler errors
	bool 		loadFont(string filename, float fontsize = 10, bool _bAntiAliased = false, bool _bFullCharacterSet = false, bool makeContours = false, float simplifyAmnt = 0, int dpi = 72);
    bool 		isLoaded();
    
	void 		setSize(int size);
	float 		getLineHeight();
    void		setLineHeight(float newHeight);
	ofRectangle getStringBoundingBox(wstring s, float x, float y);
	ofRectangle getStringBoundingBox(string s, float x, float y);

	void 		drawString(wstring s, float x, float y);
	void 		drawString(string s, float x, float y);
	float 		stringHeight(string c);
	float 		stringWidth(string c);
    bool        setLineLength(float l);
	
    FTFont*  font;
    FTSimpleLayout* layout;
    
  protected:
    bool loaded;
    float lineHeight;
};

