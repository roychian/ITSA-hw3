#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int find;
        for(int i=n-1;i>0;i--)
        {
            find=1;
            for(int j=i/2;j>1;j--)
            {
                if(i%j==0)
                {
                    find=0;
                    break;

                }
            }
            if(find==1)
            {
                printf("%d\n",i);
                break;
            }
        }



    }
}
