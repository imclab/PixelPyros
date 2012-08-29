//
//  TextWriter.h
//  PixelPyros
//
//  Created by Paul King on 27/08/2012.
//

#pragma once 

#include <map>
#include "ofGraphics.h"
#include "VectorFont.h"

class TextWriter {
    
public:
    
    TextWriter();
    void draw(ofRectangle, string);
    
    float glyphSpacing, glyphLineSpacing, glyphLineWeight;
    
private:
    
    int findBestBreak(string, int, int);
    int calculateBlockWidth(string, int, int);
    //void drawGlyph(Letter&, ofRectangle);
    void addGlyphToMesh(Letter&, ofRectangle, ofMesh& );

    int glyphWidth, glyphHeight;
    float glyphRatio;
    VectorFont font;
};
