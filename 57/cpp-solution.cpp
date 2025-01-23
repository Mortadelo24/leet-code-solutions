// NOTE: I did not read the NOTE from this problem, so  i did a mess trying to implement it as a in-place solution :/

class Solution {
public:
    inline vector<int> combine(vector<int> a, vector<int> b){
        return {min(a[0], b[0]) , max(a[1], b[1])};
    }

    int getIndex(vector<vector<int>>& intervals, int target, int left, int right){
        int middle = floor(float(left+right)/2);

        if (middle < 0) {
            return 0;
        }else if (middle > intervals.size()-1){
            return intervals.size()-1;
        }else if (left >= right){
            return middle;
        }

        if (intervals[middle][0] > target){
            return getIndex(intervals, target, left, middle-1);
        }
        if (intervals[middle][1] < target){
            return getIndex(intervals, target, middle+1, right);
        }
        
        return middle;
    }
  
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty() || intervals[0][0] > newInterval[1]){
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        int start = getIndex(intervals, newInterval[0], 0, intervals.size() -1 ); 
        int end = getIndex(intervals, newInterval[1], start, intervals.size() -1 ); 

        if (intervals[start][1] < newInterval[0]){
            start++;
        }
        if (newInterval[1] < intervals[end][0]){
            end--;
        }

        if (end >= start) {
            if (intervals[start][1] >= newInterval[0]){
                newInterval = combine(newInterval, intervals[start]);
            }
            if (newInterval[1] >= intervals[end][0]){
                newInterval = combine(newInterval, intervals[end]);
            }

            intervals.erase(intervals.begin() + start, intervals.begin()+ end + 1);

        }


        intervals.insert(intervals.begin() + start, newInterval);

        return intervals;

    }

};