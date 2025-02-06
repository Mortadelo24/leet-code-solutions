class Solution {
public:
    void printState(vector<int>& matrix){
            for (int p : matrix){
                cout << p << " ";
            }        
            cout << endl;
    }
    void printCandidates(vector<pair<int, int>>& candidates){
        for (auto p : candidates){
            cout << p.first << ":" << p.second << " ";
        }
        cout << endl;
    }
   
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix.front().size();
        vector<pair<int,int>> candidates;
        int maxRectangle = 0;
        vector<int> dp(cols, 0);

        for (int i = 0; i < rows; i++){
            candidates.clear();
            for (int j = 0; j < cols; j++){
                dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0; 

                while(!candidates.empty() && dp[candidates.back().first] >= dp[j]) candidates.pop_back();
                int distanceLeft = j  -  (candidates.empty() ? 0 : candidates.back().first + 1);
                candidates.push_back(make_pair(j, dp[j] * distanceLeft));
                
                for (int x = 0; x < candidates.size(); x++){
                    candidates[x].second += dp[candidates[x].first];
                    maxRectangle = max(candidates[x].second, maxRectangle);
                }
                
            }            
        }


        return maxRectangle;
    }
};