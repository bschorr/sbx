//
//  Particle.cpp
//  sbxCustom_OF_simple
//
//  Created by Bernardo Santos Schorr on 4/27/14.
//
//

#include "Particle.h"

void Particle::setup(ofVec2f _pos, ofVec2f _vel) {
    pos = _pos;
    vel = _vel;
}

void Particle::update() {
    pos += vel;
    
    if (pos.x > ofGetWindowWidth()) {
        pos.x = ofGetWindowWidth();
        vel.x *= -1;
    }
    
    if (pos.x < 0) {
        pos.x = 0;
        vel.x *= -1;
    }
    
    if (pos.y > ofGetWindowHeight()) {
        pos.y = ofGetWindowHeight();
        vel.y *= -1;
    }
    
    if (pos.y < 0) {
        pos.y = 0;
        vel.y *= -1;
    }
}

void Particle::draw() {
    ofCircle (pos, 10);
}