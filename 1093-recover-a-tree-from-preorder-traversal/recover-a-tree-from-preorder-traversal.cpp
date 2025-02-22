/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        stack<pair<TreeNode*, int>> st;  // Stack stores {node, depth}
        int i = 0, n = s.length();

        while (i < n) {
            int depth = 0;
            
            // Count the number of dashes to determine depth
            while (i < n && s[i] == '-') {
                depth++;
                i++;
            }

            // Extract the node value
            int value = 0;
            while (i < n && isdigit(s[i])) {
                value = value * 10 + (s[i] - '0');
                i++;
            }

            // Create a new node
            TreeNode* node = new TreeNode(value);

            // Maintain correct tree structure
            while (!st.empty() && st.top().second >= depth) {
                st.pop(); // Ensure parent-child relationship is correct
            }

            // Attach the node to its parent
            if (!st.empty()) {
                if (st.top().first->left == nullptr) {
                    st.top().first->left = node;
                } else {
                    st.top().first->right = node;
                }
            }

            // Push the new node with its depth onto the stack
            st.push({node, depth});
        }

        // The root is at the bottom of the stack
        while (st.size() > 1) {
            st.pop();
        }
        
        return st.top().first;
    }
};
