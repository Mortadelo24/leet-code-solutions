class Solution {
public:
    void printState(vector<vector<int>>& matrix){
        for (vector<int> row : matrix){
            for (int i : row){
                cout << i << " ";
            }
            cout << endl;
        }
        cout << endl;
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
        set<int> columns;
        set<int> rows;
        for (int i = 0; i < matrix.size(); i++ ){
            for(int j = 0; j < matrix.front().size(); j++){
                if (matrix[i][j] == 0){
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }
        for (auto c : columns){
            cout << c << endl;
        }
        for (auto c : rows){
            cout << c << endl;
        }
        printState(matrix);
    }
};