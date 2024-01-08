#include<stdio.h>
#define d 86400
#define h 3600
#define m 60
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d days\n",n/d);
        n=n%d;
        printf("%d hours\n",n/h);
        n=n%h;
        printf("%d minutes\n",n/m);
        n=n%m;
        printf("%d seconds\n",n);
    }
}
