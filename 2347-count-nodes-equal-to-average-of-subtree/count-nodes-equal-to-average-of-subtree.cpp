class Solution {
private:
    int matchingCount = 0;

    // Returns {sum of subtree, count of nodes in subtree}
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int totalSum = left.first + right.first + root->val;
        int totalCount = left.second + right.second + 1;

        if (totalSum / totalCount == root->val) {
            matchingCount++;
        }

        return {totalSum, totalCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return matchingCount;
    }
};