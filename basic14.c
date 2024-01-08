#include<stdio.h>
#include<string.h>
int main()
{
    char n[1000];
    while(scanf("%s",&n)!=EOF)
    {
        int yes=1;
        for(int i=0;i<strlen(n);i++)
        {
            if(n[i]!=n[strlen(n)-i-1])
            {
                printf("NO\n");
                yes=0;
                break;
            }
        }
        if(yes==1)
            printf("YES\n");
    }
}
