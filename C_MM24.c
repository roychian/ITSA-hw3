#include<stdio.h>
#include<math.h>
int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        double out;
        if(a<=60)
        {
            out=a*b;
        }
        else if(a>=61 && a<=120)
        {
            out=60*b+(a-60)*b*1.33;
        }
        else if(a>=121)
            out=60*b+(60*b)*1.33+(a-120)*b*1.66;
        out*=100;
        if((int)out%10>=5)
        {
            out+=10-(int)out%10;
        }
        else
            out-=(int)out%10;
        printf("%.1lf\n",out/=100);
    }
}
