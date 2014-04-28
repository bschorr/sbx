#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    //set names to your SB inputs and outputs
    inParticles.setName("inParticles");
    
    //set types to your SB inputs and outputs
    inParticles.setType("particle");
    
    //load their datatypes from your json file in the data folder
    inParticles.loadType("particle.json");
    
    //Spacebrew configs and listener
    Spacebrew::Config config;
    config.clientName = "Spacebrew Particle Receiver";
    
    config.addSubscribe(inParticles);
    
    sb.connect( Spacebrew::SPACEBREW_CLOUD, config );
    
    Spacebrew::addListener(this, sb);
    
    //initialize particle system
    for (int i = 0; i < 5; i++) {
        Particle p;
        pList.push_back(p);
    }
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(255, 0, 0);
    ofSetColor(0);
    
    
    for (int i = 0; i < pList.size(); i++) {
        pList[i].draw();
    }
    
}

//--------------------------------------------------------------
void testApp::onMessage( Spacebrew::Message & m ){
    inParticles.setValue(m);
    
    //get position values according to particle ID
    pList[inParticles.getInt("id")].pos.x = inParticles.getInt("x");
    pList[inParticles.getInt("id")].pos.y = inParticles.getInt("y");

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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