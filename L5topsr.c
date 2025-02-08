#include <stdio.h>
#include <stdlib.h>

#define MAX 20

// Graph structure
typedef struct Graph {
    int vertices;
    int adj[MAX][MAX];
    int inDegree[MAX];  
} Graph;

int queue[MAX], front = 0, rear = -1;

void initGraph(Graph *g, int v) {
    g->vertices = v;
    for (int i = 0; i < v; i++) {
        g->inDegree[i] = 0;
        for (int j = 0; j < v; j++)
            g->adj[i][j] = 0;
    }
}

void addEdge(Graph *g, int from, int to) {
    g->adj[from][to] = 1;
    g->inDegree[to]++;  
}

void topologicalSort(Graph *g) {
    int sorted[MAX], index = 0; 

    for (int i = 0; i < g->vertices; i++) {
        if (g->inDegree[i] == 0) {
            queue[++rear] = i;
        }
    }

    while (front <= rear) {
        int v = queue[front++]; 
        sorted[index++] = v;

        for (int i = 0; i < g->vertices; i++) {
            if (g->adj[v][i]) {
                g->inDegree[i]--;
                if (g->inDegree[i] == 0) {
                    queue[++rear] = i;
                }
            }
        }
    }

    if (index == g->vertices) {
        printf("Topological Sort Order: ");
        for (int i = 0; i < index; i++) {
            printf("%d ", sorted[i]);
        }
        printf("\n");
    } else {
        printf("Cycle detected! Topological sorting is not possible.\n");
    }
}

int main() {
    int vertices, edges, from, to;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    Graph g;
    initGraph(&g, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (from to):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &from, &to);
        addEdge(&g, from, to);
    }

    topologicalSort(&g);
}