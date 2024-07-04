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
  
    ListNode* insert(vector<int>& arr)
    {
        ListNode* dummy = new ListNode(-1);
         ListNode* temp =  dummy;

        for(int i=0;i<arr.size();i++)
        {
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
            
        }

        return dummy->next;
    }
    
    ListNode* mergeNodes(ListNode* head) {
    
       int sum = 0;
       vector<int> arr;
       ListNode* temp = head;

       while(temp != NULL)
       {
           sum = sum + temp->val;
           temp = temp->next;

           if(temp != NULL && temp->val == 0)
           {
               arr.push_back(sum);
               sum = 0;
           }
       } 

        ListNode* ans = insert(arr);

        return ans;
        
    }
};