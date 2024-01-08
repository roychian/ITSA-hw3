#include<stdio.h>
#include<string.h>
int main()
{

    while(1)
    {
        char n[30];
        gets(n);
        if(strcmp(n,"end")==0)
            break;
        char check;
        int count=0;
        scanf("%c ",&check);
        for(int i=0;i<strlen(n);i++)
        {
            if((n[i])==check)
                count++;
        }
        printf("%d\n",count);
    }
}
