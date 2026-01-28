//////////////////////////////////////////////////////////////////////////////////
//
//      Program Name : programTwoServer.c
//      Description  : This shared object defines arithmetic functions for addition
//                     and subtraction that can be dynamically loaded and
//                     invoked at runtime by another program.
//      Author       : Aditya Vijay Mali
//      Date         : 28/01/2026
//
//////////////////////////////////////////////////////////////////////////////////

int Addition(int A, int B)
{
    int Ans = 0;
    Ans = A + B;

    return Ans;
}

int Substraction(int A, int B)
{
    int Ans = 0;
    Ans = A - B;

    return Ans;
}