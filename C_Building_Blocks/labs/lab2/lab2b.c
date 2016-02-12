#include <stdio.h>

int main(){

int x, y = 0;
float item_price, tax, total, subtotal;

printf("How many items would you like to enter?\n");
scanf("%i", &x);

while(x != y){

printf("Enter price of item %i:  $", y+1);
scanf("%f", &item_price);

subtotal = subtotal + item_price;

y++;
}



printf("\nYou've entered %i items.\n", y);
printf("The sub-total is: $ %3.2f\n", subtotal);

tax = 0.07 * subtotal;

printf("The tax is:       $ %3.2f\n", tax);
printf("The total is:     $ %3.2f\n", subtotal + tax);


return 0;
}
