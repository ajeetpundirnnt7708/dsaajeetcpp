class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string current, int open, int close, int max) {
        // Base case: If the current string reaches the maximum length, add it to results
        if (current.length() == max * 2) {
            result.push_back(current);
            return;
        }

        // Rule 1: We can always add an opening parenthesis if we haven't reached the limit 'n'
        if (open < max) {
            backtrack(result, current + "(", open + 1, close, max);
        }

        // Rule 2: We can only add a closing parenthesis if it matches an already open one
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, max);
        }
    }
};
