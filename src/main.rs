use bevy::{ecs::system, prelude::*};

mod bubble;
mod mouth;
mod system_setup;

fn main() {
    App::new()
        .add_plugins(DefaultPlugins.set(WindowPlugin {
            primary_window: Some(Window {
                // fill the entire browser window
                fit_canvas_to_parent: true,
                // don't hijack keyboard shortcuts like F5, F6, F12, Ctrl+R etc.
                prevent_default_event_handling: false,
                ..default()
            }),
            ..default()
        }))
        .add_systems(
            Startup,
            (
                system_setup::setup,
                bubble::spawn_bubble,
                mouth::spawn_mouth,
            ).chain(),
        )
        .add_systems(Update, system_setup::test_cam)
        .run();
}
