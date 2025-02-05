class Solution {
public:
    void printStack(stack<int> candidates){
        while(!candidates.empty()){
            cout << candidates.top() << ",";
            candidates.pop();
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        stack<int> candidates;
        for (int i = 0; i < heights.size(); i++){
            while(!candidates.empty() && heights[candidates.top()] < heights[i]) candidates.pop();
            candidates.push(i);
        }
        printStack(candidates);
        return 0;
    }
};