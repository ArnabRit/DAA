#include <stdio.h>
#define V 5 

int isSafe(int v, int graph[V][V], int path[], int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return 0;
    int i;
    for ( i = 0; i < pos; i++) {
        if (path[i] == v)
            return 0;
    }

    return 1;
}

int hamiltonianCycleUtil(int graph[V][V], int path[], int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return 1;
        else
            return 0;
    }
    int v;
    for (v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamiltonianCycleUtil(graph, path, pos + 1) == 1)
                return 1;
            path[pos] = -1; 
        }
    }

    return 0;
}

int hamiltonianCycle(int graph[V][V]) {
    int path[V];
    int i;
    for (i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0; 

    if (hamiltonianCycleUtil(graph, path, 1) == 0) {
        printf("No Hamiltonian cycle exists\n");
        return 0;
    }

    printf("Hamiltonian cycle exists: ");
    for (i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]); 

    return 1;
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 0,0},
        {1, 0, 1, 0,1},
        {1, 1, 0, 1,0},
        {0, 0, 1, 0,1},
        {0, 1, 0, 1,0}
    };

    hamiltonianCycle(graph);

    return 0;
}

