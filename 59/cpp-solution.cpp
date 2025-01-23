class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector(n, 0));
        int counter = 1;

        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right  = n -1;

        while (top <= bottom && left <= right){
            for (int y = left; y <= right; y++){
                matrix[top][y] = counter++;
            }
            top++;

            for (int x = top; x <= bottom; x++){
                matrix[x][right] = counter++;
            }
            right--;

            for (int y = right; y >= left; y--){
                matrix[bottom][y] = counter++;
            }
            bottom--;

            for (int x = bottom; x >= top; x--){
                matrix[x][left] = counter++;
            }
            left++;
        }


        return matrix;
    }
};