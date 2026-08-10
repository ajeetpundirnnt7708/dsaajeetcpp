class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        
        auto getNext = [&](int i) {
            return ((i + nums[i]) % n + n) % n;
        };
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
            
            int slow = i, fast = i;
            bool forward = nums[i] > 0;
            
            while (true) {
                int nextSlow = getNext(slow);
                if ((nums[nextSlow] > 0) != forward || nums[nextSlow] == 0) break;
                
                int nextFast = getNext(fast);
                if ((nums[nextFast] > 0) != forward || nums[nextFast] == 0) break;
                
                int nextFast2 = getNext(nextFast);
                if ((nums[nextFast2] > 0) != forward || nums[nextFast2] == 0) break;
                
                slow = nextSlow;
                fast = nextFast2;
                
                if (slow == fast) {
                    if (slow == getNext(slow)) break;
                    return true;
                }
            }
            
            int curr = i;
            while (nums[curr] != 0 && (nums[curr] > 0) == forward) {
                int next = getNext(curr);
                nums[curr] = 0;
                curr = next;
            }
        }
        
        return false;
    }
};