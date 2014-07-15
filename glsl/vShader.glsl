#version 130

vec4 a				= gl_Vertex;
vec4 b				= a;

in vec3				vPosition;
uniform float 		uForm;


void main () {
	float PI			= 3.14159265358979323846264;
	float angle			= 27.0;
	float rad_angle		= uForm * PI/180.0;
								
	b.x			= a.x*cos(rad_angle) - a.y*sin(rad_angle);
	b.y			= a.y*cos(rad_angle) + a.x*sin(rad_angle);
	
	gl_Position = gl_ModelViewProjectionMatrix * b;
}
