
#include <stdio.h>
#include <stdlib.h>
void printFileAsCArray(FILE* file, const char* name);
void help(int argc, char** argv) {
	printf("Program usage is: ./fileToCByteArray file.ext > file.h\n");
	exit(01);
}
int main(int argc, char** argv) {
	
	//./fileToCByteArray file.ext > file.h

	if(argc < 2) {
		help(argc,argv);
	}
	char* path = argv[1]; 
	FILE* input = fopen(path,"rb");
	printFileAsCArray(input,"easyrpg_logo");

}

void printFileAsCArray(FILE* file, const char* name){
	 char c;
	 int cols = 12;
	 printf("const uint8_t %s[] = {",name);
	 for(int count = 0 ;fscanf(file,"%c",&c)!=EOF; count++){
	 	if(count % cols == 0) {
	 		printf("\n\t");
	 	}
	 	printf(" 0x%02X,",c);
	 }
	 printf("0x00 };\n");
}