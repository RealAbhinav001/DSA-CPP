/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*dummy = new ListNode(-1);
        dummy->next = head;

        ListNode*Fast = dummy;
        ListNode*Slow = dummy;

        for(int i=0;i<n;i++){
            Fast = Fast->next;
        }

        while(Fast->next !=NULL){
            Slow = Slow->next;
            Fast = Fast->next;
        }

        Slow->next = Slow->next->next;

        return dummy->next;
    }
};