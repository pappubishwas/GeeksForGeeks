#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10005

struct ListNode {
    int data;
    struct ListNode *next;
};

struct graph {
    struct ListNode *head[N];
};

struct edges {
    int src, dest;
};

void show_graph(struct graph *g, int n, int m) {
    for (int i = 0; i < n; i++) {
        struct ListNode *graph_ptr = g->head[i];
        if (graph_ptr != NULL) {
            printf("%d-->", i);
        }
        while (graph_ptr != NULL) {
            printf("%d ", graph_ptr->data);
            graph_ptr = graph_ptr->next;
        }
        printf("\n");
    }
}

struct graph *create_graph(struct edges arr_edges[], int n, int m) {
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));

    for (int i = 0; i < n; i++) {
        g->head[i] = NULL;
    }

    for (int i = m - 1; i >= 0; i--) {
        int u = arr_edges[i].src, v = arr_edges[i].dest;

        // edge from u->v
        struct ListNode *newNode =
            (struct ListNode *)malloc(sizeof(struct ListNode));

        newNode->data = v;
        newNode->next = g->head[u];
        g->head[u] = newNode;

        // edge from v->u
        newNode = (struct ListNode *)malloc(sizeof(struct ListNode));

        newNode->data = u;
        newNode->next = g->head[v];
        g->head[v] = newNode;
    }

    return g;
}

void dfsUtil(struct graph *g, int v, int visited[]) {
    // Mark the current node as visited
    visited[v] = 1;
    printf("%d ", v);

    // Traverse all adjacent vertices of the current node
    struct ListNode *node = g->head[v];
    while (node != NULL) {
        int adj = node->data;
        if (!visited[adj]) {
            dfsUtil(g, adj, visited);
        }
        node = node->next;
    }
}

void dfs(struct graph *g, int n, int m) {
    // Create an array to keep track of visited nodes
    int visited[n];
    memset(visited, 0, sizeof(visited));
    stack<graph*> st;
    // Start DFS from every unvisited node in case of disconnected graphs
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfsUtil(g, i, visited);
        }
    }
}

int main() {
    int t = 1;

    while (t--) {
        int queries;
        scanf("%d", &queries);
        while (queries--) {
            int n, m;
            scanf("%d %d", &n, &m);
            struct edges arr_edges[m];
            for (int i = 0; i < m; i++) {
                int u, v;
                scanf("%d %d", &u, &v);
                arr_edges[i].src = u;
                arr_edges[i].dest = v;
            }

            struct graph *g = create_graph(arr_edges, n, m);

            dfs(g, n, m);
            printf("\n");
        }
    }
    return 0;
}
