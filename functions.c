#include "functions.h"


/*
 * stuf stuf stuf stuf stuf stuf 
*/


void Init(void){
	const int window_width = 800,
            window_height = 600;
 
	if (glfwInit() != GL_TRUE)
	Shut_Down(1);
	// 800 x 600, 16 bit color, no depth, alpha or stencil buffers, windowed
	if(glfwOpenWindow(window_width, window_height, 5, 6, 5, 0, 0, 0, GLFW_WINDOW) != GL_TRUE)
	Shut_Down(1);
	glfwSetWindowTitle("The GLFW Window");

	// set the projection matrix to a normal frustum with a max depth of 50
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float aspect_ratio = ((float)window_height) / window_width;
	glFrustum(.5, -.5, -.5 * aspect_ratio, .5 * aspect_ratio, 1, 50);
	glMatrixMode(GL_MODELVIEW);
	
	
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
 

void Main_Loop(void){

	// this just loops as long as the program runs
	while(1){

    if (glfwGetKey(GLFW_KEY_ESC) == GLFW_PRESS)
	break;
	
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// draw the figure

		Draw();
		// swap back and front buffers
		glfwSwapBuffers();
	}
}
 

GLfloat vertices[]	= {  1.0f, 1.0f, -5.0f,  -1.0f, 1.0f, -5.0f,  
						-1.0f,-1.0f, -5.0f,   1.0f,-1.0f, -5.0f};	 
GLubyte indices[]	= { 0, 1, 2,   2, 3, 0}; 
GLfloat		sTok = 0.0f;


void Draw(void){
	// reset view matrix
	sTok += 0.05f;
	
	glLoadIdentity();
	
		glUseProgram( GLSL_Program);
		
		GLuint	uFormLocation		= glGetUniformLocation( GLSL_Program, "uForm");
		glUniform1f( uFormLocation, sTok);

	
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, indices);
    glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays
}

