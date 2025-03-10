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
     
    ListNode* solve(ListNode* head, int k , int cnt){
        
        if(cnt < k){  
            return head;
        }

        ListNode* curr = head;
        ListNode* prev = NULL;
        int t = k;

        while(t--){

            ListNode* nt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nt;
        }

        ListNode* conn = solve(curr  , k , cnt-k);
    
        head->next = conn;
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* prev = NULL;
        int cnt = 0;
        
         ListNode* temp = head;

        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        
        return solve(head , k , cnt);
    }
};