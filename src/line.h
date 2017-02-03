//
//  line.h
//  generative-logo
//
//  Created by Jayce Rudig-Leathers on 11/18/16.
//
//

#ifndef line_h
#define line_h
#include "ofMain.h"

class line {
public:
    void draw();
    line(ofVec2f origin, float length, float direction);
    line(ofVec2f origin, ofVec2f endpoint);
    ofVec2f getOrigin();
    ofVec2f getEndpoint();
    float getLength();
    float getDirection();
    ofVec2f origin;
    ofVec2f endpoint;
    float length;
    float direction;//in radians
};

#endif /* line_h */
