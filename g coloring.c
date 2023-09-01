#include <stdio.h>
#define V 5 // Number of vertices

void printSolution(int color[]) {
    printf("Vertex\tColor\n");
    int i;
    for (i = 0; i < V; i++)
        printf("%d\t%d\n", i, color[i]);
}

int isSafe(int v, int graph[V][V], int color[], int c) {
	int i;
    for (i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c)
            return 0;
    }
    return 1;
}

int graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V) {
        printSolution(color);
        return 1;
    }
    int c;
    for (c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1) == 1)
                return 1;
            color[v] = 0;
        }
    }

    return 0;
}

void graphColoring(int graph[V][V], int m) {
    int color[V];
    int i;
    for ( i = 0; i < V; i++)
        color[i] = 0; 

    if (graphColoringUtil(graph, m, color, 0) == 0)
        printf("No solution found\n");
}

int main() {
  int graph[V][V] = {
        {0, 1, 1, 0,0},
        {1, 0, 1, 0,1},
        {1, 1, 0, 1,0},
        {0, 0, 1, 0,1},
        {0, 1, 0, 1,0}
    };
    int m = 3; 

    graphColoring(graph, m);

    return 0;
}

