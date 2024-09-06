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
   
   void solve(ListNode* dummy , unordered_set<int>& st){

      ListNode* prev = dummy;
      ListNode* curr = dummy->next;

      while(curr != NULL){

        if(st.count(curr->val)){
            ListNode* temp = curr->next;
            prev->next = temp;
            curr->next = NULL;
            curr = temp;
        }
        else{
            prev = curr;
            curr = curr->next;
        }
         
      }

   }

    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        unordered_set<int> st;

        for(int num : nums){
           st.insert(num);
        }

        solve(dummy , st);

        return dummy->next;
    }
};