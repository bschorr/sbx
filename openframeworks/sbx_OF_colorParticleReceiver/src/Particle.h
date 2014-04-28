//
//  Particle.h
//  sbxCustom_OF_simple
//
//  Created by Bernardo Santos Schorr on 4/27/14.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    
    void setup(ofVec2f _pos, ofVec2f _vel, ofColor _color);
    void update();
    void draw();
    
    ofVec2f pos;
    ofVec2f vel;
    ofColor color;
    
};
