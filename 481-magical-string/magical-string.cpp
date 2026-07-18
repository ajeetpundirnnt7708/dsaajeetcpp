class Solution {
public:
    int magicalString(int n) {
        if (n <= 0) return 0;
        if (n <= 3) return 1;
        
        vector<int> s = {1, 2, 2};
        int head = 2;
        int tail = 3;
        int countOnes = 1;
        
        while (tail < n) {
            int nextNum = (s[tail - 1] == 1) ? 2 : 1;
            
            for (int i = 0; i < s[head]; ++i) {
                if (tail < n) {
                    s.push_back(nextNum);
                    if (nextNum == 1) {
                        countOnes++;
                    }
                    tail++;
                }
            }
            head++;
        }
        
        return countOnes;
    }
};