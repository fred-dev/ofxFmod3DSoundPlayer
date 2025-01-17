#pragma once

#include "ofMain.h"
#include "ofxFmod3DSoundPlayer.hpp"

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
    
    ofxFmod3DSoundPlayer player;
    
    glm::vec3 lposition, lpositionScreen, lvelocity, lforward, lup;
    glm::vec3 sposition, spositionScreen;
    glm::vec3 svelocity, svelocityScreen;
    
    bool keyIsDown = false;
    bool mouseIsDown = false;
    float scale = 1/50.f;
		
};
