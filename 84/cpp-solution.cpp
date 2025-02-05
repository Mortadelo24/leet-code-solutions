class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> candidates;
        for (int i = 0; i < heights.size(); i++){
            while(!candidates.empty() && heights[candidates.top()] < heights[i]) candidates.pop();
            candidates.push(i);
        }
        return 0;
    }
};