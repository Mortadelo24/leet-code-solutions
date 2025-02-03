class Solution {
public:
    bool includesMove(set<pair<int, int>>& state, pair<int, int> move){

        return false;        
    }
    bool solveWord(vector<vector<char>>& board, string& word, set<pair<int, int>>& state, pair<int, int>& boardCoordenates, int wordIndex){
        cout << includesMove(state, boardCoordenates);


        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board.front().size(); j++){
                if (board[i][j] == word.front()){
                    set<pair<int, int>> state;
                    pair<int, int> coordenates = {i,j};
                    state.insert(coordenates);
                    solveWord(board, word, state, coordenates,  1);
                }
            }
        }

        return false;
    }
};