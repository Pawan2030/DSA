class Solution {
public:

    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
          
          int n = seats.size();
          int minMove = 0;

          sort(begin(seats) , end(seats));
          sort(begin(students) , end(students));

          for(int i=0; i<n; i++){
            
            int val = abs(students[i] - seats[i]);
            minMove += val;
          }
          
          return minMove;
    }
};