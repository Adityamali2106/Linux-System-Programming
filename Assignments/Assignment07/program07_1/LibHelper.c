int IsFactor(int No, int i)
{
    if ((No % i) == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int SumOfFactors(int No)
{
    int iCnt = 0;
    int iSum = 0;

    for (iCnt = 1; iCnt <= (No / 2); iCnt++)
    {
        if ((IsFactor(No, iCnt)) == 0)
        {
            iSum = iSum + iCnt;
        }
    }

    return iSum;
}
