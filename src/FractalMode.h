#pragma once
class FractalMode{
    protected:
        float x, y;
        int n, timer = 0, limit = 90, count = 0;
        bool activate = false;
        bool changingDepth = true;

    public:
        virtual void draw() = 0;
        bool getActivate(){return activate;}
        void setActivate(bool activate){this-> activate = activate;};
        FractalMode(float x, float y, int n){
        this -> x = x;
        this -> y = y;
        this -> n = n;
        }
        int getLevel(){return n;};
        void setLevel(int n){this-> n = n;};
        virtual void animation() = 0;
        void setTimer(int t){this-> timer = t;};
        void setLimit(int l){this-> limit = l;};
        int getCOunt(){return count;};
        void setCount(int c){this-> count = c;};
};