#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    //set names to your SB inputs and outputs
    outParticles.setName("outParticles");
    
    //set types to your SB inputs and outputs
    outParticles.setType("particle");
    
    //load their datatypes from your json file in the data folder
    outParticles.loadType("particle.json");
    
    //Spacebrew configs and listener
    Spacebrew::Config config;
    config.clientName = "Spacebrew Particle Sender";
    
    config.addPublish(outParticles);
    
    sb.connect( Spacebrew::SPACEBREW_CLOUD, config );
    
    Spacebrew::addListener(this, sb);
    
    //initialize particle system
    for (int i = 0; i < 5; i++) {
        Particle p;
        ofVec2f initPos = ofVec2f (ofRandomWidth(), ofRandomHeight());
        ofVec2f initVel = ofVec2f (ofRandom(-5,5), ofRandom(-5,5));
        ofColor color = ofColor (ofRandom(255), ofRandom(255), ofRandom(255));
        p.setup(initPos, initVel, color);
        pList.push_back(p);
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    ofBackground(0);
    
    for (int i = 0; i < pList.size(); i++) {
        pList[i].update();
        outParticles.setValue("id", i);
        outParticles.setValue("pos", "x", pList[i].pos.x);
        outParticles.setValue("pos", "y", pList[i].pos.y);
        
        outParticles.setValue("color", "r", pList[i].color.r);
        outParticles.setValue("color", "g", pList[i].color.g);
        outParticles.setValue("color", "b", pList[i].color.b);
        
        //send outgoing position
        sb.send(outParticles);
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
    for (int i = 0; i < pList.size(); i++) {
        pList[i].draw();
    }
    
}

//--------------------------------------------------------------
void testApp::onMessage( Spacebrew::Message & m ){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    for (int i = 0; i < pList.size(); i++) {
            pList[i].color = ofColor (ofRandom(255), ofRandom(255), ofRandom(255));
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
