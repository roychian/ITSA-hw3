#include<stdio.h>
#include<math.h>
int main()
{
    int a[6];
    int i=0;
    while(scanf("%d",&a[i])!=EOF)
    {

        i++;
        if(i==6)
        {
            int sum=0;
            for(int j=0;j<6;j++)
            {
                a[j]=pow(a[j],3);
                sum+=a[j];
            }
            printf("%d\n",sum);
        }
    }
}
