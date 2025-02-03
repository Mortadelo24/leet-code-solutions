class Solution {
public:
    bool solveWord(vector<vector<char>>& board, string& word, stack<pair<int, int>>& state){

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board.front().size(); j++){
                if (board[i][j] == word.front()){
                    stack<pair<int, int>> state;
                    state.push({i, j});
                    solveWord(board, word, state);
                }
            }
        }

        return false;
    }
};