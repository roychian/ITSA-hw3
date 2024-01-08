#include<stdio.h>
#include<math.h>
int main()
{
    float n;
    while(scanf("%f",&n)!=EOF)
    {
        float out=((n*9)/5)+32;
        out*=100;
        if((int)(out)%10>=5)
        {
            out+=10-(int)(out)%10;
        }
        else
            out-=(int)(out)%10;
        out/=100;
        printf("%.1f\n",out);
    }
}
