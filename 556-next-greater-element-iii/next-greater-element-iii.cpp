#include <string>
#include <algorithm>

class Solution {
public:
    int nextGreaterElement(int n) {
        std::string s = std::to_string(n);
        int len = s.length();
        
        int i = len - 2;
        while (i >= 0 && s[i] >= s[i + 1]) {
            i--;
        }
        
        if (i < 0) return -1;
        
        int j = len - 1;
        while (s[j] <= s[i]) {
            j--;
        }
        
        std::swap(s[i], s[j]);
        std::reverse(s.begin() + i + 1, s.end());
        
        long long res = std::stoll(s);
        return res > INT_MAX ? -1 : res;
    }
};