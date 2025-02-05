class Solution {
public:
    void printStack(vector<int>& candidates, vector<int>& heights){
        for (int candidate : candidates){
            cout << candidate << ":" << heights[candidate] << "|";
        }
        cout << endl;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> candidates;
        for (int i = 0; i < heights.size(); i++){
            // insert element in stack
            while(!candidates.empty() && heights[candidates.back()] > heights[i]) candidates.pop_back();
            candidates.push_back(i);
            // end
            printStack(candidates, heights);

            int base = heights[candidates.front()];
            int distance = candate.front() - 0;
            cout << base + (distance * base) << endl;

        }
        return 0;
    }
};