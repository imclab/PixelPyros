#version 120

varying vec2 texCoord;
uniform sampler2DRect baseTexture;
uniform float blackPoint;
uniform float gamma;
uniform float whitePoint;

void main() {
    vec2 uv = texCoord.xy;
    vec3 col = texture2DRect(baseTexture, uv).rgb;
    
    vec3 diff = vec3(whitePoint) - vec3(blackPoint);
    if( diff == vec3(0.0) ) {
        diff += vec3(0.00001);
    }
    
    float g = gamma;
    if( g == 0.0f ) {
        g += 0.00001;
    }
    
    vec3 adjusted = min(max(col - vec3(blackPoint), vec3(0.0)) / (diff), vec3(1.0));
    
    gl_FragColor.rgb = pow(adjusted, vec3(1.0 / gamma));
    gl_FragColor.a = 1.0;
}