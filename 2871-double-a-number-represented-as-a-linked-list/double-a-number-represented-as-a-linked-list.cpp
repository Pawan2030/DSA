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
   
   int carry = 0;
   
   int solve(ListNode* head){
        
        if(head == NULL){
            return 0;
        }
        
        solve(head->next);

        int val = (head->val * 2 ) + carry;
        carry = val / 10;

        head->val = val%10;

        return carry;
        
   }
    

    ListNode* doubleIt(ListNode* head) {

        //int carry = 0;
        int carry = solve(head);
        
        ListNode* newHead = NULL;

        if(carry != 0){
            newHead = new ListNode(carry);
            newHead->next = head;
            return newHead;
        } 

        return head;
    }
};