#include <stdio.h>
#include<math.h>
int main(void) {
    int input[7],n,i=0;
    while(scanf("%d,",&n)!=EOF)
    {
        input[i]=n;
        i++;
    }
    //printf("(i)%d\n",i);
    int max=0,min=0;
    for(int j=0;j<i;j++)//find max
    {
        for(int k=0;k<i-j-1;k++)
        {
            if(input[k]<input[k+1])
            {
                int temp=input[k];
                input[k]=input[k+1];
                input[k+1]=temp;
            }
        }
    }
    for(int j=0;j<i;j++)
    {
        max+=input[i-1-j]*pow(10,j);
        min+=input[j]*pow(10,j);
    }
    printf("%d\n",max-min);
}
