#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

char *myStrrev(char *str)
{
    char temp;
    int iCounter;
    int iCounter2;

    for (iCounter = 0; str[iCounter] != '\0'; iCounter++)
        ;
    iCounter--;

    for (iCounter2 = 0; iCounter2 < iCounter; iCounter2++)
    {
        temp = str[iCounter];
        str[iCounter] = str[iCounter2];
        str[iCounter2] = temp;

        iCounter--;
    }

    return str;
}

int main()
{
    char Name[50];
    int fd = 0;
    char Buffer[500];

    memset(Name, '\0', sizeof(Name));
    memset(Buffer, '\0', sizeof(Buffer));

    printf("Enter File name : \t");
    scanf("%[^'\n']s", Name);

    fd = open(Name, O_RDONLY);

    read(fd, Buffer, sizeof(Buffer));

    myStrrev(Buffer);

    printf("Reverse content from file is : \t %s\n", Buffer);
    return 0;
}