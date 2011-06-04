// Based on:
// Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example 17-8: Characters along a curve 
// 
// Edited by fabiantheblind
// http://www.the-moron.net
#include "circleText.h"
// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


//--------------------------------------------------------------
void CrclTxtApp::setup(){	 
	saveAFrame = FALSE;

	
    // The radius of a circle
    radius = ofGetWidth()/3;
    pointsize  = 8;
    
    // this loads the font
	franklinBook.loadFont("OCRAEXT.ttf", pointsize,true,true,true);
    
    // this is the text
    message = "this is fabiantheblind Keeper of the Sacred Chao Adept of Canhoto son of H.Z. and Dr.D member of the moron net who travells the hello worlds and does stuff that involves things.\nThe quick, brown fox jumps over a lazy dog. DJs flock by when MTV ax quiz prog. Junk MTV quiz graced by fox whelps. Bawds jog, flick quartz, vex nymphs. Waltz, bad nymph, for quick jigs vex! Fox nymphs grab quick-jived waltz. Brick quiz whangs jumpy veldt fox. Bright vixens jump; dozy fowl quack. Quick wafting zephyrs vex bold Jim. Quick zephyrs blow, vexing daft Jim.\n Sex-charged fop blew my junk TV quiz.\n How quickly daft jumping zebras vex. Two driven jocks help fax my big quiz. Quick, Baz, get my woven flax jodhpurs! \"Now fax quiz Jack! \" my brave ghost pled. Five quacking zephyrs jolt my wax bed. Flummoxed by job, kvetching W. zaps Iraq. Cozy sphinx waves quart jug of bad milk. A very bad quack might jinx zippy fowls. Few quips galvanized the mock jury box. Quick brown dogs jump over the lazy fox. The jay, pig, fox, zebra, and my wolves quack! Blowzy red vixens fight for a quick jump. Joaquin Phoenix was gazed by MTV for luck.\n A wizard’s job is to vex chumps quickly in fog. Watch \"Jeopardy! \", Alex Trebek's fun TV quiz game. Woven silk pyjamas exchanged for blue quartz. Brawny gods just";
    
    for(int j = 0; j < 5; j++){
        message = message + message;
    }
    // count the time
	counter = 0;
    // set the bg
    ofBackground(255,255,255);
	// set the framerate
    ofSetFrameRate(25);
    // dont redraw the background if not called
    ofSetBackgroundAuto(FALSE);

    
}

//--------------------------------------------------------------
// only count up
void CrclTxtApp::update(){
    counter++;
}


//--------------------------------------------------------------
void CrclTxtApp::draw(){

    // the first 3 frames or so dont show the text
    // so we wait 10 frames
    if(counter > 10){
        
    //translate it to the center
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    // if you want to twist it in runtime
    // ofRotateZ(counter);
    
    // use this function if you only want to write the circle without animation
    //txtCircle(message);
    txtCircleRun(counter - 11,message,radius,pointsize);
    }//close pre counter
    
    // if you want to write sequences
    if(saveAFrame ==TRUE){
    myImage.grabScreen(0,0,ofGetWidth(),ofGetHeight());
    
    myImage.saveImage("Screenrecord-"+ofToString(snapCounter)+".png");
    
    snapCounter++;
    }
    

	
}

