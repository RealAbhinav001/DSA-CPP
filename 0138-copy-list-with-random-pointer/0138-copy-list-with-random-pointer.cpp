/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        // STEP 1: har original ke baad uska clone ghusao
        // 1 -> 1' -> 2 -> 2' -> 3 -> 3'
        Node* curr = head;
        while (curr != NULL) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // STEP 2: clone ka random set karo
        // clone (curr->next) ka random = original ke random ka clone (curr->random->next)
        curr = head;
        while (curr != NULL) {
            if (curr->random != NULL)
                curr->next->random = curr->random->next;
            else
                curr->next->random = NULL;
            curr = curr->next->next;
        }

        // STEP 3: dono lists alag karo (original restore + clone nikalo)
        Node* dummy = new Node(-1);
        Node* copyTail = dummy;
        curr = head;
        while (curr != NULL) {
            Node* copy = curr->next;
            curr->next = copy->next;   // original ka next wapas
            copyTail->next = copy;     // clone ko clone-list mein
            copyTail = copy;
            curr = curr->next;
        }
        return dummy->next;
    }
};