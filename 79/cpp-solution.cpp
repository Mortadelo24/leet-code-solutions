class Solution {
public:
    bool solveWord(vector<vector<char>>& board, string& word, stack<pair<int, int>>& members, pair<int, int> coordenates){

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board.front().size(); j++){
                if (board[i][j] == word.front()){
                    stack<pair<int, int>> members;
                    solveWord(board, word, members, {i,j});
                }
            }
        }

        return false;
    }
};