#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n>=0)
        {
            for(int i=7;i>=0;i--)
            {
                if(n>=pow(2,i))
                {
                    printf("1");
                    n-=pow(2,i);
                }
                else
                    printf("0");
            }
        }
        else
        {
            n*=(-1);
            n-=1;
            for(int i=7;i>=0;i--)
            {
                if(n>=pow(2,i))
                {
                    printf("0");
                    n-=pow(2,i);
                }
                else
                    printf("1");
            }
        }
        printf("\n");

    }
}
