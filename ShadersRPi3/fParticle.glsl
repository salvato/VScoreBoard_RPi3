#version 100


attribute vec2 TexCoords;
attribute vec4 ParticleColor;
varying vec4 color;

uniform sampler2D sprite;

void
main() {
    color = (texture(sprite, TexCoords) * ParticleColor);
}
