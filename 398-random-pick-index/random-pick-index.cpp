class Solution {
    unordered_map<int, vector<int>> indices;

public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            indices[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        const auto& target_indices = indices[target];
        int random_pos = rand() % target_indices.size();
        return target_indices[random_pos];
    }
};