class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> arr(2, -1); // Initializing result vector with -1

        if(!head || !head->next || !head->next->next) return arr; // Check if the list has fewer than 3 nodes

        ListNode* temp = head->next;
        ListNode* prev = head;
        int first_cp = -1; // To store the position of the first critical point
        int last_cp = -1; // To store the position of the last critical point
        int min_dist = INT_MAX; // To store the minimum distance between critical points

        int cnt = 1; // Position counter (1-based index)

        while(temp->next != NULL) {
            cnt++;
            ListNode* next = temp->next;

            // Check for critical point
            if((temp->val > prev->val && temp->val > next->val) || (temp->val < prev->val && temp->val < next->val)) {
                if(first_cp == -1) {
                    first_cp = cnt;
                } else {
                    min_dist = min(min_dist, cnt - last_cp); // Update the minimum distance
                }
                last_cp = cnt; // Update the last critical point
            }

            prev = temp;
            temp = next;
        }

        // If there were fewer than two critical points, return [-1, -1]
        if(first_cp == last_cp) {
            return arr;
        }

        // Calculate the maximum distance between the first and last critical points
        int max_dist = last_cp - first_cp;

        arr[0] = min_dist;
        arr[1] = max_dist;

        return arr;
    }
};
