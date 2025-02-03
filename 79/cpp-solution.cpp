class Solution {
public:
    bool includesMove(vector<pair<int, int>>& state, pair<int, int> move){
        return find(state.begin(), state.end(), move) != state.end();        
    }
    bool solveWord(vector<vector<char>>& board, string& word, vector<pair<int, int>>& state){    
        if (word.size() == state.size()) {
            return true;
        }
        set<pair<int, int>> unCheckedPaths;
        pair<int, int> newPath;
        pair<int, int> boardCoordenates = state.back();
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
                state.push_back(tempMove);
                if(solveWord(board, word, state)) return true;
                state.pop_back();
            }
        }
            
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() > board.size() * board.front().size()) return false;
        vector<pair<int, int>> state;
        unordered_map<char, int> characters; 

        for (char a : word){
            characters[a]--;
        }
      

        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board.front().size(); j++){
                if (characters.find(board[i][j]) != characters.end()){
                    characters[board[i][j]]++;
                }
            }
        }
        for (pair<char, int> c : characters){
           cout << c.second << endl;
        }
        // if (board[i][j] == word.front()){
        //             state.push_back({i,j});
        //             if (solveWord(board, word, state)) return true;
        //             state.pop_back();
        //         }

        return false;
    }
};