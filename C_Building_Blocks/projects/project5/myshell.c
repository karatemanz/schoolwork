#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(void){

	while(1){

		char *args[50], *path, *temp;
		char buffer[50];
		char delims[] = {" \n\0"};
		int i;

		printf("adz13 shell> ");
		fgets(buffer, 100, stdin);

			args[0] = strtok(buffer, delims);

			for(i = 1; i < 50; i++){

				args[i] = strtok(NULL, delims);
				
				if(args[i] == NULL){
					break;
				}

			}	

			//args[1] = strtok(NULL, " \n");
			//printf("arg[0] = %s\n", args[0]);
			//printf("arg[1] = %s\n", args[1]);


		if(strcmp(args[0], "cd") == 0){

			//temp = args[i-1];
			//temp[strlen(temp) - 1] = 0;

			path = args[i-1];

			if(chdir(path) == -1){
				perror("adz13 shell: ");
			}

		}else if(strcmp(args[0], "exit") == 0){

			exit(0);

		}else{

			if(fork() == 0){

				if(execvp(args[0], args) == -1){
					perror("adz13 shell: ");
					exit(0);
				}


			}else{
				int status;
				wait(&status);
			}
		}
	}
}
