/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    void solve(Node* root , vector<int>& arr){
        
      if(!root){
        return;
      }

      for(auto node : root->children){
         solve(node , arr);
      }

      arr.push_back(root->val);

    }

    vector<int> postorder(Node* root) {
       
      
       vector<int> arr;
       solve(root , arr);
       return arr;  
    }
};