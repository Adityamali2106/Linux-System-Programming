//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Program Name : Program08_4
//  Description  : A simple C program to add two integers and display the result.
//                 to demenstrote use of Makrfile
//  Author       : Aditya Vijay Mali
//  Date         : 04/02/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

int main(void)
{
    int iNo1 = 0, iNo2 = 0, iRet = 0;

    printf("Enter first integer: ");
    scanf("%d", &iNo1);
    printf("Enter second integer: ");
    scanf("%d", &iNo2); 
    
    iRet = Addition(iNo1,iNo2);

    printf("Addition is : %d\n", iRet);

    return 0;
}

