#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 1000
#define INF 99999

int graph[MAX_NODES][MAX_NODES];
int distance[MAX_NODES];
bool visited[MAX_NODES];
int parent[MAX_NODES];

int minDistance(int n) {
    int minIndex = -1, minDist = INF;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && distance[i] < minDist) {
            minDist = distance[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int start, int n) {
    for (int i = 0; i < n; i++) {
        distance[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }

    distance[start] = 0;

    for (int i = 0; i < n-1; i++) {
        int u = minDistance(n);
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && distance[u] != INF && distance[u]+graph[u][v] < distance[v]) {
                distance[v] = distance[u]+graph[u][v];
                parent[v] = u;
            }
        }
    }
}

void printResult(int start, int n) {
    char vertex;
    char parentNode;
    for (int i = 0; i < n; i++) {
        switch (i) {
            case 0: vertex = 's'; break;
            case 1: vertex = 't'; break;
            case 2: vertex = 'x'; break;
            case 3: vertex = 'y'; break;
            case 4: vertex = 'z'; break;
        }
        switch (parent[i]) {
            case 0: parentNode = 's'; break;
            case 1: parentNode = 't'; break;
            case 2: parentNode = 'x'; break;
            case 3: parentNode = 'y'; break;
            case 4: parentNode = 'z'; break;
        }
        printf("d[%c]=%d, p[%c]=", vertex, distance[i], vertex);
        if (parent[i] == -1) {
            printf("NULL\n");
        } else {
            printf("%c\n", parentNode);
        }
    }
}

int main() {
    int n = 5; 
    int start = 0; 
    int g3[5][5] = {{0, 10, INF, 5, INF},
                    {INF, 0, 1, 2, INF},
                    {INF, INF, 0, 4, INF},
                    {INF, 3, 9, 0, 2},
                    {7, INF, 6, INF, 0}};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = g3[i][j];
        }
    }

    dijkstra(start, n);
    printResult(start, n);

    return 0;
}
