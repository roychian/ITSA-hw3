#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int is;
        is=1;
        for(int j=n/2;j>1;j--)
        {
            if(n%j==0)
            {
                is=0;
                printf("NO\n");
                break;

            }
        }
        if(is==1)
        {
            printf("YES\n");
        }
    }
}
