#pragma once

class Bubble {
public:
    Bubble() {};
    ~Bubble() {};

    const int resolution = 500;

    float x = 0;
    float y = 0;
    float size = 0;
    float volatility = 0.01;
    float volatility_amp = 5;

private:
};