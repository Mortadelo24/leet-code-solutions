class Solution {
public:
    void printState(vector<vector<int>>& state){
        for (vector<int> row : state){
            for (int cell : row){
                 cout << cell;
                cout << " ";
            }
            cout << endl;
        }
        cout << endl;

    }
    int minDistance(string word1, string word2) {
        // setup the grid
        vector<vector<int>> state(word1.size() + 1, vector(word2.size() + 1, 0));
        for (int x = 1; x <= word1.size(); x++) state[x][0] = x;
        for (int y = 1; y <= word2.size(); y++) state[0][y] = y;
        // end

        for (int x = 1; x <= word1.size(); x++){
            for(int y = 1; y <= word2.size(); y++){
                int base = min({state[x-1][y], state[x][y-1], state[x-1][y-1]});        
                state[x][y] = word1[x-1] != word2[y-1] ? base + 1 : state[x-1][y-1];         
            }
        }

        return state.back().back();
    }
};