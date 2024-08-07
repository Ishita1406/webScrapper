#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 1000

// Function to add an edge to the adjacency matrix
void addEdge(int adj[MAX_NODES][MAX_NODES], int u, int v)
{
    adj[u][v] = 1;
    adj[v][u] = 1;
}

// Function to perform Level Order traversal
void levelordertraversal(int adj[MAX_NODES][MAX_NODES], int numNodes, int start)
{
    bool vis[MAX_NODES] = {false};
    int queue[MAX_NODES];
    int s = 0, e = 0;

    // Start from the root node (start)
    queue[e++] = start;
    vis[start] = true;

    while (s < e)
    {
        int node = queue[s++];
        printf("%d ", node);

        // Visit all adjacent nodes that are not visited yet
        for (int i = 0; i < numNodes; ++i)
        {
            if (adj[node][i] && !vis[i])
            {
                queue[e++] = i;
                vis[i] = true;
            }
        }
    }
}

int main()
{
    int numEdges;
    scanf("%d", &numEdges);

    int adj[MAX_NODES][MAX_NODES] = {0};
    int numNodes = 0;

    // Reading edges and building adjacency matrix
    for (int i = 0; i < numEdges; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        if (u > numNodes)
            numNodes = u;
        if (v > numNodes)
            numNodes = v;
    }
    numNodes++; // Nodes are assumed to be zero-indexed, so increment by one for the count

    // Perform level-order traversal starting from node 0
    levelordertraversal(adj, numNodes, 0);
    printf("\n");

    return 0;
}