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
    
    int sizeOfList(ListNode* head){

        ListNode* temp = head;
        int cnt = 0;

        while(temp){
            temp = temp->next;
            cnt += 1;
        }

        return cnt;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        
        // head is null
        if(head == NULL || k == 0) return head;
        //if k == size of linklist return head
        int n = sizeOfList(head);
        if(n == k) return head;

        //if rotation k > n
        k = k % n;

        if(k == 0) return head;

        int cnt = 1;
        int num = n-k;
        ListNode* temp = head;

        while(cnt < num){
           temp = temp->next;
           cnt += 1;
        }

        ListNode* newHead = temp->next;
        temp->next = NULL;

        ListNode* t = newHead;

        while(t->next != NULL){
            t = t->next;
        }

        t->next = head;
        return newHead;
    }
};