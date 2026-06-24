class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Handle empty list or single element list with no loop
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        // Move fast by two steps and slow by one step
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            // If they meet, a cycle exists
            if (slow == fast) {
                return true;
            }
        }
        
        
        return false;
    }
};
