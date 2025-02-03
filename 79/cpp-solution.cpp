class Solution {
public:
    bool includesMove(set<pair<int, int>>& state, pair<int, int> move){
        return find(state.begin(), state.end(), move) != state.end();        
    }
    bool solveWord(vector<vector<char>>& board, string& word, stack<pair<int, int>>& state, pair<int, int> boardCoordenates){    
        if (word.size() == state.size()) {
            return true;
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

        for (pair<int, int> tempMove : unCheckedPaths ){
            if (!includesMove(state, tempMove) && board[tempMove.first][tempMove.second] == word[state.size()]) {
                state.push(tempMove);
                if(solveWord(board, word, state, tempMove)) return true;
                state.pop(tempMove);
            }
        }
            
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        stack<pair<int, int>> state;

        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board.front().size(); j++){
                if (board[i][j] == word.front()){
                    state.push({i,j});
                    if (solveWord(board, word, state, {i,j})) return true;
                    state.pop({i,j});
                }
            }
        }

        return false;
    }
};