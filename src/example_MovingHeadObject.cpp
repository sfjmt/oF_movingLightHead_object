#include "example_MovingHeadObject.h"

//--------------------------------------------------------------
void example_MovingHeadObject::setup(){
    
    ofBackground(170);
    
    _cam = new ofEasyCam();
    _cam->setDistance(5000);
    _cam->setFarClip(50000);
    
    _movingHead1 = new MovingHeadObject();
    _movingHead1->setup();
    _movingHead1->setName("sharpy 01");
    _movingHead1->setRotateY(0);
    _movingHead1->debug(true);
    
    _movingHead2 = new MovingHeadObject();
    _movingHead2->setup();
    _movingHead2->setName("sharpy 02");
    _movingHead2->setRotateY(90);
    _movingHead2->debug(true);
    
    _movingHead3 = new MovingHeadObject();
    _movingHead3->setup();
    _movingHead3->setName("sharpy 03");
    _movingHead3->setRotateY(180);
    _movingHead3->debug(true);
    
    _movingHead4 = new MovingHeadObject();
    _movingHead4->setup();
    _movingHead4->setName("sharpy 04");
    _movingHead4->setRotateX(180);
    _movingHead4->debug(true);
    
    _movingHead5 = new MovingHeadObject();
    _movingHead5->setup();
    _movingHead5->setName("sharpy 05");
    _movingHead5->setRotateX(180);
    _movingHead5->debug(true);
    
    _movingHead6 = new MovingHeadObject();
    _movingHead6->setup();
    _movingHead6->setName("sharpy 06");
    _movingHead6->setRotateX(180);
    _movingHead6->debug(true);
    
    _movingHead7 = new MovingHeadObject();
    _movingHead7->setup();
    _movingHead7->setName("sharpy 07");
    _movingHead7->setRotateX(90);
    _movingHead7->debug(true);
    
    _movingHead8 = new MovingHeadObject();
    _movingHead8->setup();
    _movingHead8->setName("sharpy 08");
    _movingHead8->setRotateX(-90);
    _movingHead8->debug(true);
    
    _sphere0 = new ofSpherePrimitive();
    _sphere0->set(30, 10);
    
    _plane = new ofPlanePrimitive();
    _plane->set(3000, 3000);
    _plane->rotate(90, 1, 0, 0);
    _plane->setPosition(0, -1500, 0);
    
    for(int i = 0; i < 8; i++)
    {
        ofSpherePrimitive sphere;
        _spheres.push_back(sphere);
        _spheres[i].set(10, 10);
        _positions.push_back(ofVec3f());
    }
    
}

//--------------------------------------------------------------
void example_MovingHeadObject::update(){
    
    if(MODE==0)
    {
        _posX = sin(ofGetElapsedTimef()*0.5)*1000;
        _posY = sin(ofGetElapsedTimef()*0.1)*100;
        _posZ = cos(ofGetElapsedTimef()*0.5)*1000;
        
        ofVec3f setPos = ofVec3f(_posX,_posY,_posZ);
        
        _sphere0->setPosition(setPos);
        
        _movingHead1->setChasePosition(setPos);
        _movingHead2->setChasePosition(setPos);
        _movingHead3->setChasePosition(setPos);
        _movingHead4->setChasePosition(setPos);
        _movingHead5->setChasePosition(setPos);
        _movingHead6->setChasePosition(setPos);
        _movingHead7->setChasePosition(setPos);
        _movingHead8->setChasePosition(setPos);
    }
    else if(MODE==1)
    {
        for(int i = 0; i < 8; i++)
        {
            int x = sin(ofGetElapsedTimef()*(0.5+0.1*i))*(100*i+100);
            int y = sin(ofGetElapsedTimef()*1.0)*(500);
            int z = cos(ofGetElapsedTimef()*0.5)*(100*i+100);
            _positions[i] = ofVec3f(x,y,z);
            
            _spheres[i].setPosition(_positions[i]);
        }
        
        _movingHead1->setChasePosition(_positions[0]);
        _movingHead2->setChasePosition(_positions[1]);
        _movingHead3->setChasePosition(_positions[2]);
        _movingHead4->setChasePosition(_positions[3]);
        _movingHead5->setChasePosition(_positions[4]);
        _movingHead6->setChasePosition(_positions[5]);
        _movingHead7->setChasePosition(_positions[6]);
        _movingHead8->setChasePosition(_positions[7]);
    }
    
    _camPos.x = cos(ofGetElapsedTimef()*0.1)*5000;
    _camPos.z = sin(ofGetElapsedTimef()*0.1)*5000;
    _cam->setPosition(_camPos);
    _cam->lookAt(ofVec3f());
}

