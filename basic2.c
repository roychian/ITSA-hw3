#include<stdio.h>
int main()
{
    int n;
    double out;
    while(scanf("%d",&n)!=EOF)
    {
        out=(double)n*1.6;
        printf("%.1lf\n",out);
    }
}
