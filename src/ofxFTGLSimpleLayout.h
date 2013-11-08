

#pragma once

#include "ofMain.h"
#include "ftgl.h"

typedef	FTGL::TextAlignment ofxFTGLTextAlignment;

#define FTGL_ALIGN_LEFT     FTGL::ALIGN_LEFT
#define FTGL_ALIGN_CENTER   FTGL::ALIGN_CENTER
#define FTGL_ALIGN_RIGHT    FTGL::ALIGN_RIGHT
#define FTGL_ALIGN_JUSTIFY  FTGL::ALIGN_JUSTIFY

class ofxFTGLSimpleLayout {

  public:
	ofxFTGLSimpleLayout();
    ~ofxFTGLSimpleLayout();
	
    void        unload();
    bool 		loadFont(string filename, float fontsize = 10, float depth = 0, bool bUsePolygons = false);
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
   
    float       getLineLength() const;
    void        setLineLength(float length);
	float       getLineSpacing() const;
    void		setLineSpacing(float spacing);
    
    ofxFTGLTextAlignment getAlignment() const;
    void setAlignment(ofxFTGLTextAlignment alignment);
    
	
    FTFont*  font;
    FTSimpleLayout* layout;
    
  protected:
    bool loaded;
};

