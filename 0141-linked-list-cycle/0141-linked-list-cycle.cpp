/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*Fast = head;
        ListNode*Slow = head;

        while(Fast !=NULL && Fast->next !=NULL){
            Slow = Slow->next;
            Fast = Fast->next->next;

            if(Slow == Fast){
                return true;
            }
        }
        return false;
    }
};