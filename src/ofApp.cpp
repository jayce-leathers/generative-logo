#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    stages = *new vector<vector<line>>;
    sceneWidth = 750;
    sceneHeight = 1000;
    ofSetWindowShape(4000, 2000);
    generationZero = 2;
    nextGeneration = generationZero + 1;
    currentDrawnGeneration = generationZero;
    setupInitialStage();
    generate(4);
    ofBackground(0);
    ofSetColor(255);
    isSavingPDF = false;

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    if(isSavingPDF) {
        ofBeginSaveScreenAsPDF("savedScreenshot_" + ofGetTimestampString() + ".pdf");
    }
    
    for (int i = 0; i<=currentDrawnGeneration; i++){
        auto stage = stages[i];
        for (auto & line : stage) {
            line.draw();
        }
    }
    
    if(isSavingPDF) {
        ofEndSaveScreenAsPDF();
        isSavingPDF = false;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 's') {
        isSavingPDF = true;
    }
    if(key == OF_KEY_LEFT) {
        currentDrawnGeneration--;
    }
    if(key == OF_KEY_RIGHT) {
        currentDrawnGeneration++;
        if(currentDrawnGeneration > nextGeneration - 1) {
            
            generateNext();
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}


//simulation
void ofApp::setupInitialStage() {
    
    vector<line> stage0;
    //vert line thru center
    line vert = *new line(*new ofVec2f(sceneWidth * .5  , sceneHeight * .25),
                         *new ofVec2f(sceneWidth * .5 , sceneHeight - sceneHeight * .25));
    //hort line thru center
    line hort = *new line(*new ofVec2f(sceneWidth * .25, sceneHeight * .5),
                         *new ofVec2f(sceneWidth - sceneWidth * .25, sceneHeight * .5 ));
    stage0.push_back(hort);
    stage0.push_back(vert);
    
    
    stages.push_back(stage0);
    
    vector<line> stage0A;
    for( auto branch : stages[0]) {
        stage0A.push_back(*new line(branch.getOrigin(), branch.getLength() * .25, branch.getDirection() - PI * .75));
        stage0A.push_back(*new line(branch.getOrigin(), branch.getLength() * .25, branch.getDirection() + PI * .75));
        
        stage0A.push_back(*new line(branch.getEndpoint(), branch.getLength() * .25, branch.getDirection() + PI * .25));
        stage0A.push_back(*new line(branch.getEndpoint(), branch.getLength() * .25, branch.getDirection() - PI * .25));
    }
    
    stages.push_back(stage0A);
    
    vector<line> stage0B;
    for( auto branch : stages[0]) {
        ofVec2f quarterPointA = *new ofVec2f(cos(branch.getDirection()) * (branch.getLength() * .25)  + branch.getOrigin().x, sin(branch.getDirection()) * (branch.getLength() * .25) + branch.getOrigin().y);
        
        stage0B.push_back(*new line(quarterPointA, branch.getLength() * .25, branch.getDirection() - PI * .75));
        stage0B.push_back(*new line(quarterPointA, branch.getLength() * .25, branch.getDirection() + PI * .75));
        
        ofVec2f quarterPointB = *new ofVec2f(cos(branch.getDirection()) * (branch.getLength() * .75)  + branch.getOrigin().x, sin(branch.getDirection()) * (branch.getLength() * .75) + branch.getOrigin().y);
        
        stage0B.push_back(*new line(quarterPointB, branch.getLength() * .25, branch.getDirection() + PI * .25));
        stage0B.push_back(*new line(quarterPointB, branch.getLength() * .25, branch.getDirection() - PI * .25));
    }
    
    stages.push_back(stage0B);
}

void ofApp::generate(int simulationLength) {
    for(int i = 3; i<=simulationLength; i++) {
        generateNext();
    }
}

void ofApp::generateNext(){
    vector<line> stage;
    for( auto branch : stages[nextGeneration - 1]) {
        stage.push_back(*new line(branch.getEndpoint(), branch.getLength() * .75, branch.getDirection() + PI * .25));
        stage.push_back(*new line(branch.getEndpoint(), branch.getLength() * .75, branch.getDirection() - PI * .25));
    }
    stages.push_back(stage);
    nextGeneration++;
}
