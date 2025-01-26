#include "rendering_system.hpp"
#include <iostream>
#include <math.h>

#include "PerlinNoise.hpp"
#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#define TO_RAD ((2 * M_PI) / 360.0)

const siv::PerlinNoise::seed_type seed = 123456u;
const siv::PerlinNoise            perlin{seed};

void RenderingSystem::init() {
}

void RenderingSystem::render() {
    GlobalState &state = GlobalState::inst();
    Scene       &scene = Scene::inst();
    Bubble      &bubble = scene.get_bubble();
    float        win_w = state.window_width;
    float        win_h = state.window_height;

    ClearBackground(Color{0, 0, 0, 0});
    BeginDrawing();

    switch (state.game_state) {
    case GameState::BASE:
        render_base_scene();
        break;
    case GameState::MOVING:
        render_moving_scene();
        break;
    default:
        break;
    }

    if (GuiButton(Rectangle{24, 24, 120, 30}, "#Show Message")) {
        std::cout << "Message\n";
    }

    EndDrawing();
}

void RenderingSystem::render_base_scene() {
    GlobalState &state = GlobalState::inst();
    float        win_w = state.window_width;
    float        win_h = state.window_height;

    render_bubble(win_w / 2, win_h / 2, win_h * 0.5);
}

void RenderingSystem::render_moving_scene() {
}

void RenderingSystem::render_bubble(float x, float y, float r) {
    Scene       &scene = Scene::inst();
    Bubble      &bubble = scene.get_bubble();
    GlobalState &state = GlobalState::inst();

    Vector2 center = Vector2{x, y};
    float   angle_step = 360.0 / bubble.resolution;

    static float noise_i = 0;
    noise_i += 0.1;

    for (int i = 0; i < bubble.resolution; i++) {
        float a1 = i * angle_step;
        float a2 = (i + 1) * angle_step;
        float a1_rad = TO_RAD * a1;
        float a2_rad = TO_RAD * a2;

        float p1_x = r * sin(a1_rad) + center.x;
        float p1_y = r * cos(a1_rad) + center.y;
        float p2_x = r * sin(a2_rad) + center.x;
        float p2_y = r * cos(a2_rad) + center.y;


        Vector2 p1 = Vector2{p1_x, p1_y};
        Vector2 p2 = Vector2{p2_x, p2_y};

        DrawTriangle(center, p1, p2, Color{255, 0, 0, 255});
    }
}
