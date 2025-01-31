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

        printState(state);


        return 0;
    }
};