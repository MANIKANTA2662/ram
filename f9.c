#include <stdio.h>
#define MAX 10
#define INF 9999
int main(){
int cost[MAX][MAX]={{0,3,INF,7},{8,0,2,INF},{5,INF,0,1},{2,INF,INF,0}};
int i,j,k,n=4;
for(k=0;k<n;k++)
for(i=0;i<n;i++)
for(j=0;j<n;j++)
if(cost[i][j]>cost[i][k]+cost[k][j])
cost[i][j]=cost[i][k]+cost[k][j];
printf("Shortest path matrix:\n");
for(i=0;i<n;i++){
for(j=0;j<n;j++)
printf("%d ",cost[i][j]);
printf("\n");
}
return 0;
}