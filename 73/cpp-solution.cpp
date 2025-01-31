class Solution {
public:
    void printState(vector<vector<auto>>& matrix){
        for (vector<auto> row : matrix){
            for (auto i : row){
                cout << i << " ";
            }
            cout << endl;
        }
    }
    void generateRow(vector<vector<int>>& matrix, int index){
        for (int i = 0; i < matrix.front().size(); i++){
            matrix[0][i] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++ ){
            for(int j = 0; j < matrix.front().size(); j++){
                if (matrix[i][j] == 0){
                    generateRow(matrix, i);
                }
            }
        }
        printState(matrix);
    }
};