#include "graph.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>


// Load the graph from a file
bool Graph::loadGraphFromFile(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        return false;
    }

    int numEdges;
    infile >> numNodes >> numEdges;


    // Implement the adjacency matrix setup
    adjMatrix.resize(numNodes, std::vector<int>(numNodes, std::numeric_limits<int>::max()));

    int u, v, weight;
    for (int i = 0; i < numEdges; ++i) {
        infile >> u >> v >> weight;
        adjMatrix[u - 1][v - 1] = weight;
        adjMatrix[v - 1][u - 1] = weight;
    }

    // Comment this line before submission
    //std::cout << "TODO: Implement adjacency matrix initialization here.\n";


    infile.close();
    return true;
}

// Prim's algorithm to find the MST
int Graph::primMST(std::vector<int>& mstStart, std::vector<int>& mstEnd) {
    // Placeholder for visited nodes and minimum weight initialization
    //std::cout << "TODO: Implement Prim's algorithm here.\n";

    // Steps:
    // 1. Initialize visited array and minWeight array
    std::vector<bool> visited(numNodes, false);
    std::vector<int> minWeight(numNodes, INF);
    std::vector<int> parent(numNodes, -1);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> minHeap;

    // 2. Start from node 1
    minWeight[0] = 0;
    minHeap.push({0, 0});
    int totalCost = 0;

    // 3. Use a loop to find the minimum weight edge at each step
    while (!minHeap.empty()) {
        int weight = minHeap.top().first;
        int node = minHeap.top().second;
        minHeap.pop();
        if (visited[node]) continue;
        visited[node] = true;
        totalCost += weight;

        // 4. Update MST edges (mstStart and mstEnd vectors)
        if (parent[node] != -1) {
            mstStart.push_back(parent[node] + 1);
            mstEnd.push_back(node + 1);
        }

        for (int neighbor = 0; neighbor < numNodes; ++neighbor) {
            int edgeWeight = adjMatrix[node][neighbor];
            if (!visited[neighbor] && edgeWeight < minWeight[neighbor]) {
                // Update the minimum weight for this neighbor
                minWeight[neighbor] = edgeWeight;
                parent[neighbor] = node;

                // Push the neighbor into the min-heap
                minHeap.push({edgeWeight, neighbor});
            }
        }
    }
    // 5. Return the total cost of the MST
    return totalCost;

}


    // Placeholder output
    //mstStart.push_back(1);
    //mstEnd.push_back(2);
    //std::cout << "TODO: Replace placeholder MST output with the actual MST.\n";

    //return 0; // TODO: Return the actual total cost of the MST