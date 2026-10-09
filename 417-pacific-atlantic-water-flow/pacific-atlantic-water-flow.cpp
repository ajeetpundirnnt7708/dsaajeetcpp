class Solution {
private:
    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        ocean[r][c] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !ocean[nr][nc]) {
                if (heights[nr][nc] >= heights[r][c]) {
                    dfs(nr, nc, ocean, heights);
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            dfs(i, 0, pacific, heights);
            dfs(i, n - 1, atlantic, heights);
        }

        for (int j = 0; j < n; j++) {
            dfs(0, j, pacific, heights);
            dfs(m - 1, j, atlantic, heights);
        }

        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};