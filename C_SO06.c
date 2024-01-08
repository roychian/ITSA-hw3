#include<stdio.h>
struct grade
{
    int id,math,eng
};
int main()
{
    int n;
    scanf("%d",&n);
    struct grade stu[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&stu[i].id,&stu[i].math,&stu[i].eng);
    }
    struct grade temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(stu[j+1].math>stu[j].math)
            {
                temp=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=temp;//change stu[j] and stu[j+1]
            }
            else if(stu[j+1].math==stu[j].math)
            {
                if(stu[j+1].eng>stu[j].eng)
                {
                    temp=stu[j];
                    stu[j]=stu[j+1];
                    stu[j+1]=temp;//change stu[j] and stu[j+1]
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d %d %d\n",stu[i].id,stu[i].math,stu[i].eng);
    }
}
