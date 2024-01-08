#include<stdio.h>
int main()
{
    int input[100];
    int i=0,count=0;
    while(scanf("%d",&input[i])!=EOF)
    {
        i++;
    }
    for(int j=i-1;j>=0;j--)
    {
        if(j==i-1)
        printf("%d",input[j]);
        else
        printf(" %d",input[j]);
    }
    printf("\n");

}

