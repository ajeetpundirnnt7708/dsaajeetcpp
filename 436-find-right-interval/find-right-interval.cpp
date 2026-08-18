#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> findRightInterval(std::vector<std::vector<int>>& intervals) {
        int n = intervals.size();
        std::vector<std::pair<int, int>> starts(n);
        
        
        for (int i = 0; i < n; ++i) {
            starts[i] = {intervals[i][0], i};
        }
        
       
        std::sort(starts.begin(), starts.end());
        
        std::vector<int> result(n, -1);
        
       
        for (int i = 0; i < n; ++i) {
            int end_i = intervals[i][1];
            
            
            auto it = std::lower_bound(starts.begin(), starts.end(), std::make_pair(end_i, -1));
            
            if (it != starts.end()) {
                result[i] = it->second;
            }
        }
        
        return result;
    }
};