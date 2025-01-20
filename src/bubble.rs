use bevy::{ecs::component, prelude::*, render::camera::ScalingMode};

#[derive(Component)]
pub struct Bubble;

pub fn spawn_bubble(
    mut commands: Commands,
    mut meshes: ResMut<Assets<Mesh>>,
    mut materials: ResMut<Assets<ColorMaterial>>,
) {
    commands.spawn((
        Bubble,
        Mesh2d(meshes.add(Circle::new(5.0))),
        MeshMaterial2d(materials.add(Color::srgb(0.0, 0.0, 1.0))),
        Transform::from_xyz(0.0, 0.0, 0.0),
    ));
}
