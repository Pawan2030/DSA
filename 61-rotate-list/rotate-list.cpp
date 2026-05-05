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
        

        if(!head) return NULL;
        
        int n = 1;
        ListNode* tail = head;

        while(tail->next != NULL){
            tail = tail->next;
            n++;
        }

        tail->next = head;
        n = n-(k%n);

        int cnt = 1;


        while(cnt < n){
           head = head->next;
           cnt++;
        }

        ListNode* newHead = head->next;
        head->next = NULL;
        return newHead;

    }
};