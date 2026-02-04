//////////////////////////////////////////////////////////////////////////
//
//  Function Name   : MyPow
//  Discription     : It is used calculate the power
//  Input           : Number, Power to calculate
//  Output          : Result
//  Author          : Aditya Vijay Mali
//  Date            : 03/02/2026
//
//////////////////////////////////////////////////////////////////////////

int MyPow(int No, int pow)
{
    int iCnt = 0;
    int iResult = 1;

    if (No == 0)
    {
        return 0;
    }

    for (iCnt = 1; iCnt <= pow; iCnt++)
    {
        iResult = No * iResult;
    }
    return iResult;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Mysqrt
//  Discription     : It is used calculate the squir root of given number
//  Input           : Number
//  Output          : Squirroot of given number
//  Author          : Aditya Vijay Mali
//  Date            : 03/02/2026
//
//////////////////////////////////////////////////////////////////////////

double my_sqrt(double No)
{
    double dNo1 = No;
    double dNo2 = 1;
    double dNo3 = 0.000001;

    while ((dNo1 - dNo2) > dNo3)
    {
        dNo1 = (dNo1 + dNo2) / 2;
        dNo2 = No / dNo1;
    }
    return dNo1;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function Name   : MyAbs
//  Discription     : It is used calculate absolute value of given number
//  Input           : Number
//  Output          : Returns the absolute (positive) value of a number.
//  Author          : Aditya Vijay Mali
//  Date            : 03/02/2026
//
//////////////////////////////////////////////////////////////////////////

int MyAbs(int No)
{
    if (No < 0)
    {
        No = -No;
    }

    return No;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function Name   : MyMin
//  Discription     : It is used calculate Minimum value from given two numbers
//  Input           : Integer,Integer
//  Output          : Returns the Minimum value.
//  Author          : Aditya Vijay Mali
//  Date            : 03/02/2026
//
//////////////////////////////////////////////////////////////////////////

int MyMin(int No1, int No2)
{
    if (No1 < No2)
    {
        return No1;
    }
    else
    {
        return No2;
    }
}

//////////////////////////////////////////////////////////////////////////
//
//  Function Name   : MyMax
//  Discription     : It is used calculate Maximum value from given two numbers
//  Input           : Integer,Integer
//  Output          : Returns the Maximum value.
//  Author          : Aditya Vijay Mali
//  Date            : 03/02/2026
//
//////////////////////////////////////////////////////////////////////////

int MyMax(int No1, int No2)
{
    if (No1 > No2)
    {
        return No1;
    }
    else
    {
        return No2;
    }
}

//////////////////////////////////////////////////////////////////////////
//
//  Function Name   : MyFactorial
//  Discription     : It is used calculate Factorial value of given number.
//  Input           : Integer
//  Output          : Returns the Factorial value.
//  Author          : Aditya Vijay Mali
//  Date            : 03/02/2026
//
//////////////////////////////////////////////////////////////////////////

int MyFactorial(int No)
{
    if (No == 1)
    {
        return 1;
    }

    return No * MyFactorial(No - 1);
}

//////////////////////////////////////////////////////////////////////////
//
//  Function Name   : MyGCD
//  Discription     : It is used calculate Greatest Common Divisor value of given two numbers
//  Input           : Integer,Integer
//  Output          : Returns the Greatest Common Divisor value.
//  Author          : Aditya Vijay Mali
//  Date            : 03/02/2026
//
//////////////////////////////////////////////////////////////////////////

int MyGCD(int No1, int No2)
{
    int i = 0, iAns = 1;

    for (i = 1; i <= No1 && i <= No2; i++)
    {
        if ((No1 % i) == 0 && (No2 % i) == 0)
        {
            iAns = i;
        }
    }

    return iAns;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function Name   : MyLCM
//  Discription     : It is used calculate Least Common Multiple value of given two numbers
//  Input           : Integer,Integer
//  Output          : Returns the Least Common Multiple value.
//  Author          : Aditya Vijay Mali
//  Date            : 03/02/2026
//
//////////////////////////////////////////////////////////////////////////

int MyLCM(int No1, int No2)
{
    int Ans = (No1 * No2) / MyGCD(No1, No2);

    return Ans;
}