// tihs is the animated circle
// depends on counter
void CrclTxtApp::txtCircleRun(int frmcnt,string txt, float r,int pt){

    // get the global values to local
    //float r = radius;// ofGetWidth() / 4;
    //int pt  = pointsize; //15;
    static float rad = r;
    
    static float arclength = 0;
    char input[txt.length()];
    // For every box
    int i = frmcnt%txt.length();
    
   // for (int i = 0; i < txt.length(); i ++ ) {
        
        
        // The character and its width
        // later on we use this character again for checking for newline characters
        stringstream ss;
        string s;
        char  currentChar;
        
        
        currentChar = message[i];
        // push it to a stream
        ss << currentChar;
        // and then into a string again
        ss >> s;
        
        // Instead of a constant width, we check the width of each character.
        float w = franklinBook.stringWidth(s);
        
        // Each box is centered so we move half the width
        arclength += w/2;
        
        
        // Angle in radians is the arclength divided by the radius
        // Starting on the left side of the circle by adding PI
        float theta = PI + arclength / rad;
        
        // push the matrix
        ofPushMatrix();
        
        // Polar to Cartesian conversion allows us to find the point along the curve. 
        // this translate the singe character onto his position on the circle
        ofTranslate(0+(rad*cos(theta)), 0+( rad*sin(theta))); 
        
        // calc the rotation of the single character. this is in radians
        float rot = (theta + (PI/2));
        
        // turn radians to degrees
        float degrees = rot * (180/PI);
        
        // now rotate
        ofRotateZ(degrees); 
        
        // Display the "character" // watch out its a string
        ofSetColor(0,0,0);
        
        // set the textheight
        franklinBook.setLineHeight(pt);
        
        // draw the singe "character" // watch out its astring
        franklinBook.drawString(s, 0,0);
        
        
        
        ofPopMatrix();
        
        // Move halfway again
        arclength += w/2;
        
        float u = 2*PI*rad;
        
        // this checks for breakline or if the circle is full
        
        if((arclength > u - w)||(currentChar == '\n')){
            
            // reduce the radius by the textheight *1.5
            rad = rad - (pt*1.5);
            
            // set the arc back to
            arclength = 0;
            
            // check if the circle is to small
            if(rad < pt*2){
                rad = pt;
            //    break;
                
            } // close if(r < pt*2)
        }// close  if((arclength > u - w)||(currentChar == '\n'))
        
        
   // }
    


}


// tihs is for drawing the circle without animation
void CrclTxtApp::txtCircle(string txt){
    // get the global values to local
    float r = radius;// ofGetWidth() / 4;
    int pt  = pointsize; //15;
    
    float arclength = 0;
    char input[txt.length()];
    // For every box
    for (int i = 0; i < txt.length(); i ++ ) {
        
        
        // The character and its width
        // later on we use this character again for checking for newline characters
        stringstream ss;
        string s;
        char  currentChar;
        
        
        currentChar = message[i];
        // push it to a stream
        ss << currentChar;
        // and then into a string again
        ss >> s;
        
        // Instead of a constant width, we check the width of each character.
        float w = franklinBook.stringWidth(s);
        
        // Each box is centered so we move half the width
        arclength += w/2;
        
        
        // Angle in radians is the arclength divided by the radius
        // Starting on the left side of the circle by adding PI
        float theta = PI + arclength / r;
        
        // push the matrix
        ofPushMatrix();
        
        // Polar to Cartesian conversion allows us to find the point along the curve. 
        // this translate the singe character onto his position on the circle
        ofTranslate(0+(r*cos(theta)), 0+( r*sin(theta))); 
        
        // calc the rotation of the single character. this is in radians
        float rot = (theta + (PI/2));
        
        // turn radians to degrees
        float degrees = rot * (180/PI);
        
        // now rotate
        ofRotateZ(degrees); 
        
        // Display the "character" // watch out its a string
        ofSetColor(0,0,0);

        // set the textheight
        franklinBook.setLineHeight(pt);
        
        // draw the singe "character" // watch out its astring
        franklinBook.drawString(s, 0,0);



        ofPopMatrix();
        
        // Move halfway again
        arclength += w/2;
        
        float u = 2*PI*r;
        
        // this checks for breakline or if the circle is full
        
        if((arclength > u - w)||(currentChar == '\n')){
            
            // reduce the radius by the textheight *1.5
            r = r - (pt*1.5);
            
            // set the arc back to
            arclength = 0;
            
            // check if the circle is to small
            if(r < pt*2){
                r = pt;
                break;
                
            } // close if(r < pt*2)
        }// close  if((arclength > u - w)||(currentChar == '\n'))
        
        
    }
    
}


//--------------------------------------------------------------
void CrclTxtApp::keyPressed  (int key){ 
	
}

//--------------------------------------------------------------
void CrclTxtApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void CrclTxtApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void CrclTxtApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void CrclTxtApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void CrclTxtApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void CrclTxtApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void CrclTxtApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void CrclTxtApp::dragEvent(ofDragInfo dragInfo){ 

}
