#include "Mode4.h"
#include "ofApp.h"

Mode4::Mode4(float x, float y, int n) : FractalMode(x, y, n){
}
    void Mode4::draw(){
        drawMode4( x, y, n);
        
    }

void Mode4::drawMode4(float x, float y, int n){
    if (n != 0)
    {
        ofDrawRectangle(x-50, y-37.5, 100, 75);
        ofDrawCircle(x, y, 37.5);
        ofDrawCircle(x, y, 25);
        ofDrawCircle(x, y, 12.5);
        ofDrawCircle(x, y, 6.25);
        ofDrawCircle(x, y, 3.125);
        ofDrawCircle(x, y, 1.5625);
        
        drawMode4(x + 100, y + 50, n-1);
        drawMode4(x - 100, y - 50, n-1);
        drawMode4(x + 100, y - 50, n-1);
        drawMode4(x - 100, y + 50, n-1);
    }
    if (getLevel() == 1) ofSetColor(204,201,98);
    if (getLevel() == 2) ofSetColor(100,60,201);
    if (getLevel() == 3) ofSetColor(150,255,86);
    if (getLevel() == 4) ofSetColor(238,130,238);
    if (getLevel() == 5) ofSetColor(255,0,0);
    if (getLevel() == 6) ofSetColor(0,255,0);
    if (getLevel() == 7) ofSetColor(0,0,255);
}
void Mode4::animation(){
     timer++;
    setLevel(count);
    if (timer >= limit && getLevel() <= 6 && changingDepth){
        setLevel(count++);
        limit += 90;
    } 
    if (getLevel() == 6){
        changingDepth = false;
    }
    if(timer >= limit && getLevel() >= 0 && !changingDepth){
        setLevel(count--);
        limit += 90;
    }
    if(getLevel() == 0){
        changingDepth = true;
    }
}