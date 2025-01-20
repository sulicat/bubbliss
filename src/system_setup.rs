use bevy::{prelude::*, render::camera::ScalingMode};

pub fn setup(mut commands: Commands) {
    // camera
    commands.spawn((
        Camera2d,
        OrthographicProjection {
            scaling_mode: {
                ScalingMode::FixedVertical {
                    viewport_height: 100.0,
                }
            },
            ..OrthographicProjection::default_2d()
        },
    ));
}
