class Solution {
public:
    void printState(vector<vector<pair<int,int>>>& matrix){
        for (vector<pair<int,int>> row : matrix) {
            for (pair<int,int> p : row){
                cout << p.first << " ";
            }
            cout << endl;
        }
        cout << string(matrix.front().size() * 2, '-') << endl;
        for (vector<pair<int,int>> row : matrix) {
            for (pair<int,int> p : row){
                cout << p.second << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix.front().size();
        vector<vector<pair<int, int>>> dp(rows, vector(cols, make_pair(0, 0)));
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                dp[i][j].first = matrix[i][j] == '1' ? 1 : 0;
                if (dp[i][j].first == 0) continue;
                if (j != 0) dp[i][j].first += dp[i][j-1].first;
                
                if (dp[i][j].first == 0) continue;
                dp[i][j].second = 1;
                if (i == 0) continue;
                if (dp[i-1][j].first != 0 ){
                    dp[i][j].second += dp[i-1][j].second;
                }
            
            }
        }
        printState(dp);


        return 0;
    }
};