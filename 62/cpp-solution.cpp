class Solution {
public:
    int uniquePaths(int m, int n) {
        stack<pair<int,int>> remainer;
        int uniquePaths = 0;

        remainer.push({0,0});

        while (!remainer.empty()){
            pair<int, int> currentCoordenates = remainer.top();
            remainer.pop();

            if (currentCoordenates.first < m - 1){
                remainer.push({currentCoordenates.first + 1, currentCoordenates.second});
            }
            if (currentCoordenates.second < n - 1){
                remainer.push({currentCoordenates.first, currentCoordenates.second + 1});
            }
            if (currentCoordenates.first >= m-1 && currentCoordenates.second >= n-1){
                uniquePaths++;
            }
        }

        return uniquePaths;
    }
};