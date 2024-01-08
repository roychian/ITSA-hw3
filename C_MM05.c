#include<stdio.h>
#include<math.h>
int main()
{
    double n;
    while(scanf("%lf",&n)!=EOF)
    {
        n*=10;
        n=pow(n,2);
        if((int)n%10>=5)//carry
        {
            n+=10-((int)n%10);
        }
        else
            n-=(int)n%10;
        n/=100;
        printf("%.1lf\n",n);
    }
}
