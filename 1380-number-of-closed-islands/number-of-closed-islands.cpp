class Solution {
private:
    bool dfs(int r, int c, vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // If we hit the boundary, this island is NOT closed
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return false;
        }
        
        // If it's water (1) or already visited, return true (doesn't invalidate the path)
        if (grid[r][c] == 1) {
            return true;
        }
        
        // Mark current cell as visited by turning it into water (1)
        grid[r][c] = 1;
        
        // Explore all 4 directions
        bool left = dfs(r, c - 1, grid);
        bool right = dfs(r, c + 1, grid);
        bool up = dfs(r - 1, c, grid);
        bool down = dfs(r + 1, c, grid);
        
        // The component is closed only if all 4 directions are valid (closed)
        return left && right && up && down;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int closedIslandsCount = 0;
        
        // Step 1: Eliminate all land cells connected to the top and bottom borders
        for (int c = 0; c < cols; ++c) {
            if (grid[0][c] == 0) dfs(0, c, grid);
            if (grid[rows - 1][c] == 0) dfs(rows - 1, c, grid);
        }
        
        // Step 2: Eliminate all land cells connected to the left and right borders
        for (int r = 0; r < rows; ++r) {
            if (grid[r][0] == 0) dfs(r, 0, grid);
            if (grid[r][cols - 1] == 0) dfs(r, cols - 1, grid);
        }
        
        // Step 3: Count remaining closed islands in the inner grid
        for (int r = 1; r < rows - 1; ++r) {
            for (int c = 1; c < cols - 1; ++c) {
                if (grid[r][c] == 0) {
                    // If a DFS from this cell is entirely bounded by 1s, it's a closed island
                    if (dfs(r, c, grid)) {
                        closedIslandsCount++;
                    }
                }
            }
        }
        
        return closedIslandsCount;
    }
};