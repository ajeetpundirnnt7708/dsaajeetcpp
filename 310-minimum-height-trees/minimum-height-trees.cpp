#include <vector>
#include <queue>

class Solution {
public:
    std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) {
        if (n == 1) return {0};

        // Build adjacency list and degree array
        std::vector<std::vector<int>> adj(n);
        std::vector<int> degree(n, 0);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        // Initialize queue with all leaf nodes (degree 1)
        std::queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        // Trim leaves layer by layer until <= 2 nodes remain
        int remainingNodes = n;
        while (remainingNodes > 2) {
            int leafCount = q.size();
            remainingNodes -= leafCount;

            for (int i = 0; i < leafCount; ++i) {
                int leaf = q.front();
                q.pop();

                for (int neighbor : adj[leaf]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }

        // The remaining nodes are the centroids/roots of MHTs
        std::vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
};