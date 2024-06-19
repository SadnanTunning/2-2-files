#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int n;
int adj[MAX][MAX];
int visited[MAX];
int level[MAX];

void create_graph();
void represent_graph();
void BFS();
void printlevel();

int queue[MAX], front = -1,rear = -1;
void enQueue(int vertex);
int deQueue();
int isEmpty_queue();

int main()
{
    create_graph();
    represent_graph();
    BFS();
    printlevel();
    return 0;
}

void create_graph()
{
    int count,max_edge,origin,destin;

    printf("No.of vertices : ");
    scanf("%d",&n);
    max_edge = n*(n-1);

    for(count=1; count<=max_edge; count++)
    {
        printf("Enter edge %d( -1 -1 to quit ) : ",count);
        scanf("%d %d",&origin,&destin);

        if((origin == -1) && (destin == -1))
            break;

        if(origin>=n || destin>=n || origin<0 || destin<0)
        {
            printf("Invalid edge!\n");
            count--;
        }
        else
        {
            adj[origin][destin] = 1;
           // adj[destin][origin] = 1;
        }
    }
}

void represent_graph()
{
    printf("\nAdjacent matrix:\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            printf("%d ",adj[i][j] );
        printf("\n");

    }
    printf("\n");
}


void BFS()
{
    int i=0;
    for(i=0; i<n; i++)
    {
        visited[i] = 0;
        level[i]=-1;
    }

    int src, u;
    printf("Start Vertex: \n");
    scanf("%d", &src);

    enQueue(src);
    level[src]=0;
    while(!isEmpty_queue())
    {
        u= deQueue( );
        if(visited[u])
            continue;

        printf("%d->",u);
        visited[u] = 1;

        for(i=0; i<n; i++)
        {
            if(adj[u][i] == 1 && visited[i] == 0)
            {
                enQueue(i);
                level[i]=level[u]+1;
            }
        }
    }
    printf("\n");
}

void printlevel()
{
    printf("vertex Level\n");
    for(int i=0; i<n; i++)
        printf("%d\t%d\n", i,level[i]);
}

void enQueue(int vertex)
{
    if(rear == MAX-1)
        printf("Queue Overflow\n");
    else
    {
        if(front == -1)
            front = 0;
        rear = rear+1;
        queue[rear] = vertex ;
    }
}

int isEmpty_queue()
{
    if(front == -1 || front > rear)
        return 1;
    else
        return 0;
}

int deQueue()
{
    int delete_item;
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        exit(1);
    }

    delete_item = queue[front];
    front = front+1;
    return delete_item;
}


