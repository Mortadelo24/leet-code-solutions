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
                
                int base = min(state[x-1][y], state[x][y-1], state[x-1][y-1]);
                cout << base << endl;
                
            }
        }
        printState(state);

        return 0;
    }
};