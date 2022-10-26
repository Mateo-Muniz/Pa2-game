#pragma once
#include<cmath>
#include "ofMain.h"
#include "Mode1.h"
#include "Mode2.h"
#include "Mode3.h"
#include "Mode4.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		int level = 1;
		bool activateFractal1 = true;
		bool activateFractal2 = false;
		bool activateFractal3 = false;
		bool activateFractal4 = false;
		Mode1 *mode1;
		Mode2 *mode2Center;
		Mode2 *mode2Left;
		Mode2 *mode2Right;
		Mode3 *mode3;
		Mode4 *mode4;
		vector<FractalMode*> fractals;

	private:
		char mode = '1';
};