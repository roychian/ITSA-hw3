#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct network
{
    int num_link;
    int *link;
};
struct queue
{
    int node;
    int from;
};
struct all_route
{
    int *node;
    int len;
    int reqid;
};


void bfs(int num_nodes,int i,struct all_route route[],struct network input[]);
void print_all_memory_use(int max_time,int num_nodes,int max_memory[],int now_memory[][num_nodes]);
void sort_by_len(int num_req,struct all_route route[]);
int accept_req_or_not(int max_time,int num_nodes,int now_memory[][num_nodes],int max_memory[],int memuse[][num_nodes],int totaltime);
void add_memuse_to_nowmemory(int num_nodes,int now_memory[][num_nodes],int memuse[][num_nodes],int totaltime,int t);
void set_memuse(int num_nodes,int totaltime,int req,struct all_route route[],int memuse[][num_nodes]);
int main(void)
{
    int num_nodes,links,max_time,num_req;
    scanf("%d %d %d %d",&num_nodes,&links,&max_time,&num_req);
    struct network input[num_nodes];
    for(int i=0;i<num_nodes;i++)
    {
        input[i].link=malloc(sizeof(int)*num_nodes);    //malloc the same number of nodes for neighbor of every node
    }

    for(int i=0;i<num_nodes;i++)//set num_link 0
    {
        input[i].num_link=0;
    }

    int max_memory[num_nodes];
    for(int i=0;i<num_nodes;i++)//set memory
    {
        int id,mem;
        scanf("%d %d",&id,&mem);
        max_memory[id]=mem;
    }


    for(int i=0;i<links;i++)//input links
    {
        int id,ini,end;
        scanf("%d %d %d",&id,&ini,&end);
        input[ini].link[input[ini].num_link]=end;
        input[end].link[input[end].num_link]=ini;
        input[ini].num_link+=1;
        input[end].num_link+=1;
    }


    struct all_route route[num_req];
    for(int i=0;i<num_req;i++)
    {
        route[i].node=malloc(sizeof(int)*num_nodes);    //malloc the same number of nodes for bfs path
    }

    //--------bfs----------
    for(int i=0;i<num_req;i++)
    {
        bfs(num_nodes,i,route,input); //find minium route for request i,store in the route[i].node[]
    }


    //sort the route by len
    sort_by_len(num_req,route); //selecting sort from shortr route to longer route


    int now_memory[max_time+1][num_nodes];
    memset(now_memory,0,sizeof(now_memory)); //set the memory use every timeslot to 0

    //----------------------request-----------------------
    int num_ac=0;
    char *outstr=malloc(sizeof(char)*10000000);//store the printf
    *outstr='\0';
    for(int req=0;req<num_req;req++)
    {
        /*
        for(int i=0;i<route[req].len;i++)
        {
            printf("%d ",route[req].node[i]);//print the route
        }
        printf("\n");*/
        int totaltime=route[req].len; //will use route[req].len to finish each request
        if(totaltime>max_time) //exceed timeslot
            continue;

        int t=0;
        int memuse[totaltime][num_nodes];
        memset(memuse,0,sizeof(memuse));

        // set the memory that will be use in this request
        set_memuse(num_nodes,totaltime,req,route,memuse);



        //---accept request?---
        t=accept_req_or_not(max_time,num_nodes,now_memory,max_memory,memuse,totaltime); //return the time that can start the request. return -1 means reject the request
        if(t==(-1))
            continue; //reject,check next request
        num_ac++;


        // copy and add memuse to nowmemory
        add_memuse_to_nowmemory(num_nodes,now_memory,memuse,totaltime,t);

        //sprintf(outstr+strlen(outstr),"\n");
        sprintf(outstr+strlen(outstr),"%d ",route[req].reqid);//id of request
        for(int i=0;i<route[req].len;i++)
        {
            sprintf(outstr+strlen(outstr),"%d ",route[req].node[i]);//print the route
        }
        sprintf(outstr+strlen(outstr),"\n");

        int indexshift=1; //s for shift from


        t+=2;
        sprintf(outstr+strlen(outstr),"%d %d %d\n",route[req].node[0],route[req].node[1],t);


        //if len ==2,skip this part
        if(totaltime>=3)
        {
            //swap
            while(1)
            {
                sprintf(outstr+strlen(outstr),"%d %d %d\n",route[req].node[indexshift],route[req].node[indexshift+1],t);
                // swap node0,node(S-1),nodeS
                sprintf(outstr+strlen(outstr),"%d %d %d %d %d %d %d\n",route[req].node[0],route[req].node[indexshift+1],route[req].node[0],route[req].node[indexshift],route[req].node[indexshift],route[req].node[indexshift+1],t+1);
                if(indexshift+1==totaltime-1)
                {
                    break;
                }
                indexshift++;
                t++;
            }
        }

        /*
        printf("      ");

        for(int j=0;j<num_nodes;j++)
        {
            printf("%d ",j%10);
        }
        printf("\n");
        for(int i=0;i<max_time;i++)
        {
            printf("t=%2d: ",i);
            for(int j=0;j<num_nodes;j++)
            {
                printf("%d ",memuse[i][j]);
            }
            printf("\n");
        }*/

        print_all_memory_use(max_time,num_nodes,max_memory,now_memory); //print all memory use in each time with every node

    }
    printf("%d\n",num_ac);
    printf("%s",outstr);



    //----------------------request-----------------------
}
void bfs(int num_nodes,int i,struct all_route route[],struct network input[])
{
    int ini,end;
    //int finish_bfs=1;
    scanf("%d %d %d",&(route[i].reqid),&ini,&end);
    struct queue que[num_nodes];
    int visit[num_nodes];
    memset(visit,0,sizeof(visit));
    route[i].len=0;
    int buttom=0,top=0;

    que[top].node=ini;//initial
    visit[que[top++].node]=1;

    while(buttom<top)
    {
        for(int j=0;j<input[que[buttom].node].num_link;j++)//add every link of buttom que;
        {
            if(visit[input[que[buttom].node].link[j]]==0)//has visit?
            {

                que[top].node=input[que[buttom].node].link[j];//top of queue=link of (buttom of queue)
                que[top].from=buttom;
                visit[que[top].node]=1;

                //printf("add node %d from %d\n",que[top].node,que[top].from);
                if(que[top].node==end)//find the end
                {
                    int *temp=malloc(sizeof(int)*num_nodes);
                    while(que[top].node!=ini)
                    {
                        temp[route[i].len]=que[top].node;
                        top=que[top].from;
                        route[i].len++;
                    }
                    temp[route[i].len++]=ini;

                    //inverse the route
                    for(int k=0;k<route[i].len;k++)
                    {
                        route[i].node[k]=temp[route[i].len-k-1];
                    }
                    return;
                }
                top++;
            }
        }
        buttom++;
    }
}
void print_all_memory_use(int max_time,int num_nodes,int max_memory[],int now_memory[][num_nodes])
{
    printf("node: ");
    for(int i=0;i<num_nodes;i++)
    {
        printf("%d ",i%10);
    }
    printf("\n");

    printf(" max: ");
    for(int i=0;i<num_nodes;i++)
    {
        printf("%d ",max_memory[i]);
    }
    printf("\n");
    for(int i=0;i<max_time;i++)
    {
        printf("t=%2d: ",i+1);
        for(int j=0;j<num_nodes;j++)
        {
            printf("%d ",now_memory[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void sort_by_len(int num_req,struct all_route route[])
{
    struct all_route temp;
    for(int i=0;i<num_req;i++)  //selecting sort from short route to longer route
    {
        int min_index=i;
        for(int j=i+1;j<num_req;j++)
        {

            if(route[j].len<route[min_index].len)
            {
                min_index=j;
            }
        }
        temp=route[i];
        route[i]=route[min_index];
        route[min_index]=temp;
    }
}
int accept_req_or_not(int max_time,int num_nodes,int now_memory[][num_nodes],int max_memory[],int memuse[][num_nodes],int totaltime)
{
    //---accept request?---
    int can=1;
    for(int time=0;time<totaltime;time++)
    {
        can=1;
        if(time+totaltime>max_time) //exceed time_slot
        {
            return -1;
        }
        for(int i=0;i<num_nodes && can==1;i++) //every node on path
        {
            for(int j=0;j<totaltime;j++) //from time to time+total_time
            {
                    if(now_memory[time+j][i]+memuse[j][i]>max_memory[i])//exceed max_memory
                    {
                        can=0;
                        break;  //try next t
                    }
            }
        }
        if(can==1)
        {
            return time; //start entangle in time t
        }
    }

    return -1; //reject
}
void add_memuse_to_nowmemory(int num_nodes,int now_memory[][num_nodes],int memuse[][num_nodes],int totaltime,int t)
{
    for(int i=0;i<num_nodes;i++) //every node on path
    {
        for(int j=0;j<totaltime;j++) //from t to t+totaltime
        {
                now_memory[t+j][i]+=memuse[j][i];
        }
    }
}
void set_memuse(int num_nodes,int totaltime,int req,struct all_route route[],int memuse[][num_nodes])
{
    for(int time=0;time<totaltime;time++) // set 1,2,2,1 in swap
    {
        if(time!=0) //other row
        {
            memuse[time][route[req].node[0]]+=1; //initial node
            memuse[time][route[req].node[time]]+=1; //the node will attach after swap
        }
        if(time+1<=totaltime-1) //before the last row,entangle of (i,i+1) is finish
        {
            memuse[time][route[req].node[time]]+=1;
            memuse[time][route[req].node[time+1]]+=1;
        }
        if(time+2<=totaltime-1) //before the last two row, start entangle with (i+1,i+2)
        {
            memuse[time][route[req].node[time+1]]+=1;
            memuse[time][route[req].node[time+2]]+=1;
        }
    }
}
