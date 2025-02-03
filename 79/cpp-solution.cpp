class Solution {
public:
    bool includesMove(set<pair<int, int>>& state, pair<int, int> move){
        return state.find(move) != state.end();        
    }
    bool solveWord(vector<vector<char>>& board, string& word, set<pair<int, int>>& state, pair<int, int> boardCoordenates, int wordIndex){    
        if (word.size() == state.size()) {
            cout << "anAnswer" << endl;
        }
        set<pair<int, int>> unCheckedPaths;
        pair<int, int> newPath;
        if (boardCoordenates.first > 0){
            newPath = boardCoordenates;
            newPath.first--;
            unCheckedPaths.insert(newPath);
        }
        if (boardCoordenates.second > 0){
            newPath = boardCoordenates;
            newPath.second--;
            unCheckedPaths.insert(newPath);
        }
        if (boardCoordenates.first < board.size() - 1){
            newPath = boardCoordenates;
            newPath.first++;
            unCheckedPaths.insert(newPath);
        }
        if (boardCoordenates.second < board.front().size() - 1){
            newPath = boardCoordenates;
            newPath.second++;
            unCheckedPaths.insert(newPath);
        }

        cout << "Moves" << endl;
        for (pair<int, int> tempMove : unCheckedPaths ){
            cout << tempMove.first << "|" << tempMove.second << endl;
            continue;
            if (!includesMove(state, tempMove) && board[tempMove.first][tempMove.second] == word[wordIndex]) {
                state.insert(tempMove);
                solveWord(board, word, state, tempMove, wordIndex + 1);
                state.erase(tempMove);
            }
        }
            


        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        set<pair<int, int>> state;

        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board.front().size(); j++){
                if (board[i][j] == word.front()){
                    state.insert({i,j});
                    solveWord(board, word, state, {i,j},  1);
                    state.erase({i,j});
                }
            }
        }

        return false;
    }
};