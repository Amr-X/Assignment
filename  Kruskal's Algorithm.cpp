#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};

// Function to find the parent of a node
int findParent(int node, int parent[]) {
    while (node != parent[node]) node = parent[node];
    return node;
}

// Kruskal's algorithm
void kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.weight < b.weight; }); // Sort edges by weight

    int parent[n];
    for (int i = 0; i < n; i++) parent[i] = i; // Initialize parent array

    cout << "Minimum Spanning Tree:" << endl;
    for (Edge e : edges) {
        int p1 = findParent(e.src, parent);
        int p2 = findParent(e.dest, parent);

        if (p1 != p2) { // If no cycle
            cout << e.src << " - " << e.dest << " : " << e.weight << endl;
            parent[p2] = p1; // Union
        }
    }
}

int main() {
    int n = 4; // Number of vertices
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskal(n, edges);
    return 0;
}
