#include<stdio.h>
#include<math.h>
int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        for(int i=a;i>0;i--)
        {
            if(a%i==0 && b%i==0)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
}
