class Solution {
public:
    int getItem(vector<vector<int>>& matrix, int virtualIndex){
        int n = matrix.front().size();
        cout << virtualIndex / n << "|" << virtualIndex%n << endl;
        
        return 0;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size() + matrix.front().size(); i++){
            getItem(matrix, i);
        }
        return false;
    }
};