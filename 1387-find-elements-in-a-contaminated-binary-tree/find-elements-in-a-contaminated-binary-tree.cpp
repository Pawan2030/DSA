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
class FindElements {
public:
    
   unordered_set<int> st;

   void BuildTree(TreeNode* root , int x){
       
       if(!root->left && !root->right) return;

       if(root->left && !root->right){
           int valLeft         = 2*x + 1;
           root->left->val = valLeft;
           st.insert(valLeft);
           BuildTree(root->left , valLeft);
       }
       else if(!root->left && root->right){
           int valRight         = 2*x + 2;
           root->right->val = valRight;
           st.insert(valRight);
           BuildTree(root->right , valRight);
       }
       else{
           int valLeft         = 2*x + 1;
           int valRight        = 2*x + 2;

           root->left->val  = valLeft;
           root->right->val = valRight;
           st.insert(valLeft);
           st.insert(valRight);
           BuildTree(root->left , valLeft);
           BuildTree(root->right , valRight);
       }

   }
    
    FindElements(TreeNode* root) {
        
        int x = 0;
        root->val = x; 
        st.insert(x);
        BuildTree(root , 0);
    }
    
    bool find(int target) {
        return st.find(target) != st.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */