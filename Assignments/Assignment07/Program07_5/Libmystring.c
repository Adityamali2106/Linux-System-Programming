#include <stdio.h>

//////////////////////////////////////////////////////////////////////////
//
//  Function Name   : MyStrlen
//  Discription     : It is used count length of the string
//  Input           : Charactor Array base address string
//  Output          : length of the string
//  Author          : Aditya Vijay Mali
//  Date            : 02/02/2026
//
//////////////////////////////////////////////////////////////////////////

int Mystrlen(const char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
    }

    return i;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function Name   : MyStrcpy
//  Discription     : It is used to copy first string into secound string
//  Input           : Charactor Array base address string 1,Charactor Array base address string 2
//  Output          : Cpoed string base addess
//  Author          : Aditya Vijay Mali
//  Date            : 02/02/2026
//
//////////////////////////////////////////////////////////////////////////

char *MyStrcpy(const char *str1, char *str2)
{
    int iCnt = 0;

    for (iCnt = 0; str1[iCnt] != '\0'; iCnt++)
    {
        str2[iCnt] = str1[iCnt];
    }
    str2[iCnt] = '\0';

    return str2;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function Name   : MyStrncpy
//  Discription     : It is used to copy first string into secound string only N caharactors
//  Input           : Charactor Array base address string 1,Charactor Array base address string 2
//                    N to copy the string 2 charactor
//  Output          : Cpoed string base addess
//  Author          : Aditya Vijay Mali
//  Date            : 02/02/2026
//
//////////////////////////////////////////////////////////////////////////

char *MyStrncpy(char *str1, char *str2, int N)
{
    int iCnt = 0;
    for (iCnt = 0; iCnt < N; iCnt++)
    {
        str2[iCnt] = str1[iCnt];
    }
    str2[iCnt] = '\0';

    return str2;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function Name   : MyStrcat
//  Discription     : It is used to Concatenates two strings
//  Input           : Charactor Array base address string 1,Charactor Array base address string 2
//  Output          : Concatenated string base addess
//  Author          : Aditya Vijay Mali
//  Date            : 02/02/2026
//
//////////////////////////////////////////////////////////////////////////

char *MyStrcat(char *str1, char *str2)
{
    int iCnt1 = 0;
    int iCnt2 = 0;

    while (str1[iCnt1] != '\0')
    {
        iCnt1++;
    }

    for (iCnt2 = 0; str2[iCnt2] != '\0'; iCnt2++, iCnt1++)
    {
        str1[iCnt1] = str2[iCnt2];
    }

    return str2;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function Name   : MyStrncat
//  Discription     : It is used to Concatenates first string with second strings only N Charactors
//  Input           : Charactor Array base address string 1,Charactor Array base address string 2,
//                    N to copy the string 2 charactor
//  Output          : Concatenated string base addess
//  Author          : Aditya Vijay Mali
//  Date            : 02/02/2026
//
//////////////////////////////////////////////////////////////////////////

char *MyStrnCat(char *destination, const char *source, int n)
{
    int iCounter;
    int iCounter2;

    for (iCounter = 0; destination[iCounter] != '\0'; iCounter++)
        ;

    for (iCounter2 = 0; iCounter2 < n && source[iCounter2] != '\0'; iCounter2++)
    {
        destination[iCounter] = source[iCounter2];
        iCounter++;
    }
    destination[iCounter] = '\0';

    return destination;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function Name   : MyStrcmp
//  Discription     : It is used to check string are equal or not
//  Input           : Charactor Array base address string 1,Charactor Array base address string 2
//  Output          : if both are same 0 if not then 1
//  Author          : Aditya Vijay Mali
//  Date            : 02/02/2026
//
//////////////////////////////////////////////////////////////////////////

int MyStrcmp(const char *str1, const char *str2)
{
    int iCnt = 0;
    for (iCnt = 0; str1[iCnt] != '\0' && str2[iCnt] != '\0'; iCnt++)
    {
        if (str1[iCnt] != str2[iCnt])
        {
            break;
        }
    }

    if (str1[iCnt] == '\0' && str2[iCnt] == '\0')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//////////////////////////////////////////////////////////////////////////
//
//  Function Name   : MyStrncmp
//  Discription     : It is used to check string are equal or not
//                    to spacific first N charactors only
//  Input           : Charactor Array base address string 1,Charactor Array base address string 2
//  Output          : if both are same 0 if not then 1
//  Author          : Aditya Vijay Mali
//  Date            : 02/02/2026
//
//////////////////////////////////////////////////////////////////////////

int MyStrncmp(const char *str1, const char *str2, int N)
{
    int iCnt = 0;
    for (iCnt = 0; str1[iCnt] != '\0' && str2[iCnt] != '\0' && iCnt < N; iCnt++)
    {
        if (str1[iCnt] != str2[iCnt])
        {
            break;
        }
    }

    if (iCnt == N)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//////////////////////////////////////////////////////////////////////////
//
//  Function Name   : MyStrrev
//  Discription     : It is used to check is the string is present in given string
//  Input           : Charactor Array base address
//  Output          : Reversed string
//  Author          : Aditya Vijay Mali
//  Date            : 02/02/2026
//
//////////////////////////////////////////////////////////////////////////

char *myStrrev(char *str)
{
    char temp;
    int iCnt1 = 0;
    int iCnt2 = 0;

    for (iCnt1 = 0; str[iCnt1] != '\0'; iCnt1++)
        ;
    iCnt1--;

    for (iCnt2 = 0; iCnt2 < iCnt1; iCnt2++, iCnt1--)
    {
        temp = str[iCnt1];
        str[iCnt1] = str[iCnt2];
        str[iCnt2] = temp;
    }

    return str;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function Name   : MyStrstr
//  Discription     : It is used to check is the string is present in given string
//  Input           : Charactor Array base address, Charactor Array base address
//  Output          : Base adderss of string 2 in string 1
//  Author          : Aditya Vijay Mali
//  Date            : 02/02/2026
//
//////////////////////////////////////////////////////////////////////////

char *MyStrstr(const char *str_main, const char *Str_To_Find)
{
    int iCnt1 = 0;
    int iCnt2 = 0;
    char *pPos = NULL;

    for (iCnt1 = 0; str_main[iCnt1] != '\0'; iCnt1++)
    {
        if (str_main[iCnt1] == Str_To_Find[iCnt2])
        {
            if (iCnt2 == 0)
                pPos = &(str_main[iCnt1]);

            iCnt2++;

            if (Str_To_Find[iCnt2] == '\0')
                break;
        }
    }

    return pPos;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function Name   : MyStrset
//  Discription     : It is used replace each charactor of a string with given charactor
//  Input           : Charactor Array base address string, charactor to replace the string
//  Output          : changed string base address
//  Author          : Aditya Vijay Mali
//  Date            : 02/02/2026
//
//////////////////////////////////////////////////////////////////////////

char *myStrset(char *p, char ch)
{
    int iCounter;

    for (iCounter = 0; p[iCounter] != '\0'; iCounter++)
    {
        p[iCounter] = ch;
    }

    return p;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function Name   : MyStrnset
//  Discription     : It is used replace only first n charactor of a string with given charactor
//  Input           : Charactor Array base address string, charactor to replace the string
//  Output          : changed string base address
//  Author          : Aditya Vijay Mali
//  Date            : 02/02/2026
//
//////////////////////////////////////////////////////////////////////////

char *myStrnset(char *p, char ch, int n)
{
    int iCounter;

    for (iCounter = 0; iCounter < n && p[iCounter] != '\0'; iCounter++)
    {
        p[iCounter] = ch;
    }
    return p;
}
