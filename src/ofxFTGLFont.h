

#pragma once

#include "ofMain.h"
#include "ftgl.h"

class ofxFTGLFont {

  public:
	ofxFTGLFont();
    ~ofxFTGLFont();
	bool 		loadFont(string filename, float fontsize = 10, bool _bAntiAliased = false, bool _bFullCharacterSet = false, bool makeContours = false);
    bool 		isLoaded();
    
	void 		setSize(int size);
	float 		getLineHeight();
    void		setLineHeight(float newHeight);
	ofRectangle getStringBoundingBox(string s, float x, float y);

	void 		drawString(string s, float x, float y);

    FTFont*  font;
  protected:
    bool loaded;
    float lineHeight;
};

