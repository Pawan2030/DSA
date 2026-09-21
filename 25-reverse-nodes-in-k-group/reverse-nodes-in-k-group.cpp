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

     bool lessThanKNodeLeft(ListNode* head, int k){

        int cnt = 1;

        ListNode* t = head;

        while(t != NULL){
            t = t->next;

            if(t != NULL)
             cnt++;

            if(cnt >= k) return false;
        }

        return true;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        if(!head || lessThanKNodeLeft(head , k)){
            return head;
        }

        int count = 0;
        ListNode* tail = head;
        ListNode* prev = NULL;

        while(count < k){

            ListNode* tempNext = head->next;
            head->next = prev;
            prev = head;
            head = tempNext;
            count++;
        }

        tail->next = reverseKGroup(head , k);
        return prev;
    }
};