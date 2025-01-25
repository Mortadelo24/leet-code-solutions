class Solution {
public:
   
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid.back().size();

        vector<int> dp(n, 1);

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