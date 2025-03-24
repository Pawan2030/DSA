class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days; // If no meetings, all days are free
        
        // Sort meetings by start time, and then by end time if start times are the same
        sort(meetings.begin(), meetings.end());
        
        vector<vector<int>> merged;
        merged.push_back(meetings[0]);
        
        // Merge overlapping and contiguous intervals
        for (int i = 1; i < meetings.size(); ++i) {
            if (meetings[i][0] <= merged.back()[1] + 1) {
                merged.back()[1] = max(merged.back()[1], meetings[i][1]);
            } else {
                merged.push_back(meetings[i]);
            }
        }
        
        int cnt = 0;
        
        // Count free days before the first meeting
        if (merged[0][0] > 1) {
            cnt += (merged[0][0] - 1);
        }
        
        // Count free days between merged intervals
        for (int i = 1; i < merged.size(); ++i) {
            cnt += (merged[i][0] - merged[i-1][1] - 1);
        }
        
        // Count free days after the last meeting
        if (merged.back()[1] < days) {
            cnt += (days - merged.back()[1]);
        }
        
        return cnt;
    }
};
