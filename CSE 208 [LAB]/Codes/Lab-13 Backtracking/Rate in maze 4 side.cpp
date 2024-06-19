#include <iostream>
using namespace std;
#define SIZE 5

int maze[SIZE][SIZE] =
{
    {0,1,0,1,1},
    {0,0,0,0,0},
    {1,0,1,0,1},
    {0,0,1,0,0},
    {1,0,0,1,0}
};
int solution[SIZE][SIZE];


void printsolution()
{
    int i,j;
    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            printf("%d\t",solution[i][j]);
        }
        printf("\n\n");
    }
}

int solvemaze(int r, int c)
{
    //if destination is reached, maze is solved
   //destination is the last cell(maze[SIZE-1][SIZE-1])
    if((r==SIZE-1) && (c==SIZE-1))
    {
        solution[r][c] = 1;
        return 1;
    }

    if(r>=0 && c>=0 && r<SIZE && c<SIZE && solution[r][c] == 0 && maze[r][c] == 0)
    {
        //if safe to visit then visit the cell
        solution[r][c] = 1;
        //going down
        if(solvemaze(r+1, c))
            return 1;
        //going right
        if(solvemaze(r, c+1))
            return 1;
        //going up
        if(solvemaze(r-1, c))
            return 1;
        //going left
        if(solvemaze(r, c-1))
            return 1;
        //backtracking
        solution[r][c] = 0;
        return 0;
    }
    return 0;
}
int main()
{
    //making all elements of the solution matrix 0
    int i,j;
    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            solution[i][j] = 0;
        }
    }
    if (solvemaze(0,0))
        printsolution();
    else
        printf("No solution\n");
    return 0;
}
