class Solution {
public:
    int lengthLongestPath(string input) {
        stringstream ss(input);
        string line;
        unordered_map<int, int> depthLen;
        int maxLen = 0;

        while (getline(ss, line, '\n')) {
            int depth = 0;
            while (depth < line.size() && line[depth] == '\t') {
                depth++;
            }

            string name = line.substr(depth);
            
            if (name.find('.') != string::npos) {
                int currentLen = (depth > 0 ? depthLen[depth - 1] + 1 : 0) + name.length();
                maxLen = max(maxLen, currentLen);
            } else {
                depthLen[depth] = (depth > 0 ? depthLen[depth - 1] + 1 : 0) + name.length();
            }
        }

        return maxLen;
    }
};