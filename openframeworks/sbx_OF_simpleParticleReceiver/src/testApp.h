#pragma once

#include "ofMain.h"
#include "ofxSpacebrew.h"
#include "sbxCustom.h"
#include "Particle.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        Spacebrew::Connection sb;
    
        //Spacebrew library uses this method to get incoming data
        void onMessage( Spacebrew::Message & m );
    
        //in this example we're using sbx to send particles, holding their screen position and an ID
        sbx::custom inParticles;
        vector <Particle> pList;
};
