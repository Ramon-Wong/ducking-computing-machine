#include "functions.h"
#include "Matrix.h"



GLfloat		Proj_Matrix[16];
GLfloat		View_Matrix[16];

//			Camera Array [Pose][View][UpVx]
GLfloat		vCamera[3][3];



void Init(void){
	const int window_width = 800,
            window_height = 600;
 
	if (glfwInit() != GL_TRUE)
	Shut_Down(1);
	// 800 x 600, 16 bit color, no depth, alpha or stencil buffers, windowed
	if(glfwOpenWindow(window_width, window_height, 5, 6, 5, 0, 0, 0, GLFW_WINDOW) != GL_TRUE)
	Shut_Down(1);
	glfwSetWindowTitle("The GLFW Window");
	
	MLoadIdentity(Proj_Matrix);
	MLoadIdentity(View_Matrix);
	
	float aspect_ratio = ((float)window_height) / window_width;
	_MFrustum( Proj_Matrix, 0.5f, -0.5f, -0.5f * aspect_ratio, 0.5f * aspect_ratio, 1.0f, 100.0f);	

	printf("GL VENDOR:---  %s \n",		glGetString(GL_VENDOR));
	printf("GL RENDERER:-  %s \n",		glGetString(GL_RENDERER));
	printf("GL VERSION:--  %s \n",  	glGetString(GL_VERSION));
	printf("GL SHADING:--  %s \n",		glGetString(GL_SHADING_LANGUAGE_VERSION));
 
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);    
	glFrontFace(GL_CW);	
}
 

void Shut_Down(int return_code){
	glDeleteProgram( GLSL_Program);
	glDeleteShader( GLSL_vertex);
	glDeleteShader( GLSL_fragment);		
	
	glfwTerminate();
	exit(return_code);
}
