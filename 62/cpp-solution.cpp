class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(m + 1, 1);
        dp[0] = 0;

        for (int i = 1; i < n; i++){
            for (int index = 1; index < dp.size(); index++){
                dp[index] = dp[index] + dp[index-1];
            }
        }

        return dp.back();
    }
};