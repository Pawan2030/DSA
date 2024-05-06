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
    ListNode* removeNodes(ListNode* head) {

        stack<ListNode*> st;

        ListNode* curr = head;

        while(curr != NULL){
            st.push(curr);
            curr = curr->next;
        }

        ListNode* top = st.top();
        st.pop();

        int maxi = top->val;

        ListNode* newHead = new ListNode(maxi);

        while(!st.empty()){

            ListNode* temp = st.top();
            st.pop();

            if(temp->val < maxi){
                continue;
            }
            else{
                ListNode* newtemp = new ListNode(temp->val);
                newtemp->next = newHead;
                newHead = newtemp;
                maxi = temp->val;
            }

        }
        return newHead;
    }
};