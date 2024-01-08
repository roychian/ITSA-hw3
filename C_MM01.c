#include<stdio.h>
int main()
{
    int up,but,h;
    while(scanf("%d %d %d",&up,&but,&h)!=EOF)
    {
        printf("Trapezoid area:%.1f\n",((up+but)*h)/2.0);
    }
}
