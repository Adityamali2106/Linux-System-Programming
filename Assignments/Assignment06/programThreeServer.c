//////////////////////////////////////////////////////////////////////////////////
//
//      Program Name : programThreeServer.c
//      Description  : This shared object defines arithmetic functions for addition
//                     subtraction, Multiplication and Division that can be dynamically loaded and
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

int Multiplication(int A, int B)
{
    int Ans = 0;
    Ans = A * B;

    return Ans;
}

int Division(int A, int B)
{
    int Ans = 0;
    Ans = A / B;

    return Ans;
}