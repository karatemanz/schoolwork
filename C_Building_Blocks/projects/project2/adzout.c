// address: 0x80485a4
int main(int argc, char *argv[], char *envp[]) {
    __size32 eax; 	         // r24
    __size32 eax_1;          // r24{419}
    int eax_2; 		         // r24{7}
    int edx; 		         // r26
    int esp; 		         // r28
    char local0[][][]; 		 // m[esp - 24]

    
    __size32 local14; 		 // eax_1{419}
    
    int local1;              // m[esp - 36]
    unsigned char local2;    // m[esp - 11]
    unsigned int local11;    // m[esp - 32]
    int local13;             // m[esp - 28]
    int local3; 		     // m[esp - 64]
    int local4; 		     // m[esp - 76]
    int local5; 		     // m[esp - 40]

    eax_2 = *20;

    printf("Please enter your Pitt ID: ");

    __isoc99_scanf();
    strcmp(&0x317a6461, &local0);

    if (eax == 0) {

        time(0);
        srand();
        printf("Your session number is ");

        local11 = 0;

        while ((int)local11 <= 9) {
            rand();
            *(__size32*)(esp + local11 * 4 - 76) = (eax & 0x7) + 1;
            edx = *(esp + local11 * 4 - 76);
            printf("%i", edx);

            local11++;
        }
        // local 11 = 9;

        putchar();

        local13 = 0;
        local11 = 0;

        while ((int)local11 <= 9) {

            eax = *(esp + local11 * 4 - 76);

            if ((eax & 0x1) == 0) {

                eax = *(esp + local11 * 4 - 76);
                local13 += eax;

            }
            local11++;
        }

        printf("Please enter a number: ");
        __isoc99_scanf();

        printf("local13 = %i", local13);
        if (local1 == local13) { //input same as 13

            local13 = 0;
            local11 = 0;

            while ((int)local11 <= 9) {
                eax = *(esp + local11 * 4 - 76);
                local13 += eax;
                local11++;
            }

            printf("Please enter a number: ");
            __isoc99_scanf();

            printf("local13 = %i", local13);
            if (local1 == local13) { //input is same as 13

                eax = (local2);
                eax = (int) (unsigned char) eax - 48;
                eax = *(esp + eax * 4 - 76);
                local13 = eax << local3;

                printf("Please enter a number: ");
                __isoc99_scanf();

                printf("local13 = %i", local13);
                if (local1 == local13) {

                    printf("Please enter a number: ");
                    __isoc99_scanf();

                    printf("local4 < %i", local4);
                    if (local1 < local4) {

                        printf("Please enter a number: ");
                        __isoc99_scanf();

                        printf("local5 < %i", local5);
                        if (local1 < local5) {

                            puts("Congratulations!!! You just crack the code.");

                        } else {
                            puts("*****************\n***   BOOM!   ***\n*** Game Over ***\n*****************");
                        }
                    } else {
                        puts("*****************\n***   BOOM!   ***\n*** Game Over ***\n*****************");
                    }
                } else {
                    puts("*****************\n***   BOOM!   ***\n*** Game Over ***\n*****************");
                }
            } else {
                puts("*****************\n***   BOOM!   ***\n*** Game Over ***\n*****************");
            }
        } else {
            puts("*****************\n***   BOOM!   ***\n*** Game Over ***\n*****************");
        }
    } else {
        puts("Warning!!!");
        printf("This program is generated specifically for %s\n", &0x317a6461);
        printf("If your pitt ID is %s, download the program %s_project2.\n", &local0, &local0);
    }
    eax_1 = 0;
    edx = eax_2 ^ *20;
    local14 = eax_1;
    if (edx != 0) {
        __stack_chk_fail();
        local14 = eax;
    }
    eax_1 = local14;
    return eax_1;
}
