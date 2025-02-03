// this is a bad aproach but i will let it this way because i know the solution only because i read it from another person and i do not want to copy it exactly the same.
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
        stack<pair<int, int>> startStateCandidates;

        for (char a : word){
            characters[a]--;
        }
      
        int correctCharsCounter = 0;
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board.front().size(); j++){
                if (characters.find(board[i][j]) != characters.end()){
                    characters[board[i][j]]++;
                    if (characters[board[i][j]] == 0) correctCharsCounter++;
                    if (board[i][j] == word.front()) startStateCandidates.push({i,j});
                }
            }
        }
        if (correctCharsCounter != characters.size()) return false;
        
       
       
        while(!startStateCandidates.empty()){
            state.push_back(startStateCandidates.top());
            if (solveWord(board, word, state)) return true;
            state.pop_back();

            startStateCandidates.pop();
        }

        return false;
    }
};