#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int num;
        int count=0,total=0;
        for(int i=0;i<n;i++)
        {
            total+=i+1;
            if(i!=n-1)
            {
                scanf("%d",&num);
                count+=num;
            }
        }
        printf("%d\n",total-count);
    }
}
