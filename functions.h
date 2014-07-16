#ifndef _functions_h
#define _functions_h

#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/glfw.h>




/*
 * stuf stuf stuf stuf stuf stuf 
*/



extern GLuint		GLSL_Program;
extern GLuint		GLSL_vertex;
extern GLuint		GLSL_fragment;


void				Init(void);
void				Shut_Down(int return_code);
void				Main_Loop(void);
void				Draw(void);

char			*	ReadFile(const char *);
void				print_shader_info_log(GLuint);
void				print_program_info_log(GLuint);
void				ShaderSetup(void);

#endif
