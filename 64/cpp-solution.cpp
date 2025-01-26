class Solution {
public:
    void printState(vector<int>& state){
        for (int a : state){
            cout << a  << " | ";
        }
        cout << endl;
    }

    int minPathSum(vector<vector<int>>& grid) {
        vector<int> dp = vector(grid.front());

        return dp.back();
    }
};