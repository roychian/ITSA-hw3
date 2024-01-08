#include<stdio.h>
#include<math.h>
int main()
{
    int x,y;
    float rad=pow(pow(100,2)+pow(100,2),0.5);
    while(scanf("%d %d",&x,&y)!=EOF)
    {
        if((float)(pow(pow(x,2)+pow(y,2),0.5))<=rad)
        {
            printf("inside\n");
        }
        else
        {
            printf("outside\n");
        }
    }
}
