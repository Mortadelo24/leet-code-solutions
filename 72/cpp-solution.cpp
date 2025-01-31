class Solution {
public:
    void printState(vector<vector<int*>>& state){
        for (vector<int*> row : state){
            for (int* cell : row){
                if (!cell) cout << "N";
                else cout << *cell;
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
            for(int y = x; y < word1.size(); y++){
                int distance = x-y;
                int* currentCell = state[x][y];
            
                if (word2[x] == word1[y] && (!currentCell || distance < *currentCell) ){
                    state[x][y] = new int(distance); 
                }
            }
        }
        printState(state);

        return 0;
    }
};