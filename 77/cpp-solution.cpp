class Solution {
public:
    void generateCombinations(vector<vector<int>> combinations, int n, int k, vector<int> base = {}){
        int start = base.empty() ? 0 : base.back();
        for (int i = start; i <= n; i++){
            cout << i << endl;
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        
        generateCombinations(combinations, n, k, {});


        return combinations;
    }
};