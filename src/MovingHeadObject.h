#ifndef __MovingHeadObject__
#define __MovingHeadObject__

#include "ofMain.h"

class MovingHeadObject : public ofBaseApp
{
public:
    
    MovingHeadObject();
    ~MovingHeadObject();
    
    ofVec3f getPosition();
    int getAnglePan();
    int getAngleTilt();
    
    void setRotateX(int val);
    void setRotateY(int val);
    void setRotateZ(int val);
    
    void setPanMin(int angle);
    void setPanMax(int angle);
    void setTiltMin(int angle);
    void setTiltMax(int angle);
    
    void setName(string name);
    
    void setObjectColor(int r, int g, int b, int a);
    void setObjectColor(int gray, int a);
    void setMonitorColor(int r, int g, int b, int a);
    void setLineColor(int r, int g, int b, int a);
    void setLineColor(int gray, int a);
    void setLineWidth(int lineWidth);
    
    void setRotatePan(int angle);
    void setRotateTilt(int angle);
    void setPosition(ofVec3f v);
    void setChasePosition(ofVec3f v);
    
    void setup(float objectScale=1.0);
    
    void debug(bool flag=true);
    
    void update();
    void draw();
    void draw(ofVec3f v);
    void draw(float x, float y, float z);
    
private:
    
    void draw_pan_status();
    void draw_tilt_status();
    void draw_base_status();
    void draw_monitor_status();
    
    float panAngle(ofVec3f v);
    float tiltAngle(ofVec3f v1, ofVec3f v2, ofVec3f v3);
    
    ofBoxPrimitive      *_obj_pan;
    ofCylinderPrimitive *_obj_tilt;
    ofBoxPrimitive      *_obj_monitor;
    ofBoxPrimitive      *_obj_base;
    
    string MY_NAME;
    bool DEBUG;
    int PAN_MIN,PAN_MAX;
    int TILT_MIN,TILT_MAX;
    
    int _angle_pan;
    int _angle_tilt;
    int _preArea;
    float _posX_sphere,_posY_sphere,_posZ_sphere;
    float _translateX,_translateY,_translateZ;
    float _rotateX,_rotateY,_rotateZ;
    int _lineWidth;
    float _objectScale;
    
    ofVec3f _getRawPosition;
    ofVec3f _targetPosition;
    ofVec3f _AXIS_X_NORMAL;
    ofVec3f _AXIS_Y_NORMAL;
    ofVec3f _AXIS_Z_NORMAL;
    
    ofColor _objectColor,_monitorColor,_lineColor;
};

#endif