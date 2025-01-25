#pragma once

#include "game_state.hpp"
#include "scene.hpp"

class RenderingSystem {
public:
    static void render();

private:
    static void render_base_scene();
    static void render_moving_scene();

};