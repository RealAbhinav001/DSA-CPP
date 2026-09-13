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
    int getLength(ListNode*head){
            int count = 0;
            ListNode*temp = head;

            while(temp !=NULL){
                count++;
                temp = temp->next;
            }
            return count;
        }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int lenA = getLength(headA);
        int lenB = getLength(headB);
        int diff = abs(lenA - lenB);

        if(lenA>lenB){
            for(int i=0;i<diff;i++){
                headA = headA->next;
            }
        }
        if(lenB>lenA){
            for(int i=0;i<diff;i++){
                headB = headB->next;
            }
        }

        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }

        return headA;

    }
};