class Solution {
private:
    double dfs(const string& src, const string& dst, unordered_set<string>& visited, unordered_map<string, unordered_map<string, double>>& graph) {
        if (graph.find(src) == graph.end() || graph.find(dst) == graph.end()) {
            return -1.0;
        }
        if (src == dst) {
            return 1.0;
        }

        visited.insert(src);

        for (const auto& neighbor : graph[src]) {
            const string& nextNode = neighbor.first;
            double weight = neighbor.second;

            if (visited.find(nextNode) == visited.end()) {
                double res = dfs(nextNode, dst, visited, graph);
                if (res != -1.0) {
                    return weight * res;
                }
            }
        }

        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;

        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            graph[u][v] = val;
            graph[v][u] = 1.0 / val;
        }

        vector<double> results;
        for (const auto& query : queries) {
            string src = query[0];
            string dst = query[1];
            unordered_set<string> visited;
            results.push_back(dfs(src, dst, visited, graph));
        }

        return results;
    }
};