class Solution {
public:
    void printState(vector<vector<int*>>& state){
        for (vector<int*> row : state){
            for (int* cell : row){
                if (!cell) cout << "N";
                else cout << cell;
                cout << " ";
            }
            cout << endl;
        }
        cout << endl;

    }
    int minDistance(string word1, string word2) {
        if (word1.size() < word2.size()) swap(word1, word2);

        vector<vector<int*>> state(word2.size(), vector(word1.size(), (int*) nullptr));

        for (int x = 0; x < word2.size(); x++){
            for(int y = 0; y < word1.size(); y++){
                if (word2[x] == word1[y]){
                    state[x][y] = new int(abs(x-y)); 
                }
            }
        }
        printState(state);

        return 0;
    }
};