#pragma once

#include "bubble.hpp"

class Scene{
public:
    ~Scene(){};
    static Scene& inst();
    void init();

    Bubble& get_bubble(){ return bubble; }

private:
    Scene(){};
    static Scene* _scene;
    Bubble bubble;
};