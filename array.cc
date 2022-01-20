// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph
#include <iostream>
using namespace std;
#include <limits.h>
#include <fstream>
#include <bits/stdc++.h>

// Number of vertices in the graph
int V;

float totalDistance = 0;
// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(float dist[], bool sptSet[])
{
  
    // Initialize min value
    float min = FLT_MAX;
    int  min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance array
void printSolution(float dist[])
{
//    cout <<"Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++){
        totalDistance += dist[i];
//        cout << dist[i] << endl;
    }
}


// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(float** graph, int src)
{
    float dist[V]; // The output array.  dist[i] will hold the shortest
    // distance from src to i

    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = FLT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != FLT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    printSolution(dist);
}

// driver program to test above function
int main(int argc, char* argv[])
{
    clock_t begin, end;
    string file_connect;
    file_connect = argv[2];
    V = atoi(argv[1]);
    fstream file(file_connect);
    int p1, p2;
    float d;
//    float arr[V][V] = {0};
    float** arr = new float*[V];
    
    for(int i=0;i<V;i++){
        arr[i] = new float[V];
        for(int j=0;j<V;j++){
            arr[i][j] = 0;
        }
    }
    while(file >> p1 >> p2 >> d){
        arr[p1][p2] = d;
        arr[p2][p1] = d;
    }
    file.close();

    begin = clock();
    for(int i=0;i<V;i++){
        dijkstra(arr,i);
    }
    end = clock();

    for(int i=0;i<V;i++){
        delete arr[i];
    }
    delete arr;
    double time = double(end - begin) / double(CLOCKS_PER_SEC);
    cout << totalDistance << endl;
    float average = float(totalDistance) / float(V*(V-1)/2);
    file.open("arr.csv", ios_base::app);
    file << V << "," << time << "," << totalDistance << "," << average << endl;
    file.close();

    return 0;
}

// This code is contributed by shivanisinghss2110
