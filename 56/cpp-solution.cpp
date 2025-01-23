class Solution {
public:
    vector<int> combine(vector<int>& a, vector<int>& b){
        return {min(a[0], b[0]), max(a[1], b[1])};
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> newIntervals;
        
        vector<int> interval = intervals[0];

        for(int i = 1; i < intervals.size(); i++){
            
            if (interval[1] >=  intervals[i][0]){
                interval = combine(interval, intervals[i]);
            }else {
                newIntervals.push_back(interval);
                interval = intervals[i];
            }

            if (i == intervals.size()-1){
                newIntervals.push_back(interval);
            }
        }
            
        

        return newIntervals;
    }
};