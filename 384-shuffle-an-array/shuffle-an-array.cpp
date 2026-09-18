#include <vector>
#include <cstdlib>

class Solution {
private:
    std::vector<int> original;
    std::vector<int> array;

public:
    Solution(std::vector<int>& nums) {
        original = nums;
        array = nums;
    }
    
    std::vector<int> reset() {
        array = original;
        return array;
    }
    
    std::vector<int> shuffle() {
        int n = array.size();
        for (int i = 0; i < n; ++i) {
            int randIdx = i + rand() % (n - i);
            std::swap(array[i], array[randIdx]);
        }
        return array;
    }
};