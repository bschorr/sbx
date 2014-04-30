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
    
    sb.connect( "localhost", config );
    
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
    ofBackground(50);
    ofSetColor(0);
    
    
    for (int i = 0; i < pList.size(); i++) {
        pList[i].draw();
    }
    
}

//--------------------------------------------------------------
void testApp::onMessage( Spacebrew::Message & m ){
    inParticles.setValue(m);
    pList[inParticles.getInt("id")].pos.x = inParticles.getInt("pos", "x");
    pList[inParticles.getInt("id")].pos.y = inParticles.getInt("pos", "y");
    
    pList[inParticles.getInt("id")].color.r = inParticles.getInt("color", "r");
    pList[inParticles.getInt("id")].color.g = inParticles.getInt("color", "g");
    pList[inParticles.getInt("id")].color.b = inParticles.getInt("color", "b");

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
