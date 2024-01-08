#include<stdio.h>
struct arr
{
    char word[100]
};
int main()
{
    struct arr input[100];
    int single=0,words=0;
    while(1)
    {
        gets
        printf("(%d %d)",single,words);
        if(input[words].word[single]=='\n')
        {
            for(int j=words;j>=0;j--)
            {
                printf("%s",input[j].word);
            }
            single=0;
            words=0;
        }
        else if(input[words].word[single]==' ')
            words++;
        single++;
    }

}

