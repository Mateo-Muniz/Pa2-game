#pragma once

#include"FractalMode.h"

class Mode4 : public FractalMode{
    public:
        virtual void draw();
        Mode4(float x, float y, int n);
        void drawMode4(float x, float y, int n);
        virtual void animation();       
};