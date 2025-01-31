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
    void generateRow(vector<vector<int>>& matrix, int index){
        for (int i = 0; i < matrix.front().size(); i++){
            matrix[index][i] = 0;
        }
    }
    void generateColumn(vector<vector<int>>& matrix, int index){
        for (int i = 0; i < matrix.size(); i++){
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
        cout << "columns" << endl;
        for (int cIndex : columns){
            generateColumn(matrix, cIndex);
        }
        cout << "rows" << endl;
        for (int rIndex : rows){
            generateRow(matrix, rIndex);
        }
        printState(matrix);
    }
};