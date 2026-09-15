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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;   // empty/single → waise return
        int count = 1;
        ListNode*temp = head;
        while(temp->next !=NULL){
            temp = temp->next;
            count++;
        }

        k = k % count;
        temp->next = head;
        int len = count - k-1;
        ListNode*m = head;

        for(int i=0;i<len;i++){
            m = m->next;
        }

        ListNode*newHead = m->next;
        m->next = NULL;
        return newHead;
    }
};