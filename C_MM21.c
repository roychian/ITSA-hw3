#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        long long int sum=1;
        for(int i=1;i<=n;i++)
        {
            sum*=i;
        }
        printf("%lld\n",sum);
    }
}
