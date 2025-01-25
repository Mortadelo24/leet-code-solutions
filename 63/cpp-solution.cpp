class Solution {
public:
   void printState(vector<int>& dp){
        for (int a : dp) {
            cout << a << " |";
        }
        cout << endl;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1 || obstacleGrid.back().back() == 1) return 0;
        
        int m = obstacleGrid.size();
        int n = obstacleGrid.back().size();

        vector<int> dp(n, 0);

        for (int x = 0; x < m; x++){
            for (int y = 0; y < n; y++){
                if (obstacleGrid[x][y] == 1){
                    dp[y] = 0;
                    continue;
                }

                if (y == 0 || x == 0) {
                    dp[y] = 1;
                    continue;
                }

                dp[y] = dp[y] + dp[y-1];

                
            }
            
        }

        return dp.back();

    }
};