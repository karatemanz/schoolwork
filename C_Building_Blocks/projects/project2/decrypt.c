#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static char NEWLINE = '\n';

int isASCII(char);

int main(int argc, char *argv[]){

	FILE *fp = fopen(argv[1], "r");
	char buffer[5], curChar, preChar;
	int i = 0, length = 0, I = 0, file_size = 0;

	printf("\nFilename: %s\n", argv[1]);
	printf("-----------------------\n");

	fseek(fp, 0L, SEEK_END);
	file_size = ftell(fp);
	fseek(fp, 0L, SEEK_SET);

	while(I <= file_size){

		curChar = fgetc(fp);

		if(curChar == NEWLINE){
			length = i;
			for(i = 0; i < length; i++){
				printf("%c", buffer[i]);
			}
			printf("%c", curChar);
			i = 0;
		}else if(isASCII(curChar)){
			buffer[i] = curChar;
			i++;
		}else if(i >= 4){
			length = i;
			for(i = 0; i < length; i++){
				printf("%c", buffer[i]);
			}
			i = 0;
		}else{
			i = 0;
		}

		preChar = curChar;

	I++;	
	}	

return 0;	
}

int isASCII(char value){

	return ((int)value >= 32 && (int)value <= 126);

}

