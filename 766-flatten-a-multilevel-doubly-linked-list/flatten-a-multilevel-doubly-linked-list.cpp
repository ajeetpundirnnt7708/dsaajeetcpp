/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;

        Node* curr = head;
        while (curr) {
            if (curr->child) {
                Node* nextNode = curr->next;
                Node* childNode = curr->child;

                curr->next = childNode;
                childNode->prev = curr;
                curr->child = nullptr;

                Node* tail = childNode;
                while (tail->next) {
                    tail = tail->next;
                }

                tail->next = nextNode;
                if (nextNode) {
                    nextNode->prev = tail;
                }
            }
            curr = curr->next;
        }

        return head;
    }
};