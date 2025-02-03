class Solution {
public:
    bool includesMove(set<pair<int, int>>& state, pair<int, int> move){
        return state.find(move) != state.end();        
    }
    bool solveWord(vector<vector<char>>& board, string& word, set<pair<int, int>>& state, pair<int, int> boardCoordenates, int wordIndex){
        cout << includesMove(state, boardCoordenates) << endl;
       
        for (int i = boardCoordenates.first - 1; i < boardCoordenates.first + 1; i++ ){
            for (int j = boardCoordenates.second - 1; j < boardCoordenates.second + 1; j++){
                cout << i << "|" << j << endl;
                // cout << board[i][j] << " ";
            }
            cout << endl;
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