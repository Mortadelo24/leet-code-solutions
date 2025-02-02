class Solution {
public:
    void generateCombinations(vector<vector<int>> combinations, int n, int k, vector<int> base = {}){
        int start = base.empty() ? 0 : base.first();
        for (int i = start; i <= n; i++){
            cout << i << endl;
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        
        generateCombinations(combination, n, k, {});


        return combinations;
    }
};