class Solution {
public:
    inline int getItem(vector<vector<int>>& matrix, int n,  int virtualIndex){
        return matrix[floor( virtualIndex / n)][virtualIndex%n];
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.front().size();
        for (int i = 0; i < matrix.size() * n; i++){
            cout << getItem(matrix,n, i) << endl;
        }
        return false;
    }
};