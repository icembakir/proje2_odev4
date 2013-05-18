#version 120

uniform sampler2D fbo_texture;
uniform sampler1D color_coor;
varying vec2 f_texcoord;

void main(void) {
    vec3 enterColor = texture2D(fbo_texture, f_texcoord).xyz;
	vec3 finalColor;
	finalColor.r = texture1D(color_coor, enterColor.r).r;
	finalColor.g = texture1D(color_coor, enterColor.g).g;
	finalColor.b = texture1D(color_coor, enterColor.b).b;
    gl_FragColor = vec4(finalColor, 1.0);
}

