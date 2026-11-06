class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m_queries = queries.size();
        vector<pair<int, int>> sorted_queries(m_queries);
        for (int i = 0; i < m_queries; ++i) {
            sorted_queries[i] = {queries[i], i};
        }
        sort(sorted_queries.begin(), sorted_queries.end());
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        vector<int> ans(m_queries);
        unordered_map<int, int> server_counts;
        int l = 0, r = 0;
        int total_logs = logs.size();

        for (int i = 0; i < m_queries; ++i) {
            int q_time = sorted_queries[i].first;
            int q_idx = sorted_queries[i].second;
            int start_time = q_time - x;

            while (r < total_logs && logs[r][1] <= q_time) {
                server_counts[logs[r][0]]++;
                r++;
            }

            while (l < total_logs && logs[l][1] < start_time) {
                server_counts[logs[l][0]]--;
                if (server_counts[logs[l][0]] == 0) {
                    server_counts.erase(logs[l][0]);
                }
                l++;
            }

            ans[q_idx] = n - server_counts.size();
        }

        return ans;
    }
};