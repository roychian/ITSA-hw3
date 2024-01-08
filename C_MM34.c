#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            if(n%i==0)
            {
                if(i==1)
                {
                    printf("%d",i);
                }
                else
                    printf(" %d",i);
            }
        }
        printf("\n");


    }
}
