#pragma once

#include "ofMain.h"
#include "MovingHeadObject.h"

class example_MovingHeadObject : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyReleased(int key);
    void mouseReleased(int x, int y, int button);
    
    ofEasyCam *_cam;
    MovingHeadObject *_movingHead1;
    MovingHeadObject *_movingHead2;
    MovingHeadObject *_movingHead3;
    MovingHeadObject *_movingHead4;
    MovingHeadObject *_movingHead5;
    MovingHeadObject *_movingHead6;
    MovingHeadObject *_movingHead7;
    MovingHeadObject *_movingHead8;
    
    ofSpherePrimitive *_sphere0;
    vector<ofSpherePrimitive> _spheres;
    
    int _posX, _posY, _posZ;
    vector<ofVec3f> _positions;
    
    int MODE;
};