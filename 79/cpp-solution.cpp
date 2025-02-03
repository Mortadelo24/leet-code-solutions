class Solution {
public:
    bool includesMove(set<pair<int, int>>& state, pair<int, int> move){
        return state.find(move) != state.end();        
    }
    bool solveWord(vector<vector<char>>& board, string& word, set<pair<int, int>>& state, pair<int, int> boardCoordenates, int wordIndex){
        cout << includesMove(state, boardCoordenates) << endl;
        int offSetX = 0;
        int offSetY = 0;
        for (int i = offSetX; i < offSetX + 3; i++ ){
            for (int j = offSetY; j < offSetY + 3; j++){
                cout << board[i][j] << endl;
            }
        }

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board.front().size(); j++){
                if (board[i][j] == word.front()){
                    set<pair<int, int>> state;
                    state.insert({i,j});
                    solveWord(board, word, state, {i,j},  1);
                }
            }
        }

        return false;
    }
};