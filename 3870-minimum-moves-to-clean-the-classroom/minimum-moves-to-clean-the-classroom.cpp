class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int sx = -1, sy = -1;
        vector<pair<int, int>> litter;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                } else if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int numLitter = litter.size();
        if (numLitter == 0) return 0;

        vector<vector<vector<int>>> maxEnergy(m, vector<vector<int>>(n, vector<int>(1 << numLitter, -1)));
        
        queue<tuple<int, int, int, int>> q;
        q.push({sx, sy, 0, energy});
        maxEnergy[sx][sy][0] = energy;

        int steps = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y, mask, e] = q.front();
                q.pop();

                if (mask == (1 << numLitter) - 1) return steps;

                for (auto& d : dirs) {
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && classroom[nx][ny] != 'X') {
                        int ne = e - 1;
                        if (ne < 0) continue;

                        int nmask = mask;
                        if (classroom[nx][ny] == 'L') {
                            for (int i = 0; i < numLitter; ++i) {
                                if (litter[i].first == nx && litter[i].second == ny) {
                                    nmask |= (1 << i);
                                    break;
                                }
                            }
                        } else if (classroom[nx][ny] == 'R') {
                            ne = energy;
                        }

                        if (ne > maxEnergy[nx][ny][nmask]) {
                            maxEnergy[nx][ny][nmask] = ne;
                            q.push({nx, ny, nmask, ne});
                        }
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};