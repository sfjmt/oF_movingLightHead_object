#include "example_MovingHeadObject.h"

//--------------------------------------------------------------
void example_MovingHeadObject::setup(){
    
    ofBackground(200);
    
    _cam = new ofEasyCam();
    _cam->setDistance(5000);
    _cam->setFarClip(50000);
    
    _movingHead1 = new MovingHeadObject();
    _movingHead1->setup();
    _movingHead1->set_name("sharpy 01");
    _movingHead1->rotateY(0);
    _movingHead1->debug(true);
    
    _movingHead2 = new MovingHeadObject();
    _movingHead2->setup();
    _movingHead2->set_name("sharpy 02");
    _movingHead2->rotateY(90);
    _movingHead2->debug(true);
    
    _movingHead3 = new MovingHeadObject();
    _movingHead3->setup();
    _movingHead3->set_name("sharpy 03");
    _movingHead3->rotateY(180);
    _movingHead3->debug(true);
    
    _movingHead4 = new MovingHeadObject();
    _movingHead4->setup();
    _movingHead4->set_name("sharpy 04");
    _movingHead4->rotateX(180);
    _movingHead4->debug(true);
    
    _movingHead5 = new MovingHeadObject();
    _movingHead5->setup();
    _movingHead5->set_name("sharpy 05");
    _movingHead5->rotateX(180);
    _movingHead5->debug(true);
    
    _movingHead6 = new MovingHeadObject();
    _movingHead6->setup();
    _movingHead6->set_name("sharpy 06");
    _movingHead6->rotateX(180);
    _movingHead6->debug(true);
    
    _movingHead7 = new MovingHeadObject();
    _movingHead7->setup();
    _movingHead7->set_name("sharpy 07");
    _movingHead7->rotateX(90);
    _movingHead7->debug(true);
    
    _movingHead8 = new MovingHeadObject();
    _movingHead8->setup();
    _movingHead8->set_name("sharpy 08");
    _movingHead8->rotateX(-90);
    _movingHead8->debug(true);
    
    _sphere0 = new ofSpherePrimitive();
    _sphere0->set(30, 10);
    
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
        
        _movingHead1->set_targetPosition(setPos);
        _movingHead2->set_targetPosition(setPos);
        _movingHead3->set_targetPosition(setPos);
        _movingHead4->set_targetPosition(setPos);
        _movingHead5->set_targetPosition(setPos);
        _movingHead6->set_targetPosition(setPos);
        _movingHead7->set_targetPosition(setPos);
        _movingHead8->set_targetPosition(setPos);
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
        
        _movingHead1->set_targetPosition(_positions[0]);
        _movingHead2->set_targetPosition(_positions[1]);
        _movingHead3->set_targetPosition(_positions[2]);
        _movingHead4->set_targetPosition(_positions[3]);
        _movingHead5->set_targetPosition(_positions[4]);
        _movingHead6->set_targetPosition(_positions[5]);
        _movingHead7->set_targetPosition(_positions[6]);
        _movingHead8->set_targetPosition(_positions[7]);
    }
}

//--------------------------------------------------------------
void example_MovingHeadObject::draw(){
    
    _cam->begin();
    
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
    ofDrawBitmapString("fps : "+ofToString(ofGetFrameRate()), ofPoint(10,20*1));
    ofDrawBitmapString("key press(0) : MODE 0", ofPoint(10,20*2));
    ofDrawBitmapString("key press(1) : MODE 1", ofPoint(10,20*3));
    
    ofDrawBitmapString("movingHead_1 pan angle  : " + ofToString(_movingHead1->getAnglePan()) , ofPoint(10,ofGetHeight()-20*16));
    ofDrawBitmapString("movingHead_1 tilt angle : " + ofToString(_movingHead1->getAngleTilt()), ofPoint(10,ofGetHeight()-20*15));
    ofDrawBitmapString("movingHead_2 pan angle  : " + ofToString(_movingHead2->getAnglePan()) , ofPoint(10,ofGetHeight()-20*14));
    ofDrawBitmapString("movingHead_2 tilt angle : " + ofToString(_movingHead2->getAngleTilt()), ofPoint(10,ofGetHeight()-20*13));
    ofDrawBitmapString("movingHead_3 pan angle  : " + ofToString(_movingHead3->getAnglePan()) , ofPoint(10,ofGetHeight()-20*12));
    ofDrawBitmapString("movingHead_3 tilt angle : " + ofToString(_movingHead3->getAngleTilt()), ofPoint(10,ofGetHeight()-20*11));
    ofDrawBitmapString("movingHead_4 pan angle  : " + ofToString(_movingHead4->getAnglePan()) , ofPoint(10,ofGetHeight()-20*10));
    ofDrawBitmapString("movingHead_4 tilt angle : " + ofToString(_movingHead4->getAngleTilt()), ofPoint(10,ofGetHeight()-20*9));
    ofDrawBitmapString("movingHead_5 pan angle  : " + ofToString(_movingHead5->getAnglePan()) , ofPoint(10,ofGetHeight()-20*8));
    ofDrawBitmapString("movingHead_5 tilt angle : " + ofToString(_movingHead5->getAngleTilt()), ofPoint(10,ofGetHeight()-20*7));
    ofDrawBitmapString("movingHead_6 pan angle  : " + ofToString(_movingHead6->getAnglePan()) , ofPoint(10,ofGetHeight()-20*6));
    ofDrawBitmapString("movingHead_6 tilt angle : " + ofToString(_movingHead6->getAngleTilt()), ofPoint(10,ofGetHeight()-20*5));
    ofDrawBitmapString("movingHead_7 pan angle  : " + ofToString(_movingHead6->getAnglePan()) , ofPoint(10,ofGetHeight()-20*4));
    ofDrawBitmapString("movingHead_7 tilt angle : " + ofToString(_movingHead6->getAngleTilt()), ofPoint(10,ofGetHeight()-20*3));
    ofDrawBitmapString("movingHead_8 pan angle  : " + ofToString(_movingHead6->getAnglePan()) , ofPoint(10,ofGetHeight()-20*2));
    ofDrawBitmapString("movingHead_8 tilt angle : " + ofToString(_movingHead6->getAngleTilt()), ofPoint(10,ofGetHeight()-20*1));
    
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

