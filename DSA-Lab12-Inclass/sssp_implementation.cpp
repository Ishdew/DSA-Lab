#include <iostream>
#include <climits> // For INT_MAX

using namespace std;

#define V 6 // Number of vertices in the graph

int minDistance(int distances[], bool visited[]) {
   int min = INT_MAX, min_index;
   for (int v = 0; v < V; v++)
     if (visited[v] == false && distances[v] <= min)
         min = distances[v], min_index = v;
   return min_index;
}

void dijkstra(int graph[V][V], int startNode) {
    int distances[V]; // The output array. distances[i] will hold the shortest distance from startNode to i.
    bool visited[V]; // visited[i] will be true if i is included in shortest path tree or shortest distance from startNode to i is finalized.

    // Initialize all distances as INFINITE and visited[] as false
    for (int i = 0; i < V; i++) {
        distances[i] = INT_MAX;
        visited[i] = false;
    }

    // Distance of source vertex from itself is always 0
    distances[startNode] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        int u = minDistance(distances, visited);

        // Mark the picked vertex as processed
        visited[u] = true;

        // Update distances of adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++) {
            // Update distances[v] only if it is not in visited[], there is an edge from u to v,
            // and total weight of path from startNode to v through u is smaller than current value of distances[v]
            if (!visited[v] && graph[u][v] && distances[u] != INT_MAX
                && distances[u] + graph[u][v] < distances[v])
                distances[v] = distances[u] + graph[u][v];
        }
    }

    // Print the shortest distances from startNode to all other nodes
    cout << "Vertex \t Distance from "<< startNode << endl;
    for (int i = 0; i < V; i++) {
        if(distances[i] == INT_MAX) {
            cout << i << " \t\t " << "INF" << endl;
        } else {
            cout << i << " \t\t " << distances[i] << endl;
        }
    }
}

int main() {
    int graph[V][V] = { { 0, 10, 0, 0, 15, 5 },
                        { 10, 0, 10, 30, 0, 0 },
                        { 0, 10, 0, 12, 5, 0 },
                        { 0, 30, 12, 0, 0, 20 },
                        { 15, 0, 5, 0, 0, 0 },
                        { 5, 0, 0, 20, 0, 0} };

    dijkstra(graph, 0);

    return 0;
}