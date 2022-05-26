/*
This is a security authentication program that is menu-driven.
The user will be asked to enter  4 integer numbers and the program will then
encrypt the numbers and compare it to the correct authorised access code (4523).
This program will then decrypt the code that the user entered and display it.
This program will then terminate gracefully. 

This program was compiled using Visual Studio Code
 
Author: Sara Egan

Date: 03/03/21
*/

//include these in every program
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define SIZE 4

//global variable
int access_code[SIZE] = {4,5,2,3};

// Function signature or Function prototype
void option1 (int array[SIZE]);
int option2 (int *, int *, int array[SIZE]);
void option3 (int array[SIZE]);
void option4 (int *, int *);
int option5 ();


int main()
{
    char menu_option;
    int check_code[SIZE];
    int correct = 0;
    int incorrect = 0;

    // Display main menu and enter selection
    while (menu_option != '5')
    {
        printf("|--------------------------------------------------------------------------------------|\n");
        printf("|1. Enter any code                                                                     |\n");
        printf("|--------------------------------------------------------------------------------------|\n");
        printf("|2. Encrypt code entered and verify it is correct                                      |\n");
        printf("|--------------------------------------------------------------------------------------|\n");
        printf("|3. Decrypt code                                                                       |\n");
        printf("|--------------------------------------------------------------------------------------|\n");
        printf("|4. Display the number of times the encrypted code entered matches the authorised code |\n|    (i) Successfully (ii) Incorrectly                                                 |\n");
        printf("|--------------------------------------------------------------------------------------|\n");
        printf("|5. Exit Program                                                                       |\n");
        printf("|--------------------------------------------------------------------------------------|\n");
        printf("\n Please choose an option from the menu above. \n");
        
        // Read menu option from user
        scanf("%c", &menu_option);

        // This clears the input buffer
        while (getchar() != '\n');

        //Check option selected by the user
        switch(menu_option)
        {
            //menu option 1
            case '1':
            {
                option1(check_code);

                break;
            }//end case 1

            //menu option 2
            case '2':
            {
               option2(&correct, &incorrect, check_code);

               break;
            }//end case 2

            //menu option 3
            case '3':
            {
                option3(check_code);

                break;
            }//end case 3

            //menu option 4
            case '4':
            {
                option4(&correct , &incorrect);

                break;
            }//end case 4

            //menu option 5
            case '5':
            {
                option5();
                
                break;
            }//end case 5

            //default output for incorrect input. Menu validation
            default:
            {
                printf("\nInvalid entry. Try again\n\n");
            } // end default

        } // end switch

    } // end while

    return 0;

}//end main()

void option1(int check_code[])
{
    int i;
    int right = 0;
    int flag = 0;
    int wrong = 0;
    int char_check = 0;


    printf("Enter a valid 4-digit code\n");

    // Enter a code
    for(i = 0; i < SIZE; i++)
    {
        char_check = scanf("%d", &*(check_code + i));

        
        

        if (*(check_code+i) >= 10  || *(check_code+i) <= -1 || char_check != 1)
        {
            printf("You entered an invalid number, starting option 1 again\n\n");

            i = -1;
        }//end if
    } // end for

    printf("\n");

    printf("\nThe code you entered is:");


    printf("\n");

    for(i = 0; i < SIZE; i++)
    {
        printf("%d", *(check_code + i));
    } // end for


    printf("\n");

}//end function for option1()

int option2(int *correct, int *incorrect, int check_code[])
{
    int temp;
    int i;

    for(i = 0; i < SIZE; i++)
    {
       *(check_code + i) = *(check_code + i) + 1; 
    }//end for

    //store element 0 in temp
    temp = *(check_code);

    //swap 1st and 3rd num
    *(check_code) = *(check_code + 2);

    //swap 3rd with 1st
    *(check_code + 2) = temp;

    //set temp to 2nd number 
    temp = *(check_code + 1);

    //swap 2nd num with 4th num
    *(check_code + 1) = *(check_code + 3); 

    //swap 4th num with 2nd num
    *(check_code + 3) = temp;

    //for loop to check for 10
    for(i = 0; i < SIZE; i++)
    {
        if (*(check_code + i) == 10)
        {
            *(check_code + i) = 0;
        }//end if
    }//end for

    if ((check_code[0]) == access_code[0] && check_code[1] == access_code[1] && check_code[2] == access_code[2] && check_code[3] == access_code[3])
    {
        (*correct)++;

        printf("You entered the correct code \n\n");

    }//end if

    else
    {
        printf("You entered the wrong code \n\n");

        (*incorrect)++;
    }//end else
    
    printf("\n\n");

    printf("The code that you entered encrypted is: \n");

    for(i = 0; i < SIZE; i++)
    {
        printf("%d", *(check_code + i));
    } // end for

    printf("\n\n");

}//end function for option2()

void option3 (int check_code[])
{
    int temp;
    int i;

    for(i = 0; i < SIZE; i++)
    {
       *(check_code + i) = *(check_code + i) - 1; 
    }//end for

    //store element 0 in temp
    temp = *(check_code);

    //swap 1st num to equal 3rd num
    *(check_code) = *(check_code + 2);

    //swap 3rd with 1st
    *(check_code + 2) = temp;

    //set temp to 2nd number 
    temp = *(check_code + 1);

    //swap 2nd num with 4th num
    *(check_code + 1) = *(check_code + 3); 

    //swap 4th num with 2nd num
    *(check_code + 3) = temp;

    //for loop to check for -1
    for(i = 0; i < SIZE; i++)
    {
        if (*(check_code + i) == -1)
        {
            *(check_code + i) = 9;
        }//end if
    }//end for

    printf("\n\n");

    printf("The code that you entered decrypted is: \n");

    for(i = 0; i < SIZE; i++)
    {
        printf("%d", *(check_code + i));
    } // end for

    printf("\n\n");

}//end option3()

void option4 (int *correct, int *incorrect)
{
    printf("\nCorrect code entries: %d", *correct);
    printf("\nIncorrect code entries: %d\n", *incorrect);
}//end option4()

int option5 ()
{
    char confirm_end;

    printf("\nProgram ending. Are you sure (y/n)?\n");
    scanf("%c", &confirm_end);

    // This clears the input buffer
    while (getchar() != '\n');

    // check if user is sure they wish to end the program
    if(confirm_end == 'y' || confirm_end == 'Y' )
    {
        printf("\nGood bye\n");

    }//end if

    else if (confirm_end == 'n' || confirm_end == 'N' )
    {
        return main();

    }

}//end option5()