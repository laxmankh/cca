#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a graph edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a disjoint set
struct DisjointSet {
    int *parent, *rank;
    int n;

    DisjointSet(int n) {
        this->n = n;
        parent = new int[n + 1];
        rank = new int[n + 1];

        // Initialize each set as a singleton set with rank 0
        for (int i = 0; i <= n; i++) {
            rank[i] = 0;
            parent[i] = i;
        }
    }

    // Find the set of an element (uses path compression)
    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]); // Path compression
        return parent[u];
    }

    // Union of two sets of x and y (uses union by rank)
    void Union(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);

        if (rank[xRoot] < rank[yRoot])
            parent[xRoot] = yRoot;
        else if (rank[xRoot] > rank[yRoot])
            parent[yRoot] = xRoot;
        else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
};

// Compare function for sorting edges based on their weights
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Kruskal's algorithm to find Minimum Spanning Tree
void Kruskal(vector<Edge> edges, int V) {
    // Sort the edges in non-decreasing order of their weights
    sort(edges.begin(), edges.end(), compareEdges);

    // Allocate memory for the disjoint set
    DisjointSet ds(V);

    // Vector to store the result (minimum spanning tree)
    vector<Edge> result;

    // Iterate through all sorted edges
    for (Edge edge : edges) {
        int x = ds.find(edge.src);
        int y = ds.find(edge.dest);

        // If including this edge does not cause a cycle, add it to the result
        if (x != y) {
            result.push_back(edge);
            ds.Union(x, y);
        }
    }

    // Print the result
    cout << "Edges of the Minimum Spanning Tree:\n";
    for (Edge edge : result) {
        cout << edge.src << " -- " << edge.dest << " : " << edge.weight << "\n";
    }
}

int main() {
    // Example usage
    int V = 4; // Number of vertices
    vector<Edge> edges = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};

    Kruskal(edges, V);

    return 0;
}
