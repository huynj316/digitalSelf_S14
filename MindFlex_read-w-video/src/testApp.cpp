#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	
	bSendSerialMessage = false;
	ofBackground(255);
	ofSetLogLevel(OF_LOG_VERBOSE);
	
	serial.listDevices();
	vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
	
	// this should be set to whatever com port your serial device is connected to.
	// (ie, COM4 on a pc, /dev/tty.... on linux, /dev/tty... on a mac)
	// arduino users check in arduino app....
	int baud = 9600;
    serial.setup(0, baud); //open the first device
	//serial.setup("COM4", baud); // windows example
    //serial.setup("/dev/tty.usbmodem411", baud); // mac osx example
	//serial.setup("/dev/ttyUSB0", baud); //linux example
	
	nTimesRead = 0;
	nBytesRead = 0;
	readTime = 0;
	memset(bytesReadString, 0, 4);
    str = "";
    fullPacket = "";

	//video
	ofSetVerticalSync(true);
	frameByframe = false;
	
	// Uncomment this to show movies with alpha channels
	// fingerMovie.setPixelFormat(OF_PIXELS_RGBA);
	
	fingerMovie.loadMovie("movies/clip.mp4");
	fingerMovie.play();
	TFN=fingerMovie.getTotalNumFrames();

}

//--------------------------------------------------------------
void testApp::update(){
	//video
	fingerMovie.update();
    
    
    do {
        str = ofxGetSerialString(serial,'\n'); //read until end of line
        if (str=="") continue;
       numbersAsStrings=ofSplitString(str, ",");
        
        //cout <<"" <<ans[2]<<endl;
        
        // cout << str;
        
        
        
        //fullPacket+=str;
    } while (str!="");
    while (str!="");
    //cout << fullPacket <<endl;
    
    //use fullPacket for below...
    //figure out how take this string and split it into an 11-cell array with the individual values inside of it
    
	for( int i = 0; i < numbersAsStrings.size(); i++){
		//separates number into channel
		if (i == 0){
			signal = ofToInt(numbersAsStrings[i]);
		} else if (i == 1){
			attention = ofToInt(numbersAsStrings[i]);
		} else if (i == 2){
			meditation = ofToInt(numbersAsStrings[i]);
		} else if (i == 3){
			delta = ofToInt(numbersAsStrings[i]);
		} else if (i == 4){
			theta = ofToInt(numbersAsStrings[i]);
		} else if (i == 5){
			lowAlpha = ofToInt(numbersAsStrings[i]);
		} else if (i == 6){
			highAlpha = ofToInt(numbersAsStrings[i]);
		} else if (i == 7){
			lowBeta = ofToInt(numbersAsStrings[i]);
		} else if (i == 8){
			highBeta = ofToInt(numbersAsStrings[i]);
		} else if (i == 9){
			lowGamma = ofToInt(numbersAsStrings[i]);
		} else if (i == 10){
			highGamma = ofToInt(numbersAsStrings[i]);
		}
		
		
	}
	cout<<"signal:"<<signal<<endl;
	cout<<"attention:"<<attention<<endl;
	cout<<"meditation:"<<meditation<<endl;
	cout<<"delta:"<<delta<<endl;
	cout<<"theta:"<<theta<<endl;
	cout<<"low alpha:"<<lowAlpha<<endl;
	cout<<"high alpha:"<<highAlpha<<endl;
	cout<<"low beta:"<<lowBeta<<endl;
	cout<<"high beta:"<<highBeta<<endl;
	cout<<"low gamma:"<<lowGamma<<endl;
	cout<<"high gamma:"<<highGamma<<endl;
	
    
    fullPacket = "";
}

    
    
    
    //cout << numbersAsStrings.size() << endl;
//    if (numbersAsStrings.size() != 11){
//        fullPacket = "";
//        return;
//      }
    
