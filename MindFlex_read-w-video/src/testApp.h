#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{
	
	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        string ofxGetSerialString(ofSerial &serial, char until);
		string ofxTrimStringRight(string str);
        string ofxTrimStringLeft(string str);
        string ofxTrimString(string str);
        //vector<string>ans;
        vector <string> numbersAsStrings;// vectpr of information split up
        vector <int> numbersVector; //vector of ints
    
		ofTrueTypeFont		font;

		bool		bSendSerialMessage;			// a flag for sending serial
		char		bytesRead[3];				// data from serial, we will be trying to read 3
		char		bytesReadString[4];			// a string needs a null terminator, so we need 3 + 1 bytes
		int			nBytesRead,TFN;					// how much did we read?
		int			nTimesRead;					// how many times did we read?
		float		readTime,signal,attention,meditation,delta,theta,lowAlpha,highAlpha,lowBeta,highBeta,lowGamma,highGamma;					// when did we last read?
		
		ofSerial	serial;
        string str;
        string fullPacket;
	
		//video
		ofVideoPlayer 		fingerMovie;
		bool                frameByframe;
};

