#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    fractals.push_back(new Mode1(ofGetWidth() / 2, ofGetHeight() / 2, 4));
    fractals.push_back(new Mode2(200, 10, ofGetWidth() / 2, ofGetHeight() - 50, 30));
    fractals.push_back(new Mode2(75, 10, ofGetWidth() * 0.25, ofGetHeight() - 50, 30));
    fractals.push_back(new Mode2(75, 10, ofGetWidth() * 0.75, ofGetHeight() - 50, 30));
    fractals.push_back(new Mode3(ofGetWidth() / 3, 10, ofGetHeight() / 2, 10));
    fractals.push_back(new Mode4(ofGetWidth() / 2, ofGetHeight() / 2, 4));
}

//--------------------------------------------------------------
void ofApp::update()
{
    /* The update method is called muliple times per second
    It's in charge of updating variables and the logic of our app */
    ofSetBackgroundColor(0, 0, 0);
    if(fractals[0]->getActivate()){
        for(int i = 0; i < fractals.size(); i++){
            fractals[i]->animation();
        }    
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    /* The update method is called muliple times per second
    It's in charge of drawing all figures and text on screen */
    ofNoFill();
    if (activateFractal1){
        fractals[0]->draw();
    }
    if(activateFractal2){
        fractals[1]->draw();
        fractals[2]->draw();
        fractals[3]->draw();
        
    }
    if(activateFractal3){
        fractals[4]->draw();

    }
    if(activateFractal4){
        fractals[5]->draw();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    // This method is called automatically when any key is pressed
    switch (key)
    {
    case '1':
        activateFractal1 = !activateFractal1;
        break;
    case '2':
        activateFractal2 = !activateFractal2;
        break;
    case '3':
        activateFractal3 = !activateFractal3;
        break;
    case '4':
        activateFractal4 = !activateFractal4;
        break;
    case '-':
        if (fractals[0]->getLevel() > 1) fractals[0]->setLevel(fractals[0]->getLevel() - level);
        if (fractals[1]->getLevel() > 1) {
            fractals[1]->setLevel(fractals[1]->getLevel() - level);
            fractals[2]->setLevel(fractals[2]->getLevel() - level);
            fractals[3]->setLevel(fractals[3]->getLevel() - level);
        }
        if(fractals[4]->getLevel() > 1) fractals[4]->setLevel(fractals[4]->getLevel() - level);
        if (fractals[5]->getLevel() > 1) fractals[5]->setLevel(fractals[5]->getLevel() - level);
        break;
    case '=':
        if (fractals[0]->getLevel() < 7) fractals[0]->setLevel(fractals[0]->getLevel() + level);
        if (fractals[1]->getLevel() < 11){
            fractals[1]->setLevel(fractals[1]->getLevel() + level);
            fractals[2]->setLevel(fractals[2]->getLevel() + level);
            fractals[3]->setLevel(fractals[3]->getLevel() + level);
        }
        if(fractals[4]->getLevel() < 11) fractals[4]->setLevel(fractals[4]->getLevel() + level);
        if (fractals[5]->getLevel() < 7) fractals[5]->setLevel(fractals[5]->getLevel() + level);
        break;
    case ' ':
        fractals[0]->setActivate(true);
        break;
    case 'c':
        fractals[0]->setTimer(0);
        fractals[0]->setLimit(90);
        fractals[0]->setActivate(false);
        for(int i =0; i < fractals.size(); i++){
            fractals[i]->setCount(0);
        }
        break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}