//    for( int i = 0; i < numbersAsStrings.size(); i++){
//        //cout << numbersAsStrings[i] << endl; // prints out each string input
//        //numbersVector.push_back(ofToInt(numbersAsStrings[i]));
//        //then (because these values will still be strings), convert each cell of the array an integer... and store in a new array of the same size
//        
//        //converts number to an int
//        //int convertedNumber = ofToInt(numbersAsStrings[i]);
//        
//        //only works to push data into the 10th slot in array
//		numbersVector.push_back(ofToInt(numbersAsStrings[i]));
//        
//        // then you can access the individual components of the new integer array for numerical analysis
//        signal = numbersVector[0];
//        attention = numbersVector[1];
//        meditation = numbersVector[2];
//        delta = numbersVector[3];
//        theta = numbersVector[4];
//        lowAlpha = numbersVector[5];
//        highAlpha = numbersVector[6];
//        lowBeta = numbersVector[7];
//        highBeta = numbersVector[8];
//        lowGamma = numbersVector[9];
//        highGamma = numbersVector[10];

//        signal=atoi(numbersAsStrings[0].c_str());
//        attention=atoi(numbersAsStrings[1].c_str());
//        meditation=atoi(numbersAsStrings[2].c_str());
//        delta=atoi(numbersAsStrings[3].c_str());
//        theta=atoi(numbersAsStrings[4].c_str());
//        lowAlpha=atoi(numbersAsStrings[5].c_str());
//        highAlpha=atoi(numbersAsStrings[6].c_str());
//        lowBeta=atoi(numbersAsStrings[7].c_str());
//        highBeta=atoi(numbersAsStrings[8].c_str());
//        lowGamma=atoi(numbersAsStrings[9].c_str());
//        highGamma=atoi(numbersAsStrings[10].c_str());

    
        
        
        //separates number into channel
        //        if (i == 0){
        //            signal = ofToInt(numbersAsStrings[i]);
        //        } else if (i == 1){
        //            attention = ofToInt(numbersAsStrings[i]);
        //        } else if (i == 2){
        //            meditation = ofToInt(numbersAsStrings[i]);
        //        } else if (i == 3){
        //            delta = ofToInt(numbersAsStrings[i]);
        //        } else if (i == 4){
        //            theta = ofToInt(numbersAsStrings[i]);
        //        } else if (i == 5){
        //            lowAlpha = ofToInt(numbersAsStrings[i]);
        //        } else if (i == 6){
        //            highAlpha = ofToInt(numbersAsStrings[i]);
        //        } else if (i == 7){
        //            lowBeta = ofToInt(numbersAsStrings[i]);
        //        } else if (i == 8){
        //            highBeta = ofToInt(numbersAsStrings[i]);
        //        } else if (i == 9){
        //            lowGamma = ofToInt(numbersAsStrings[i]);
        //        } else if (i == 10){
        //            highGamma = ofToInt(numbersAsStrings[i]);
        //        }
    
    //    do {
    //        str = ofxGetSerialString(serial,'\n'); //read until end of line
    //        if (str=="") continue;
    //        ans=ofSplitString(str, ",");
    //        cout <<"" <<ans[0]<<endl;
    //        cout <<"" <<ans[1]<<endl;
    //        cout <<"" <<ans[2]<<endl;
    //
    //       // cout << str;
    //
    //
    //
    //        //fullPacket+=str;
    //    } while (str!="");
    //    //cout << fullPacket;
    //    //use fullPacket for below...
    //    //figure out how take this string and split it into an 11-cell array with the individual values inside of it
    //    //then (because these values will still be strings), convert each cell of the array an integer... and store in a new array of the same size
    //    // then you can access the individual components of the new integer array for numerical analysis
    //
    //    fullPacket = "";
    //}
    


