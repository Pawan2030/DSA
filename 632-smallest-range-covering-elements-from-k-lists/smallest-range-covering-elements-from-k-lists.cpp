class node{

    public:

    int data;
    int row;
    int col;

    node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class comp{
    public:
    bool operator()(node* a, node* b)
    {
        return a->data > b->data;
    }
    
};


class Solution {
public:

 
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        int n = nums.size();
        priority_queue<node* , vector<node*>, comp> pq;
        
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i=0; i<n; i++)
        {   
            int value = nums[i][0];
            mini = min(mini,value);
            maxi = max(maxi,value);
            node* temp = new node(value,i,0);
            pq.push(temp);
        }

        int s = mini;
        int e = maxi;

        while(!pq.empty())
        {
          node* temp = pq.top();
          pq.pop();

          int val = temp->data;
          int i = temp->row;
          int j = temp->col;

          mini = val;

          if(maxi-mini < e-s)
          {
              s = mini;
              e = maxi;
          }

          if(temp->col + 1 < nums[i].size())
          {
              maxi = max(maxi,nums[i][j+1]);
              pq.push(new node(nums[i][j+1],i,j+1));
          }
          else
          {
              break;
          }

        }

        vector<int> ans;
        ans.push_back(s);
        ans.push_back(e);

        return ans;
        
    }
};