class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.back().back() == 1) return 0;

        int m = obstacleGrid.size();
        int n = obstacleGrid.back().size();

        vector<int> dp(n);
        bool isThereAnObstacle = false;
        // map the first state of the dp variable in order to start identify any obstacle
        for (int i = 0; i < n; i++){
            isThereAnObstacle = isThereAnObstacle || obstacleGrid.front()[i] == 1;

            dp[i] = isThereAnObstacle ? 0 : 1; 

        }

        for (int x = 1; x < m; x++){
            for (int y = 0; y < n; y++){
                if (obstacleGrid[x][y] == 1){
                    // in case there is an obstacle in the cell
                    dp[y] = 0;
                    continue;
                }else if (y == 0){
                    // in case it is the first of the row
                    continue;
                }

                dp[y] =  dp[y-1] + dp[y];
                
            }            
        }

        return dp.back();

    }
};