//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(signal/2,meditation/2,attention/2);
    ofFill();
    ofCircle(200,200,25);
   // cout << meditation<<endl;
   // cout << attention <<endl;
	
	//movie
	ofSetHexColor(0xFFFFFF);
	
	
    fingerMovie.draw(0,0);
    ofSetHexColor(0x000000);
    unsigned char * pixels = fingerMovie.getPixels();
    
    int nChannels = fingerMovie.getPixelsRef().getNumChannels();
	
	highBeta=ofMap(highBeta, 0, 150000, 0, 255, true);
	highAlpha=int(ofMap(highAlpha, 0, 80000, 0, 2434, true));
	
	ofSetColor(255,0,0,highBeta) ;
	fingerMovie.setFrame(highAlpha);
	
    ofFill();
	ofRect(0,0,ofGetWidth(),ofGetHeight());
    
    // let's move through the "RGB(A)" char array
    // using the red pixel to control the size of a circle.
//    for (int i = 4; i < 320; i+=8){
//        for (int j = 4; j < 240; j+=8){
//            unsigned char r = pixels[(j * 320 + i)*nChannels];
//            float val = 1 - ((float)r / 255.0f);
//            ofCircle(400 + i,20+j,10*val);
//        }
//    }
	
	
    //ofSetHexColor(0x000000);
//	ofDrawBitmapString("press f to change",20,320);
//    if(frameByframe) ofSetHexColor(0xCCCCCC);
//    ofDrawBitmapString("mouse speed position",20,340);
//    if(!frameByframe) ofSetHexColor(0xCCCCCC); else ofSetHexColor(0x000000);
//    ofDrawBitmapString("keys <- -> frame by frame " ,190,340);
//    ofSetHexColor(0x000000);
//	
//    ofDrawBitmapString("frame: " + ofToString(fingerMovie.getCurrentFrame()) + "/"+ofToString(fingerMovie.getTotalNumFrames()),20,380);
//    ofDrawBitmapString("duration: " + ofToString(fingerMovie.getPosition()*fingerMovie.getDuration(),2) + "/"+ofToString(fingerMovie.getDuration(),2),20,400);
//    ofDrawBitmapString("speed: " + ofToString(fingerMovie.getSpeed(),2),20,420);
//	
//    if(fingerMovie.getIsMovieDone()){
//        ofSetHexColor(0xFF0000);
//        ofDrawBitmapString("end of movie",20,440);
//    }
    
}
//--------------------------------------------------------------
string testApp::ofxGetSerialString(ofSerial &serial, char until) {
    static string str;
    stringstream ss;
    char ch;
    int ttl=1000;
    while ((ch=serial.readByte())>0 && ttl-->0 && ch!=until) {
        ss << ch;
    }
    
    str+=ss.str();
    if (ch==until) {
        string tmp=str;
        str="";
        return ofxTrimString(tmp);
    } else {
        return "";
    }
    
}
//--------------------------------------------------------------
string testApp::ofxTrimStringRight(string str) {
    size_t endpos = str.find_last_not_of(" \t\r\n");
    return (string::npos != endpos) ? str.substr( 0, endpos+1) : str;
}

// trim trailing spaces//--------------------------------------------------------------
string testApp::ofxTrimStringLeft(string str) {
    size_t startpos = str.find_first_not_of(" \t\r\n");
    return (string::npos != startpos) ? str.substr(startpos) : str;
}
//--------------------------------------------------------------
string testApp::ofxTrimString(string str) {
    return ofxTrimStringLeft(ofxTrimStringRight(str));;
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
	switch(key){
        case 'f':
            //frameByframe=!frameByframe;
		
//            fingerMovie.setPaused(frameByframe);
			
			break;
        case OF_KEY_LEFT:
            fingerMovie.previousFrame();
			break;
        case OF_KEY_RIGHT:
            fingerMovie.nextFrame();
			break;
        case '0':
            fingerMovie.firstFrame();
			break;
    }
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
	//if(!frameByframe){
//        int width = ofGetWidth();
//        float pct = (float)x / (float)width;
//        float speed = (2 * pct - 1) * 5.0f;
//        fingerMovie.setSpeed(speed);
//	}
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	//if(!frameByframe){
//        int width = ofGetWidth();
//        float pct = (float)x / (float)width;
//        fingerMovie.setPosition(pct);
//	}
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	if(!frameByframe){
        fingerMovie.setPaused(true);
	}
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	if(!frameByframe){
        fingerMovie.setPaused(false);
	}
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

