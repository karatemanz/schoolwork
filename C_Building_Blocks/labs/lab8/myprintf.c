#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int readInteger();
void printString(char *str);
void printInteger(int n);
void printFloat(float f);
void printChar(char character);

int readInteger()
{
	// TO DO
	char buffer[10];
	int int_char = 0, i = 0, cur_char = 0, aug = 1;

	read(STDIN_FILENO, buffer, 10);
	//printf("before %s\n", buffer);

		if(*(buffer + 0) == 45){

			aug = -1;
			i++;

		}

	while(*(buffer + i) != '\n'){

		// converts char to int
		cur_char = buffer[i] - '0';
		// move digit over 1
		int_char = int_char * 10;
		// adds total to digit location
		int_char = int_char + cur_char;
		i++;
		//printf("%d\n",int_char);

	}

		int_char = int_char * aug;

	//printf("This is it %d\n", int_char);
	return int_char;
}

void printString(char *str)
{
	// TO DO
	int str_size = 0;

	while(*(str+str_size) != '\0'){

		str_size++;
	}

	write(STDOUT_FILENO, str, str_size+1);

}

void printChar(char character){

	char buff[1];

	buff[0] = character;

	write(STDOUT_FILENO, buff, 1);

}

void myprintf(char *format, ...){

	va_list ap;
	int count, int_type;
	char *str_type, uno;
	float flt_type;

	va_start(ap, format);

	while(*(format + count) != '\0' ){

		if(*(format + count) == '%'){
			count++;

			if(*(format + count) == 's'){

				str_type = va_arg(ap, char *);
				printString(str_type);

			}else if(*(format + count) == 'i'){

				int_type = va_arg(ap, int);
				printInteger(int_type);

			}else if(*(format + count) == 'f'){

				flt_type = (float) va_arg(ap, double);
				printFloat(flt_type);

			}
		}else{

			printChar(*(format+count));

		}	

	count++;	
	}

	va_end(ap);

}

void printInteger(int n)
{
	// TO DO
	char buff[20];
	int digits = 0, num = 0, i = 0, remain = 0, sign = 1;

	if(n == 0){
		buff[0] = '0';
		write(STDOUT_FILENO, buff, 1);
		return;
	}else if(n < 0){
		sign = -1;
		n = n * -1;
	}

	//printf("\ndigits %i\n", digits);
	//printf("number %i\n", n);
	num = n;

	// checks digits of number
	while(num != 0){
		digits++;
		num /= 10;
	}


	for (i = 0; i < digits; i++)
    {
    		// the remainder is of the least signif. digit
			remain = n % 10;
			n = n / 10;
	       	buff[digits - (i + 1)] = remain + '0';

    }
    buff[digits] = '\n';

    // with negative signs displays the negative sign
    // then prints out the desired value
    if(sign == -1){
    	write(STDOUT_FILENO, "-", 1);
    }

	write(STDOUT_FILENO, buff, digits);



}

void printFloat(float f)
{
	// TO DO
	char buff[20];
	float belowdot, bd;
	int digits = 0, prec = 0, predot = 0, i = 0, p = 0, sign = 1;

	if(f < 0){
		sign = -1;
		f = f * -1;
	}

	predot = (int)f;
	p = predot;

	belowdot = f - (float)predot;
	bd = belowdot;

	while(p != 0){
		digits++;
		p /= 10;
	}

	while(i < 6){

		bd = bd - (float)prec;
		bd *= 10;
		prec = (int)bd;

		if(prec == '0'){
			buff[i] = '0';
		}else{
			buff[i] = prec + '0';
		}	
		digits++;

	i++;
	}

	// reuse integer printing and handle negative numbers
	// also adds the dot and newline following.
	if(sign == -1){
		write(STDOUT_FILENO, "-", 1);
	}
	printInteger(predot);
	write(STDOUT_FILENO, ".", 1);
    write(STDOUT_FILENO, buff, digits);


}

int main(void)
{

	int x = 5, y = 9;
	char divMsg[] = " divided by ";

	myprintf("%i %s %i is equal to %f.\n", x, divMsg, y, ((float) x)/y);

	return 0;
}
