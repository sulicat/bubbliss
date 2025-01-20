use bevy::{ecs::query, prelude::*, render::camera::ScalingMode, transform};

#[derive(Resource, Default)]
struct Globals {
    initial_viewport_height: f32,
}

pub fn setup(
    mut commands: Commands,
    mut meshes: ResMut<Assets<Mesh>>,
    mut materials: ResMut<Assets<StandardMaterial>>,
) {
    // add the global resource to resources
    let globals = Globals {
        initial_viewport_height: 100.0,
        ..Default::default()
    };

    // cube
    commands.spawn((
        Mesh3d(meshes.add(Sphere::new(1.0))),
        MeshMaterial3d(materials.add(Color::srgb_u8(124, 144, 255))),
        Transform::from_xyz(0.0, 0.5, 0.0),
    ));

    // light
    commands.spawn((
        PointLight {
            shadows_enabled: true,
            ..default()
        },
        Transform::from_xyz(4.0, 8.0, 4.0),
    ));

    // camera
    commands.spawn(Camera3dBundle {
        camera: Camera {
            clear_color: ClearColorConfig::Custom(Color::rgb(0.8, 0.4, 0.2)),
            ..default()
        },
        transform: Transform::from_xyz(0.0, 0.0, 10.0),
        ..default()
    });

    commands.insert_resource(globals);
}

pub fn test_cam(mut query: Query<(&mut Camera3d, &mut Transform)>) {
    for (mut cam, mut t) in &mut query {
        t.translation.y += 0.01;
    }
}
