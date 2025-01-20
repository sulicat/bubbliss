use bevy::{
    ecs::component,
    prelude::*,
    render::{camera::ScalingMode, render_resource::encase::vector::FromVectorParts},
};

#[derive(Component)]
pub struct Mouth;

pub fn spawn_mouth(
    mut commands: Commands,
    mut meshes: ResMut<Assets<Mesh>>,
    mut materials: ResMut<Assets<ColorMaterial>>,
) {
    commands.spawn((
        Mouth,
        Mesh2d(meshes.add(Rectangle::new(20.0, 20.0))),
        MeshMaterial2d(materials.add(Color::srgb(1.0, 0.0, 1.0))),
        Transform::from_xyz(0.0, 10.0, 0.0),
    ));
}
