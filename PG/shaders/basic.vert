#version 410 core

layout(location=0) in vec3 vPosition;
layout(location=1) in vec3 vNormal;
layout(location=2) in vec2 vTexCoords;

out vec3 fPosition;
out vec3 fNormal;
out vec2 fTexCoords;
out vec3 lightPosEye;
out vec4 fragPosEye;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 lPosEye;

void main() 
{
	
	lightPosEye = vec3(view * vec4(lPosEye,1.0f));
	fPosition = vPosition;
	fNormal = vNormal;
	fTexCoords = vTexCoords;
	fragPosEye= view * model * vec4(vPosition, 1.0f);
	gl_Position = projection * view * model * vec4(vPosition, 1.0f);
}
