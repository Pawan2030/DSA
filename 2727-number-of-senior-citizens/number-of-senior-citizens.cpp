class Solution {
public:

    int countSeniors(vector<string>& details) {

        int n = details.size();
        int olderAge = 0;

        for(int i=0; i<n; i++){

            string s = details[i];

            char ch1 = s[11];
            char ch2 = s[12];

            string st = "";
            st += ch1;
            st += ch2;

            cout<<ch1 << "  "<<ch2<<endl;

            int age = stoi(st);

            cout<<"AGE ->"<<age<<endl;

            if(age > 60){
                olderAge++;
            }
        }
        return olderAge;
        
    }
};