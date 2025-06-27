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
    ListNode* oddEvenList(ListNode* head) {
        
        if(!head) return NULL;

        ListNode* curr = head;
        int count = 1;

        while(curr->next){
            count++;
            curr = curr->next;
        }

        if(count == 1 || count == 2) return head;

        cout<<"count- "<<count<<endl;

        ListNode* head2 = curr;
        ListNode* prev;
        int idx = 1;
        curr = head;

        while(idx <= count){
            
            cout<<"curr- "<<curr->val<<" "<<"idx- "<<idx<<endl;
            if(idx%2 == 0){
                ListNode* temp1 = curr;
                ListNode* temp2 = curr->next;
                prev->next = curr->next;
                curr->next = NULL;
                curr = temp2;
                head2->next = temp1;
                head2 = head2->next;
            }
            else{
                prev = curr;
                curr = curr->next;
            }

            idx++;
        }
        return head;
    }
};