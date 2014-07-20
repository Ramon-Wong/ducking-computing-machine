#include "functions.h"

 



 
int main(int arg, char * argv[]){
	
	Init();
	ShaderSetup();
	
	Main_Loop();
	Shut_Down(0);
  
	return 0;
}
 
