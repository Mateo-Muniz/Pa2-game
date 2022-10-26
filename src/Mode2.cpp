#include "Mode2.h"
#include "ofMain.h"

Mode2::Mode2(int length, int n, float x, float y, int d) : FractalMode(x, y, n){
    this -> length = length;
    this -> d = d;
}

void Mode2::draw(){
    drawMode2(length, n, x, y, d);
}

void Mode2::drawMode2(int length, int n, float x, float y, int d){
    if (n != 0)
    {
        int middleX = x;
        int middleY = y - length;
        int leftBranchX = x - length * cos(PI / 180 * d);
        int leftBranchY = middleY - length * sin(PI / 180 * d);
        int rightBranchX = x + length * cos(PI / 180 * d);
        int rightBranchY = middleY - length * sin(PI / 180 * d);

        ofDrawLine(x, y, x, y - length);
        ofDrawLine(x, y - length, x, y - length*2);
        ofDrawLine(x, y - length, rightBranchX, rightBranchY);
        ofDrawLine(x, y - length, leftBranchX, leftBranchY);

        drawMode2(length / 2, n - 1, rightBranchX, rightBranchY, 30);
        drawMode2(length / 2, n - 1, middleX, middleY, 30);
        drawMode2(length / 2, n - 1, leftBranchX, leftBranchY, 30); 

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

    
}
void Mode2::animation(){
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