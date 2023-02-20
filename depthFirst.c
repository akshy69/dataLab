#include <stdio.h>
#include <stdlib.h>
#define max 100

int adj[max][max];
int visited[max];
int n;

void dfs(int node){
    int i;
    printf("%d",node);
    visited[node]=1;
    for(i=0;i<n;i++){
        if(adj[node][i]==1 && !visited[i]){
            dfs(i);
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
    printf("depth first search :");
    dfs(start);
    return 0;
}