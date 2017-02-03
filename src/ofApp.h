#pragma once

#include "ofMain.h"
#include "line.h"

class ofApp : public ofBaseApp{

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
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    //helpers
private:
    bool isSavingPDF;
    vector<vector<line>> stages;
    int sceneHeight;
    int sceneWidth;
    int generationZero;
    int nextGeneration;
    int currentDrawnGeneration;
    
    void setupInitialStage();
    
    void generate(int simulationLength);
    void generateNext();
		
};
