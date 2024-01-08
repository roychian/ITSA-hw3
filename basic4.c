#include<stdio.h>
int main()
{
    int h1,m1,h2,m2;
    while(scanf("%d %d %d %d",&h1,&m1,&h2,&m2)!=EOF)
    {
        int out=0;
        if(h1>h2)
        {
            h2+=24;
        }
        int min=h2*60+m2-(h1*60+m1);//delta time

        if(min>240)
        {
            out=120+160+(min-240)/30*60;
        }
        else if(min>120)
        {
            out=120+(min-120)/30*40;
        }
        else if(min>0)
        {
            out=min/30*30;
        }
        printf("%d\n",out);

    }
}

