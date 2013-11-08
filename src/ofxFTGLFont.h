

#pragma once

#include "ofMain.h"
#include "ftgl.h"

class ofxFTGLFont {
    
  public:
	ofxFTGLFont();
    ~ofxFTGLFont();
	
    void        unload();
    bool 		loadFont(string filename, float fontsize, float depth = 0, bool bUsePolygons = false);
    bool 		isLoaded();
    
	void 		setSize(int size);
	
    float       getLineHeight() const;
    float       getAscender() const;
    float       getDescender() const;
    float       getXHeight() const;
	
    ofRectangle getStringBoundingBox(wstring s, float x, float y);
	ofRectangle getStringBoundingBox(string s, float x, float y);

	void 		drawString(wstring s, float x, float y);
	void 		drawString(string s, float x, float y);
	float 		stringHeight(string c);
	float 		stringWidth(string c);
	
    FTFont*  font;
    
  protected:
    bool loaded;
};

