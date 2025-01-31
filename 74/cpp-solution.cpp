class Solution {
public:
    inline int getItem(vector<vector<int>>& matrix, int n,  int virtualIndex){
        return matrix[floor( virtualIndex / n)][virtualIndex%n];
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.front().size();
        int left = 0;
        int right = (matrix.size() * n) - 1;

        while(left < right){
            int midIndex = floor( (left+right)/2 );
            int mid = getItem(matrix, n, midIndex);
            if (mid < target){
                left = midIndex + 1;
            } else if (mid > target){
                right = midIndex - 1;
            } else return true;
        }

      
        return false;
    }
};