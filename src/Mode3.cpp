#include "Mode3.h"
#include "ofMain.h"

Mode3::Mode3(float x, float y, int size, int n) : FractalMode(x, y, n){
    this -> size = size;
}

void Mode3::draw(){
    drawMode3(x, y, size, n);
}

void Mode3::drawMode3(float x, float y, int size, int n){
    if (n == 0)
    {
        return;
    }

    ofPoint a(x, y);
    ofPoint b(x + size, y);
    ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));

    ofDrawTriangle(a, b, c);

    drawMode3(x, y, size / 2, n - 1);
    drawMode3((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, n - 1);
    drawMode3(x + size / 4, y + ((sqrt(3) * size) / 4), size / 2, n - 1);
 
    if (getLevel() == 1) ofSetColor(204,201,98);
    if (getLevel() == 2) ofSetColor(100,60,201);
    if (getLevel() == 3) ofSetColor(150,255,86);
    if (getLevel() == 4) ofSetColor(238,130,238);
    if (getLevel() == 5) ofSetColor(255,0,0);
    if (getLevel() == 6) ofSetColor(0,255,0);
    if (getLevel() == 7) ofSetColor(0,0,255);
    if (getLevel() == 8) ofSetColor(255,255,0);
    if (getLevel() == 9) ofSetColor(255,0,255);
    if (getLevel() == 10) ofSetColor(0,255,255);
}


void Mode3::animation(){
    timer++;
    setLevel(count);
    if (timer >= limit && getLevel() <= 8 && changingDepth){
        setLevel(count++);
        limit += 90;
    } 
    if (getLevel() == 8){
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