class Solution {
public:
    int getItem(vector<vector<int>>& matrix, int virtualIndex){
        int n = matrix.front().size();
        return matrix[floor( virtualIndex / n)][virtualIndex%n];
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i <= matrix.size() + matrix.front().size(); i++){
            cout <<  getItem(matrix, i) << endl;
        }
        return false;
    }
};