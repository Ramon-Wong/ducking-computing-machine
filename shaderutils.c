#include "functions.h"

/*
 * stuf stuf stuf stuf stuf stuf 
*/

char * ReadFile(const char * path){
	FILE *	tFile;
	char *	buffer;
	int		lSize;
	
	tFile = fopen( path, "rt");
	if(tFile){
		
		fseek(tFile , 0 , SEEK_END);
		lSize = ftell (tFile);
		rewind (tFile);		
		
		buffer = (char*) malloc (sizeof(char)*(lSize +1));
		fread( buffer, 1, lSize, tFile);
		buffer[lSize] = '\0';

		fclose(tFile);		
		
	}else{
		printf("\n\nError at opening file: %s\n", path);
	}

	return buffer;
}


void	print_shader_info_log(GLuint shader_index){
	int max_length = 2048;
	int actual_length = 0;
	char log[2048];
	
	glGetShaderInfoLog (shader_index, max_length, &actual_length, log);
	printf ("shader info log for GL index %u:\n%s\n", shader_index, log);
}


void print_program_info_log(GLuint programme) {
	int max_length = 2048;
	int actual_length = 0;
	char log[2048];
	
	glGetProgramInfoLog (programme, max_length, &actual_length, log);
	printf ("program info log for GL index %u:\n%s", programme, log);
}

