#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& adjacencyMatrix) {
        int numNodes = adjacencyMatrix.size();
        int* visited = new int[numNodes]();  
        int provinceCount = 0;

        for (int node = 0; node < numNodes; node++) {
            if (!visited[node]) {
                provinceCount++;
                explore(adjacencyMatrix, visited, node);
            }
        }
        delete[] visited;
        return provinceCount;
    }

private:
    void explore(vector<vector<int>>& adjacencyMatrix, int* visited, int currentNode) {
        visited[currentNode] = 1;
        for (int neighbor = 0; neighbor < adjacencyMatrix.size(); neighbor++) {
            if (adjacencyMatrix[currentNode][neighbor] && !visited[neighbor]) {
                explore(adjacencyMatrix, visited, neighbor);
            }
        }
    }
};

int main() {
    Solution solution;

    vector<vector<int>> adjacencyMatrix = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    int result = solution.findCircleNum(adjacencyMatrix);
    cout << "Number of Provinces: " << result << endl;

    return 0;
}
