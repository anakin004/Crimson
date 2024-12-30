// texture shader

#shader vertex
#version 330 core

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec2 a_TexCoord;   


out vec3 v_Position;

uniform mat4 u_Transform;
uniform mat4 u_ViewProjection;

out vec2 v_TexCoord;

void main() {
    v_TexCoord = a_TexCoord; 
    gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0); 
}

#shader fragment
#version 330 core

in vec2 v_TexCoord;
out vec4 FragColor;

uniform float u_TilingFactor;
uniform vec4 u_Color;
uniform sampler2D u_Texture;

void main() {
    FragColor = texture(u_Texture, v_TexCoord * u_TilingFactor) * u_Color;
}
