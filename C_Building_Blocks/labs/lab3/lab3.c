#include <stdio.h>

void strCpy(char *dest, char *src);
void strCat(char *dest, char *src);
void strRev(char *src);
void subString(char *dest, int start, int end, char *src);

int main(void){

	char str1[] = "Hello ";
	char str2[] = "World!!!";
	char buffer1[100];
	char buffer2[100];

		strCpy(buffer1, str1);
		printf("%s\n", buffer1);

		strCat(buffer1, str2);
		printf("%s\n", buffer1);

		strRev(str2);
		printf("%s\n", str2);

		subString(buffer2, 0, 5, buffer1);
		printf("%s\n", buffer2);

		subString(buffer2, 6, 12, buffer1);
		printf("%s\n", buffer2);


return 0;
}

void strCpy(char *dest, char *src){
	//printf("HITCPY");

	int count = 0;

	while(*(src+count) != '\0'){
	
		*(dest+count) = *(src+count);

	count++;
	}
	*(dest+count+1) = '\0';
}

void strCat(char *dest, char *src){
	//printf("HITCAT\n");

	int count = 0, point = 0;

	while(*(dest+count) != '\0'){
		count++;
	}

	while(*(src+point) != '\0'){
		*(dest+count+point) = *(src+point);
		point++;
	}

	*(dest+count+point+1) = '\0';
}

void strRev(char *src){
	//printf("HITREV\n");

	int count = 0, point = 0;
	char temp[10];

	strCpy(temp, src);

	while(*(src+count) != '\0'){
		count++;
	}

	while(count >= 0){
		*(src+point) = *(temp+count-1);
		count--;
		point++;
	}
	*(src+point+1) = '\0';
}

void subString(char *dest, int start, int end, char *src){
	//printf("HITSUB\n");	

	int count = 0;	
	
	// returns null 
	if(start > end){ *dest = '\0';
	// start init. to 0 
	}else if(start < 0){ start = 0;
	// end init. to 0
	}else if(end < 0){ end = 0;	
	// normal run time	
	}else{
	
		while(*(src+count) != '\0'){
			count++;
		}		
		
		if(start > count){
			*dest = '\0';
		}else{

			count = 0;		

			while(start < end){

				*(dest+count) = *(src+start);

			count++;
			start++;
			}
		*(dest+count+1) = '\0';
		}
	}


	

}
