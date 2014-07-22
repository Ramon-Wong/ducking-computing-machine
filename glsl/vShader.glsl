#version 400


in vec3				  vPose;

vec3 c				= vPose;
vec3 d				= c;


uniform float 		uForm;

uniform mat4		uProj_Matrix;
uniform mat4		uView_Matrix;


void main () {
	float PI			= 3.14159265358979323846264;
	float angle			= 27.0;
	float rad_angle		= uForm * PI/180.0;

											
	d.x = c.x*cos(rad_angle) - c.y*sin(rad_angle);
	d.y = c.y*cos(rad_angle) + c.x*sin(rad_angle);

	gl_Position			= uView_Matrix * uProj_Matrix * vec4(d, 1.0);
}
