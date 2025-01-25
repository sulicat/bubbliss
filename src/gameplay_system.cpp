#include "gameplay_system.hpp"
#include "bubble.hpp"
#include "scene.hpp"
#include <iostream>

void GameplaySystem::update() {
    Bubble &bubble = Scene::inst().get_bubble();
}