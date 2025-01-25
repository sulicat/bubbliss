#include "scene.hpp"

#include <iostream>

Scene* Scene::_scene = nullptr;

Scene& Scene::inst(){
    if (_scene == nullptr) {
        _scene = new Scene();
        _scene->init();
    }
    return *_scene;
}

void Scene::init(){
}