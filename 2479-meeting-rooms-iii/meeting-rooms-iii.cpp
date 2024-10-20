class Solution {
public:

    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        sort(begin(meetings) , end(meetings)); // sorting based on starting time of each meeting
        vector<long long> roomRecord(n , 0);
        vector<int> roomUsed(n , 0);

        for(vector<int> &meet : meetings){

            int start   = meet[0];
            int end     = meet[1];
            int duration = end - start;
            bool assign = false;

            long long earlyTime = LLONG_MAX;
            int earlyRoom = -1; 

            for(int room=0; room<n; room++){
               
               if(roomRecord[room] <= start){
                   roomRecord[room] = end;
                   roomUsed[room]++;
                   assign = true;
                   break;
               }

               if(earlyTime > roomRecord[room]){
                   earlyTime = roomRecord[room];
                   earlyRoom = room;
               }

            }

            //if assign = false it means room not present so we need to find early availble room for this meet
            if(!assign){
               roomRecord[earlyRoom] += duration;
               roomUsed[earlyRoom]++;
            }
        }

        int HighestMeetingRoom;
        int prev = -1; // previous room freq;
        
        for(int room=0; room<n; room++){

            if(prev < roomUsed[room]){
               prev = roomUsed[room];
               HighestMeetingRoom = room;
            }
        }

        return HighestMeetingRoom;
    }
};