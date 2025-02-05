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

            for (int j = 0; j < candidates.size(); j++){
                int base = heights[candidates[j]];
                // use start 0 as start index for the first element
                int distance = candidates.back() - (j == 0 ? 0 : candidates[j]);
                cout << base + (distance * base) << endl;
            }
            

        }
        return 0;
    }
};