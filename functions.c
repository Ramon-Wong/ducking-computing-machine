#include "functions.h"
#include "Matrix.h"

/*
 * stuf stuf stuf stuf stuf stuf 
*/




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
GLuint		uMatLoc[2];

GLfloat		aCamera[3][3];


void Draw(void){
	// reset view matrix
	sTok += 0.05f;
		
	//_LookAtM(View_Matrix, Pose, View, upVx);

	aCamera[0][0] = 0.0; aCamera[0][1] = 0.0; aCamera[0][2] =-6.0;	// Pose
	aCamera[1][0] = 0.0; aCamera[1][1] = 0.0; aCamera[1][2] = 0.0;	// View
	aCamera[2][0] = 0.0; aCamera[2][1] = 1.0; aCamera[2][2] = 0.0;	// UpVx
		
	_LookAtM( View_Matrix, aCamera[0], aCamera[1], aCamera[2]);
	
		
	glUseProgram( GLSL_Program);
		
	GLuint	uFormLocation		= glGetUniformLocation( GLSL_Program, "uForm");
	glUniform1f( uFormLocation, sTok);

	uMatLoc[0]					= glGetUniformLocation( GLSL_Program, "uView_Matrix");
	uMatLoc[1]					= glGetUniformLocation( GLSL_Program, "uProj_Matrix");
		
	glUniformMatrix4fv( uMatLoc[0], 1, GL_FALSE, View_Matrix);
	glUniformMatrix4fv( uMatLoc[1], 1, GL_FALSE, Proj_Matrix);
		
	
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, indices);
    glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays
}

