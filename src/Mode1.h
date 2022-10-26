#pragma once

#include"FractalMode.h"

class Mode1 : public FractalMode{
    public:
        virtual void draw();
        Mode1(float x, float y, int n);
        void drawMode1(float x, float y, int n);
        virtual void animation();
};