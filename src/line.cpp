//
//  line.cpp
//  generative-logo
//
//  Created by Jayce Rudig-Leathers on 11/18/16.
//
//

#include <stdio.h>
#include "line.h"
#include "ofMain.h"

line::line(ofVec2f origin, ofVec2f endpoint) {
    this->origin = origin;
    this->endpoint = endpoint;
    this->length = origin.distance(endpoint);
    this->direction = atan2(endpoint.y - origin.y, endpoint.x - origin.x);
}

line::line(ofVec2f origin, float length, float direction) {
    this->origin = origin;
    this->length = length;
    this->direction = direction;
    this->endpoint = *new ofVec2f(cos(direction) * length + origin.x, sin(direction) * length + origin.y);    
}

void line::draw() {
    ofDrawLine(origin, endpoint);
}

ofVec2f line::getOrigin() {
    return origin;
}

ofVec2f line::getEndpoint() {
    return endpoint;
}

float line::getLength() {
    return length;
}

float line::getDirection() {
    return direction;
}

