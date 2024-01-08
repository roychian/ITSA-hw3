#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        double out=pow(n%10,3)+pow((n%100)/10,3)+pow((n/100),3);
        if((int)out==n)
        {
            printf("Yes\n");
        }
        else
            printf("No\n");

    }
}
