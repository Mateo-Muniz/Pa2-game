#pragma once
#include "FractalMode.h"

class Mode3 : public FractalMode{
    private:
        int size;

    public:
        virtual void draw();
        Mode3(float x, float y, int size, int n);
		void drawMode3(float x, float y, int size, int n);
        virtual void animation();
};