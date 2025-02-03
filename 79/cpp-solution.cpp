class Solution {
public:
    bool solveWord(vector<vector<char>>& board, string& word, unordered_set<pair<int, int>>& members){
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board.front().size(); j++){
                if (board[i][j] == word.front()){
                    unordered_set<pair<int, int>> members;
                    solveWord(board, word, members);
                }
            }
        }

        return false;
    }
};