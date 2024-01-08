#include<stdio.h>
#include<string.h>
int main()
{
    int n;

    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char a[40]={'0'},b[40]={'0'};
        int out[40]={0};
        scanf("%s %s",&a,&b);
        for(int j=0;j<40;j++)
        {
            //printf("a b is %d %d\n",strlen(a)-j-1,strlen(b)-j-1);

            if((int)strlen(a)-j-1<0 && (int)strlen(b)-j-1<0)
            {
                break;
            }
            if((int)strlen(b)-j-1>=0)
            {
                out[39-j]+=(b[strlen(b)-j-1]-'0');//a finish
            }

            if((int)strlen(a)-j-1>=0)
            {
                out[39-j]+=(a[strlen(a)-j-1]-'0');//b finish
            }

            if(out[39-j]>=10)
            {
                out[39-j]-=10;
                out[39-j-1]+=1;
            }
        }
        int yes=0;
        for(int j=0;j<40;j++)
        {
            if(out[j]!=0)
            {
                yes=1;
            }
            if(yes==1)
            {
                printf("%d",out[j]);
            }
        }
        printf("\n");

    }
}
