#include<stdio.h>
#include<math.h>
int main()
{
    int a;
    while(scanf("%d",&a)!=EOF)
    {
        int sum=0;
        for(int i=3;i<=a;i+=3)
        {
            sum+=i;
        }
        printf("%d\n",sum);
    }
}
