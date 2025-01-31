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
        if (word1.size() > word2.size()) swap(word1, word2);
        vector<vector<int>> state(word1.size() + 1, vector(word2.size() + 1, 0));

        

        for (int x = 0; x <= word1.size(); x++){
            for(int y = 0; y <= word2.size(); y++){
                // fill initial state
                if (x == 0){
                    state[x][y] = y;
                    continue;
                } else if (y == 0){
                    state[x][y] = x;
                    continue;
                }
                // end
                cout << word1[x-1] << "|" << word2[y-1] << endl;
                int base = min(state[x-1][y], state[x][y-1]);
                base = min(base, state[x-1][y-1]);
                
                state[x][y] = word1[x] != word2[y] ? base + 1 : base;
                            
            }
        }
        printState(state);

        return 0;
    }
};