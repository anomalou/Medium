#version 330 core

out vec4 fragColor;

in vec4 vertexColor;
in vec2 texCoord;
uniform sampler2D uTexture;

void main(){
    fragColor = texture(uTexture, texCoord);
}