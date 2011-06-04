// Based on:
// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 17-8: Characters along a curve 
// 
// Edited by fabiantheblind
// http://www.the-moron.net

#pragma once
#include "ofMain.h"
#include <sstream>
#include <string>
#include <SourceText.h>

class CrclTxtApp : public ofBaseApp{
	
	public:
		
		void setup();
		void update();
		void draw();
		
        //void drawCircle();
        void txtCircle(string txt);
        void txtCircleRun(int frmcnt,string txt, float r,int pt);
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);		
		
		ofTrueTypeFont  franklinBook;
		ofTrueTypeFont	verdana;
		ofTrueTypeFont  franklinBookLarge;
        ofTTFCharacter  curChar;


        ofImage myImage;
        bool saveAFrame;
        float radius;
        int pointsize;
        int snapCounter;
        string  message;
		float   counter;

       
};

