#include <stdio.h>
#define MAX 10
#define INF 9999
int main(){
int graph[MAX][MAX]={{0,4,2,0},{4,0,1,5},{2,1,0,8},{0,5,8,0}};
int cost[MAX][MAX],dist[MAX],visited[MAX];
int i,j,n=4,source=1,u,v,min;
for(i=1;i<=n;i++)
for(j=1;j<=n;j++){
if(graph[i-1][j-1]==0)
cost[i][j]=INF;
else
cost[i][j]=graph[i-1][j-1];
}
for(i=1;i<=n;i++){
dist[i]=cost[source][i];
visited[i]=0;
}
dist[source]=0;
visited[source]=1;
for(i=1;i<n;i++){
min=INF;
for(j=1;j<=n;j++){
if(dist[j]<min&&!visited[j]){
min=dist[j];
u=j;
}}
visited[u]=1;
for(v=1;v<=n;v++){
if(!visited[v]&&(dist[u]+cost[u][v]<dist[v]))
dist[v]=dist[u]+cost[u][v];
}}
printf("Shortest distances from source %d:\n",source);
for(i=1;i<=n;i++)
printf("%d -> %d = %d\n",source,i,dist[i]);
return 0;
}