class Solution {
public:
    bool includesMove(set<pair<int, int>>& state, pair<int, int> move){
        return state.find(move) != state.end();        
    }
    bool solveWord(vector<vector<char>>& board, string& word, set<pair<int, int>>& state, pair<int, int> boardCoordenates, int wordIndex){
        cout << includesMove(state, boardCoordenates) << endl;
       
        for (int i = boardCoordenates.first == 0 ? 0 : boardCoordenates.first  - 1; i <= boardCoordenates.first + 1 && i < board.size(); i++ ){
            for (int j = boardCoordenates.second == 0 ? 0 : boardCoordenates.second  - 1; j <= boardCoordenates.second + 1 && j < board.front().size(); j++){
                pair<int, int> tempMove = {i,j};
                if (tempMove == boardCoordenates) continue;
                if (!includesMove(state, tempMove) && board[i][j] == word[wordIndex]) {
                    state.insert(tempMove);
                    state.erase(tempMove);
                }
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
                    state.erase({i,j});
                }
            }
        }
        cout << state.size() << endl;

        return false;
    }
};