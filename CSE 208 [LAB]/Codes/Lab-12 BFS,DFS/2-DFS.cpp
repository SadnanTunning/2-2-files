#include<stdio.h>
#include<stdlib.h>

#define MAX 100

#define initial 1
#define visited 2

int n;    /* Number of nodes in the graph */
int adj[MAX][MAX]; /*Adjacency Matrix*/
int state[MAX]; /*Can be initial or visited */


void DFS();
void create_graph();
void represent_graph();

int stack[MAX];
int top = -1;
void push(int v);
int pop();
int isEmpty_stack();

main()
{
    create_graph();
    represent_graph();
    DFS();
}/*End of main()*/


void create_graph()
{
    int i,max_edges,origin,destin;

    printf("No. of nodes : ");
    scanf("%d",&n);
    max_edges=n*(n-1);

    for(i=1; i<=max_edges; i++)
    {
        printf("Enter edge %d( -1 -1 to quit ) : ",i);
        scanf("%d %d",&origin,&destin);

        if( (origin == -1) && (destin == -1) )
            break;

        if( origin >= n || destin >= n || origin<0 || destin<0)
        {
            printf("Invalid edge!\n");
            i--;
        }
        else
            adj[origin][destin] = 1;

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
void DFS()
{
    int i;
    for(i=0; i<n; i++)
        state[i]=initial;

    printf("\nStarting node: ");
    int src,u;
    scanf("%d",&src);
    push(src);

    while(!isEmpty_stack())
    {
        u = pop();
        if(state[u]==initial)
        {
            printf("%d-> ",u);
            state[u]=visited;
        }
        for(i=n-1; i>=0; i--)
        {
            if(adj[u][i]==1 && state[i]==initial)
                push(i);
        }
    }
}/*End of DFS( )*/

void push(int v)
{
    if(top == (MAX-1))
    {
        printf("\nStack Overflow\n");
        return;
    }
    top=top+1;
    stack[top] = v;

}/*End of push()*/

int pop()
{
    int v;
    if(top == -1)
    {
        printf("\nStack Underflow\n");
        exit(1);
    }
    else
    {
        v = stack[top];
        top=top-1;
        return v;
    }
}/*End of pop()*/

int isEmpty_stack( )
{
    if(top == -1)
        return 1;
    else
        return 0;
}/*End if isEmpty_stack()*/

