class Solution {
public:

    int countSeniors(vector<string>& details) {

        int n = details.size();
        int olderAge = 0;

        for(int i=0; i<n; i++){

            string st = "";
            st  +=  details[i][11];
            st  +=  details[i][12];
        
            int age = stoi(st);

            cout<<"AGE ->"<<age<<endl;

            if(age > 60){
                olderAge++;
            }
        }
        return olderAge;
        
    }
};