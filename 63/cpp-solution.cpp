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

        vector<int> dp(n);
        for (int i = 0; i < n; i++){
            dp[i] = obstacleGrid.front()[i] == 1 ? 0 : 1; 
            if(dp[i] == 0 && m == 1) return 0;
        }
        printState(dp);


        for (int x = 1; x < m; x++){
            for (int y = 0; y < n; y++){
                if (obstacleGrid[x][y] == 1){
                    dp[y] = 0;
                    continue;
                }else if (y == 0){
                    continue;
                }

                dp[y] =  dp[y-1] + dp[y];

                
            }
            printState(dp);
            
        }

        return dp.back();

    }
};