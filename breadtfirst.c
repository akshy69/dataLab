#include <stdio.h>
#include <stdlib.h>
#define max 100

int adj[max][max];
int visited[max];
int queue[max];
int front=-1;
int rear=-1;
int n;

void enqueue(int node){
    queue[++rear]=node;
}
int dequeue(){
    return queue[++front];
}
void bfs(int start){
    int i;
    enqueue(start);
    visited[start]=1;
    while (front!=rear)
    {
        int node =dequeue();
        printf("%d ",node);
        for ( i = 0; i < n; i++)
        {
            if(adj[node][i]==1 && !visited[i]){
                enqueue(i);
                visited[i]=1;
            }
        }
        
    }
    
}

void readGraph(){
    int i,j;
    printf("enter number of vertices : ");
    scanf("%d",&n);
    printf("enter adjancy matrix: \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
}
int main(){
    int start;
    readGraph();
    printf("enter start node: ");
    scanf("%d",&start);
    printf("breadth first search :");
    bfs(start);
    return 0;
}