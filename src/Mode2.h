#pragma once
#include "FractalMode.h"

class Mode2 : public FractalMode{
    private:
        int length, d;

    public:
        virtual void draw();
        Mode2(int length, int n, float x, float y, int d);
        void drawMode2(int length,int n, float x, float y, int d);
        virtual void animation();
};