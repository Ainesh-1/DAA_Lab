#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct Graph {
    int vertices;
    int adj[MAX][MAX];
    int visited[MAX];
} Graph;

int stack[MAX], top = -1;

void initGraph(Graph *g, int v) {
    g->vertices = v;
    for (int i = 0; i < v; i++) {
        g->visited[i] = 0;
        for (int j = 0; j < v; j++)
            g->adj[i][j] = 0;
    }
}

void addEdge(Graph *g, int from, int to) {
    g->adj[from][to] = 1;
}

void dfs(Graph *g, int v) {
    g->visited[v] = 1;
    for (int i = 0; i < g->vertices; i++) {
        if (g->adj[v][i] && !g->visited[i]) {
            dfs(g, i);
        }
    }
    stack[++top] = v;
}

void topologicalSort(Graph *g) {
    for (int i = 0; i < g->vertices; i++) {
        if (!g->visited[i]) {
            dfs(g, i);
        }
    }

    printf("Topological Sort Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
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