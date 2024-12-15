class Solution {
public:
    
    #define P pair<double,int>
    //        ->> delta , idx  

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double res = 0.0;
        int n   = classes.size();
        priority_queue<P> pq;

        for(int i=0; i<n; i++){

            double pass  = classes[i][0];
            double total = classes[i][1];

            double delta = (pass+1)/(total+1) - (pass/total);

            pq.push({delta , i});
        }
        
        while(extraStudents--) {
          
            auto top = pq.top();
            pq.pop();

            //double delta = top.first;
            int  idx     = top.second;

            classes[idx][0] += 1;
            classes[idx][1] += 1;

            double pass  = classes[idx][0];
            double total = classes[idx][1];

            double CurrDelta = (pass+1)/(total+1) - (pass/total);

            pq.push({CurrDelta , idx});   
            
            /*
            // Find the class with the most improvement
            for (int i = 0; i < classes.size(); i++) {
                double pass = classes[i][0];
                double total = classes[i][1];

                // Calculate marginal improvement
                double val = ((pass + 1) / (total + 1)) - (pass / total);

                if (val > inct) {
                    inct = val;
                    idx = i;
                }
            } */
        }

        // Compute the final average
        for(int i=0; i<n; i++){

            double pass  = classes[i][0];
            double total = classes[i][1];
            res += (pass/total);
        }

        return res / n;
    }
};
