#include "Mode1.h"
#include "ofMain.h"
Mode1::Mode1(float x, float y, int n) : FractalMode(x, y, n){
}
void Mode1::draw(){
    drawMode1( x, y, n);
}

void Mode1::drawMode1(float x, float y, int n){
    if (n != 0)
    {
        ofDrawCone( x, y, 100, 100);
        drawMode1(x + 100, y, n - 1);
        drawMode1(x - 100, y, n - 1);
        drawMode1(x, y + 100, n - 1);
        drawMode1(x, y - 100, n - 1);
    }
    if (getLevel() == 1) ofSetColor(204,201,98);
    if (getLevel() == 2) ofSetColor(100,60,201);
    if (getLevel() == 3) ofSetColor(150,255,86);
    if (getLevel() == 4) ofSetColor(238,130,238);
    if (getLevel() == 5) ofSetColor(255,0,0);
    if (getLevel() == 6) ofSetColor(0,255,0);
    if (getLevel() == 7) ofSetColor(0,0,255);
}

void Mode1::animation(){
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