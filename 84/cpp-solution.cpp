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
        vector<int> results;
        int answer = 0;
        for (int i = 0; i < heights.size(); i++){
            // insert element in stack
            while(!candidates.empty() && heights[candidates.back()] >= heights[i]) {
                candidates.pop_back();
                results.pop_back();
            }
            int distanceLeft = i  -  (results.empty() ? 0 : candidates.back() + 1);
            results.push_back(heights[i] * ( distanceLeft ) );
            candidates.push_back(i);
            // end 
            
            // printStack(candidates, heights);

            for (int j = 0; j < candidates.size(); j++){
                int base = heights[candidates[j]];
                results[j] += base;
                answer = max(answer, results[j]);
            }
        }
        return answer;
    }
};