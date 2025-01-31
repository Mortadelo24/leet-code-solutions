class Solution {
public:
    void printState(vector<vector<int>>& matrix){
        for (vector<int> row : matrix){
            for (int i : row){
                cout << i << " ";
            }
            cout << endl;
        }
    }
    void generateRow(vector<vector<int>>& matrix, int index, int start = 0){
        for (int i = start; i < matrix.front().size(); i++){
            if (matrix[0][i] == 2) continue;
            matrix[index][i] = 0;
        }
    }
    void generateColumn(vector<vector<int>>& matrix, int index, int start = 0){
        for (int i = start; i < matrix.size(); i++){
            if (matrix[i][0] == 2) continue;
            matrix[i][index] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++ ){
            for(int j = 0; j < matrix.front().size(); j++){
                if (matrix[i][j] == 0){
                    matrix[i][0] = 2;
                    generateRow(matrix, i, j);
                    matrix[0][j] = 2;
                    generateColumn(matrix, j, i );
                }
            }
        }
        printState(matrix);
    }
};