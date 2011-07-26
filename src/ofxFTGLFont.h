#ifndef OFX_FTGLFONT_H
#define OFX_FTGLFONT_H

#include "ofMain.h"
#include <FTGL/ftgl.h>

class ofxFTGLFont {

public:

	bool 		loadFont(string filename, float fontsize = 10, bool _bAntiAliased = false, bool _bFullCharacterSet = false, bool makeContours = false);
	void 		setSize(int size);
  	void 		setLineHeight(float height);

	ofRectangle getStringBoundingBox(string s, float x, float y);

	void 		drawString(string s, float x, float y);

    //FTSimpleLayout layout;
    FTFont*  font;
};

#endif
