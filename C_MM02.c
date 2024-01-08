#include<stdio.h>
int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        float out=(a*b)/2.0;
        printf("%.1f\n",out);
    }
}
