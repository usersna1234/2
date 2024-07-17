#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int n, a[MAX][MAX], visited[MAX],u,v,i,j,source;
void dfs() {
    visited[u] = 1;
    for (v = 1; v <= n; v++)
        if (a[u][v] == 1 && !visited[v])
            dfs(v);
}
int main() {
    printf("Enter the number of vertices of the graph: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    for (source = 1; source <= n; source++) {
        int allVisited = 1;
        for (j = 1; j <= n; j++) {
            if (!visited[j]) {
                printf("%d is not reachable from %d\n", j, source);
                printf("So the graph is not connected\n");
                exit(0);
            }
        }
        for (j = 1; j <= n; j++)
            visited[j] = 0;
    dfs(source);
    }
    printf("The graph is connected\n");
    return 0;
}
