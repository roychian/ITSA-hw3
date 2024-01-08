#include<stdio.h>
int main()
{
    float n,sum=0;
    while(scanf("%f",&n)!=EOF)
    {
        sum=n;
        while(1)
        {

            n/=2;
            if(n<1)
                break;
            sum+=2*n;
            //printf("now %f\n",n);

        }
        sum*=1000;
        if((int)sum%10>=5)
        {
            sum+=10-(int)sum%10;
        }
        else
            sum-=(int)sum%10;
        sum/=1000;
        printf("%.2f\n",sum);

    }
}
