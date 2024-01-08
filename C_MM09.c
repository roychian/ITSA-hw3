#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n>31)
        {
            printf("Value of more than 31\n");
            continue;
        }
        printf("%d\n",1<<n);
    }
}
