#include<stdio.h>
#include<math.h>
struct xy
{
    int x;
    int y;
};
int main()
{


    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            int num;
            scanf("%d",&num);
            struct xy point[num];
            int dis=0;
            for(int j=0;j<num;j++)
            {
                scanf("%d %d",&point[j].x,&point[j].y);

            }
            dis=pow(point[0].x-point[1].x,2)+pow(point[0].y-point[1].y,2); //(x1-x2)^2+(y1-y2)^2

            for(int j=0;j<num;j++)
            {
                for(int k=0;k<num;k++)
                {
                    if(j!=k)
                    {
                        if(dis<pow(point[j].x-point[k].x,2)+pow(point[j].y-point[k].y,2))
                        {
                            dis=pow(point[j].x-point[k].x,2)+pow(point[j].y-point[k].y,2);
                        }
                    }
                }

            }
            printf("%d\n",dis);

        }

    }
}

/*
1
2 1 -1 2 3

*/
