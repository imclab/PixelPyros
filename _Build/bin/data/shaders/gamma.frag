#version 120

varying vec2 texCoord;
uniform sampler2DRect baseTexture;
uniform float gamma;

void main() {
    vec2 uv = texCoord.xy;
    vec3 col = texture2DRect(baseTexture, uv).rgb;
    gl_FragColor.rgb = pow(col, vec3(1.0 / gamma));
    gl_FragColor.a = 1.0;
}