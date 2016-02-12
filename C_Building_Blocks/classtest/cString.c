#include <stdio.h>
#include <string.h>

int main(){


char str[100];
char strc[100];
char strr[100];
char sub[100];
int x = 0, y = 0;
int start = -1, end = -1;
int dif;

printf("Please enter string: \n");
scanf("%[^\n]s", str);

printf("Please enter start and indices: \n");
scanf("%i %i", &start, &end);

while(str[x] != '\0'){
	strc[x] = str[x];
	x++;
}

y = x;
x = 0;

while(str[x] != '\0'){

	strr[x] = str[y-1];
	x++;
	y--;

}

if(start < 0 &&  end < 0){

x = start;
y = 0;

while(x != end+1){

	sub[y] = str[x];

y++;
x++;
}

}

printf("Length: %i. \n", x);
printf("Copy String: %s. \n", strc);
printf("Reversed: %s. \n", strr);
printf("Substring: %s. \n", sub);

return 0;
}
