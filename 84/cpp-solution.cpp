class Solution {
public:
    void printStack(stack<int> candidates){
        while(!candidates.empty()){
            cout << candidates.top() << ",";
            candidates.pop();
        }
        cout << endl;
    }
    int largestRectangleArea(vector<int>& heights) {
        stack<int> candidates;
        for (int i = 0; i < heights.size(); i++){
            // insert element in stack
            while(!candidates.empty() && heights[candidates.top()] > heights[i]) candidates.pop();
            candidates.push(i);
            // end

            printStack(candidates);

        }
        return 0;
    }
};