#include<stdio.h>
#include<math.h>
int main()
{
    int n[3];
    while(scanf("%d %d %d",&n[0],&n[1],&n[2])!=EOF)
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<2;j++)
            {
                if(n[j]>n[j+1])
                {
                    int t=n[j];
                    n[j]=n[j+1];
                    n[j+1]=t;
                }
            }
        }
        if(n[0]+n[1]>n[2])
        {
            printf("fit\n");
        }
        else
            printf("unfit\n");
    }
}
