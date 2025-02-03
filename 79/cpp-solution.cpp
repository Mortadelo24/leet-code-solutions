class Solution {
public:
    bool includesMove(set<pair<int, int>>& state, pair<int, int> move){
        
    }
    bool solveWord(vector<vector<char>>& board, string& word, set<pair<int, int>>& state, int wordIndex){
        for ()



        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board.front().size(); j++){
                if (board[i][j] == word.front()){
                    set<pair<int, int>> state;
                    state.insert({i, j});
                    solveWord(board, word, state, 1);
                }
            }
        }

        return false;
    }
};