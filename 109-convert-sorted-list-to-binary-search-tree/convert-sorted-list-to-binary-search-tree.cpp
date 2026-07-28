class Solution {
private:
    TreeNode* buildBST(ListNode* head, ListNode* tail) {
        if (head == tail) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode* root = new TreeNode(slow->val);
        root->left = buildBST(head, slow);
        root->right = buildBST(slow->next, tail);

        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        return buildBST(head, nullptr);
    }
};