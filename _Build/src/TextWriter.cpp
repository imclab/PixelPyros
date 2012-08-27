//
//  TextWriter.cpp
//  PixelPyros
//
//  Created by Paul King on 27/08/2012.
//

#include "TextWriter.h"

// From http://www.cplusplus.com/faq/sequences/strings/trim/
inline std::string trim(const std::string &s) {
    return s.substr(0, s.find_last_not_of(" ") + 1);
}

TextWriter::TextWriter() {
    glyphWidth = 4;
    glyphHeight = 10;
    glyphSpacing = 1.5;
    glyphLineWeight = 2;
    
    glyphRatio = glyphHeight / (float)glyphWidth;
}

int TextWriter::findBestBreak(string s, int start, int radius) {
    int bestIndex = start;
    float bestWeight = 0, examWeight;
    
    radius = MIN(MIN(start + radius, s.length() - 1) - start, start - MAX(start - radius, 0));
    
    for( int i = start - radius; i <= start + radius; i++ ) {
        if( s[i] != ' ' ) {
            continue;
        }
        
        examWeight = 10 / (float)abs(start - i);
        if( examWeight > bestWeight ) {
            bestIndex = i;
            bestWeight = examWeight;
        }
    }
    
    return MIN(bestIndex + 1, s.length());
}

int TextWriter::calculateBlockWidth(string s, int glyphRenderWidth, int glyphRenderSpacing) {
    int len = s.length();
    
    return (len * glyphRenderWidth) + (glyphRenderSpacing * (len - 1));
}

void TextWriter::renderGlyph(Letter &letter, int w, int h) {
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_LINES);
    
    for( int i = 0; i < letter.points.size(); i++ ) {
        float vx = ofMap(letter.points[i].x, 0, glyphWidth, 0, w);
        float vy = ofMap(letter.points[i].y, 0, glyphHeight, 0, h);
        
        mesh.addVertex(ofVec2f(vx, vy));
        mesh.addColor(ofColor(0, 255, 10));
    }
    mesh.draw();
}

void TextWriter::drawGlyph(Letter &letter, ofRectangle box) {
    ofPushMatrix();
    
    ofTranslate(box.x, box.y);
    
    // Debug
    /*
    ofSetColor(50, 50, 50);
    ofNoFill();
    ofRect(0, 0, box.width, box.height);
    */
    
    renderGlyph(letter, box.width, box.height);
    
    ofPopMatrix();
}

void TextWriter::draw(ofRectangle box, string text) {
    text = ofToUpper(text);
    
	// added these lines otherwise you get horribleness! 
	if(box.height<=0) box.height = 1;
	if(box.width<=0) box.width = 1;
	
	
    ofPushStyle();
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofSetLineWidth(glyphLineWeight);
    ofNoFill();
	ofRect(box);
	// Debug
    /*
    ofSetColor(255, 0, 0);
    ofNoFill();
    ofRect(box);
    */
    
    float boxRatio = box.height / (float)box.width;
    int textLength = text.length();
    string longestLine = "";
    vector<string> lines;
    
    int numRows = (int)sqrt(boxRatio * textLength / glyphRatio);
    if( (text.find(' ') == string::npos) || (numRows == 0) ) {
        lines.push_back(text);
        longestLine = text;
    } else {
        int numCols = textLength / numRows;
        int start = numCols;
        int index = 0;
        int last;
        
        for( int row = 0; row < numRows - 1; row++ ) {
            last = index;
            index = findBestBreak(text, start, numCols * 2);
            
            string linePart = trim(text.substr(last, index - last));
            
            if( linePart.length() > longestLine.length() ) {
                longestLine = linePart;
            }
            
            lines.push_back(linePart);
            // std::cout << linePart << std::endl;
            
            start = index + numCols;
        }
        
        //lines.back().append(text.substr(index));
        string linePart = trim(text.substr(index));
        lines.push_back(linePart);
        if( linePart.length() > longestLine.length() ) {
            longestLine = linePart;
        }
        
        // std::cout << text.substr(index) << std::endl;
    }
    
    float glyphScaleFactor = (box.width / (float)longestLine.length()) / (float)(glyphWidth + glyphSpacing);
    float glyphRenderWidth = glyphWidth * glyphScaleFactor;
    float glyphRenderHeight = glyphHeight * glyphScaleFactor;
    float glyphRenderSpacing = glyphSpacing * glyphScaleFactor;
    
    int marginTop = (int)((box.height - ((glyphRenderHeight + glyphRenderSpacing) * lines.size())) / 2.0);
    int marginLeft = (int)((box.width - calculateBlockWidth(longestLine, glyphRenderWidth, glyphRenderSpacing)) / 2.0); 
    
    map <int, Letter>& letters = font.letters;
    
    int ofsX = marginLeft, ofsY = marginTop;
    for( int j = 0; j < lines.size(); j++ ) {
        string line = lines[j];
        int glyphMarginLeft = ((box.width - calculateBlockWidth(line, glyphRenderWidth, glyphRenderSpacing)) / 2.0) - marginLeft;
        for( int i = 0; i < line.length(); i++ ) {
            drawGlyph(letters[line[i]], ofRectangle(box.x + ofsX + glyphMarginLeft, box.y + ofsY, glyphRenderWidth, glyphRenderHeight));
            ofsX += glyphRenderWidth + glyphRenderSpacing;
        }
        ofsX = marginLeft;
        ofsY += glyphRenderHeight + glyphRenderSpacing;
    }
    
    ofPopStyle();
}