//--------------------------------------------------------------
void example_MovingHeadObject::draw(){
    
    _cam->begin();
    
    _plane->draw();
    
    _movingHead1->draw(0    , -1500, 0);
    _movingHead2->draw(-1000, -1500, 0);
    _movingHead3->draw(1000 , -1500, 0);
    
    _movingHead4->draw(-1000, 1500, -1000);
    _movingHead5->draw(0    , 1500, 0);
    _movingHead6->draw(1000 , 1500, 1000);
    
    _movingHead7->draw(0, 0, -2000);
    _movingHead8->draw(0, 0, 2000);
    
    if(MODE==0)
    {
        ofSetColor(255, 0, 0);
        _sphere0->draw();
    }
    else if(MODE==1)
    {
        ofSetColor(255, 0, 0);
        
        for(int i = 0; i < 8; i++)
        {
            _spheres[i].draw();
        }
    }
    
    _cam->end();
    
    ofSetColor(100);
    ofDrawBitmapStringHighlight("fps : "+ofToString(ofGetFrameRate()), ofPoint(10,20*1));
    ofDrawBitmapStringHighlight("key press(0) : MODE 0", ofPoint(10,20*2));
    ofDrawBitmapStringHighlight("key press(1) : MODE 1", ofPoint(10,20*3));
    
    ofDrawBitmapStringHighlight("movingHead_1 pan angle  : " + ofToString(_movingHead1->getAnglePan()) , ofPoint(10,ofGetHeight()-20*16));
    ofDrawBitmapStringHighlight("movingHead_1 tilt angle : " + ofToString(_movingHead1->getAngleTilt()), ofPoint(10,ofGetHeight()-20*15));
    ofDrawBitmapStringHighlight("movingHead_2 pan angle  : " + ofToString(_movingHead2->getAnglePan()) , ofPoint(10,ofGetHeight()-20*14));
    ofDrawBitmapStringHighlight("movingHead_2 tilt angle : " + ofToString(_movingHead2->getAngleTilt()), ofPoint(10,ofGetHeight()-20*13));
    ofDrawBitmapStringHighlight("movingHead_3 pan angle  : " + ofToString(_movingHead3->getAnglePan()) , ofPoint(10,ofGetHeight()-20*12));
    ofDrawBitmapStringHighlight("movingHead_3 tilt angle : " + ofToString(_movingHead3->getAngleTilt()), ofPoint(10,ofGetHeight()-20*11));
    ofDrawBitmapStringHighlight("movingHead_4 pan angle  : " + ofToString(_movingHead4->getAnglePan()) , ofPoint(10,ofGetHeight()-20*10));
    ofDrawBitmapStringHighlight("movingHead_4 tilt angle : " + ofToString(_movingHead4->getAngleTilt()), ofPoint(10,ofGetHeight()-20*9));
    ofDrawBitmapStringHighlight("movingHead_5 pan angle  : " + ofToString(_movingHead5->getAnglePan()) , ofPoint(10,ofGetHeight()-20*8));
    ofDrawBitmapStringHighlight("movingHead_5 tilt angle : " + ofToString(_movingHead5->getAngleTilt()), ofPoint(10,ofGetHeight()-20*7));
    ofDrawBitmapStringHighlight("movingHead_6 pan angle  : " + ofToString(_movingHead6->getAnglePan()) , ofPoint(10,ofGetHeight()-20*6));
    ofDrawBitmapStringHighlight("movingHead_6 tilt angle : " + ofToString(_movingHead6->getAngleTilt()), ofPoint(10,ofGetHeight()-20*5));
    ofDrawBitmapStringHighlight("movingHead_7 pan angle  : " + ofToString(_movingHead6->getAnglePan()) , ofPoint(10,ofGetHeight()-20*4));
    ofDrawBitmapStringHighlight("movingHead_7 tilt angle : " + ofToString(_movingHead6->getAngleTilt()), ofPoint(10,ofGetHeight()-20*3));
    ofDrawBitmapStringHighlight("movingHead_8 pan angle  : " + ofToString(_movingHead6->getAnglePan()) , ofPoint(10,ofGetHeight()-20*2));
    ofDrawBitmapStringHighlight("movingHead_8 tilt angle : " + ofToString(_movingHead6->getAngleTilt()), ofPoint(10,ofGetHeight()-20*1));
    
}

//--------------------------------------------------------------
void example_MovingHeadObject::keyReleased(int key){
    
    if(key=='1')
    {
        MODE = 1;
    }
    if(key=='0')
    {
        MODE = 0;
    }
}

//--------------------------------------------------------------
void example_MovingHeadObject::mouseReleased(int x, int y, int button){
    
}

