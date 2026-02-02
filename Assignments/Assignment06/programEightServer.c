int CountCapital(char *str)
{
    int iCount = 0;
    int i = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            iCount++;
        }
    }

    return iCount;
}

int CountSmall(char *str)
{
    int iCount = 0;
    int i = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            iCount++;
        }
    }

    return iCount;
}

int CountDigits(char *str)
{
    int iCount = 0;
    int i = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            iCount++;
        }
    }

    return iCount;
}