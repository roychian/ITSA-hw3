#include<stdio.h>
#include<math.h>
int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        if((a>100 || a<0) || (b>100 || b<0))
        {
            printf("outside\n");
        }
        else
            printf("inside\n");
    }
}
