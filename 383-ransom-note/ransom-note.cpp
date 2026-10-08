#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.length() > magazine.length()) {
            return false;
        }

        vector<int> counts(26, 0);

        for (char c : magazine) {
            counts[c - 'a']++;
        }

        for (char c : ransomNote) {
            if (--counts[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};
