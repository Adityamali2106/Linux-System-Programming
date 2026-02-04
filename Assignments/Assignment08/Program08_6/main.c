#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

int main(void)
{
    void *handel = NULL;
    int (*fp)(int ,int );

    int iNo1 = 0, iNo2 = 0, iRet = 0;
    int iChoice = 0;

    while(1)
    {
        printf("1. Addition         \n");
        printf("2. Substraction     \n");
        printf("3. Multiplication   \n");
        printf("4. Division         \n");
        printf("5. Exit             \n");

        printf("Enter your choice : \n");
        scanf("%d",&iChoice);

        if(iChoice == 1)
        {
            printf("Enter two Numbers : \n");
            scanf("%d%d",&iNo1,&iNo2);

            handel = dlopen("libmath.so",RTLD_LAZY);
            if(NULL == handel)
            {
                printf("ERROR: %s",dlerror());
                return -1;
            }

            fp = dlsym(handel,"Add");

            iRet = fp(iNo1,iNo2);
            printf("Addition is : %d\n",iRet);

            dlclose(handel);
        }
        else if(iChoice == 2)
        {
            printf("Enter two Numbers : \n");
            scanf("%d%d",&iNo1,&iNo2);

            handel = dlopen("libmath.so",RTLD_LAZY);
            if(NULL == handel)
            {
                printf("ERROR: %s",dlerror());
                return -1;
            }

            fp = dlsym(handel,"Sub");

            iRet = fp(iNo1,iNo2);
            printf("Substraction is : %d\n",iRet);

            dlclose(handel);
        }
        else if(iChoice == 3)
        {
            printf("Enter two Numbers : \n");
            scanf("%d%d",&iNo1,&iNo2);

            handel = dlopen("libmath.so",RTLD_LAZY);
            if(NULL == handel)
            {
                printf("ERROR: %s",dlerror());
                return -1;
            }

            fp = dlsym(handel,"Div");

            iRet = fp(iNo1,iNo2);
            printf("Division is : %d\n",iRet);

            dlclose(handel);
        }
        else if(iChoice == 4)
        {
            printf("Enter two Numbers : \n");
            scanf("%d%d",&iNo1,&iNo2);

            handel = dlopen("libmath.so",RTLD_LAZY);
            if(NULL == handel)
            {
                printf("ERROR: %s",dlerror());
                return -1;
            }

            fp = dlsym(handel,"Mul");

            iRet = fp(iNo1,iNo2);
            printf("Multiplication is : %d\n",iRet);

            dlclose(handel);
        }
        else if(iChoice == 5)
        {
            printf("Thank You\n");
            break;
        }
        else
        {
            printf("Invalid Choice \n Enter valid choice \n");
        }

    }
    
    return 0;
}