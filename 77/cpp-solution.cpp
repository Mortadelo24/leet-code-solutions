class Solution {
public:
    void generateCombinations(vector<vector<int>> combinations, int n, int k, vector<int> base = {}){
        if (base.size() == k) {
            combinations.push_back(base);
            return;
        }
        int start = base.empty() ? 0 : base.back();
        for (int i = start + 1; i <= n; i++){
            cout << i << endl;
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        
        generateCombinations(combinations, n, k, {});


        return combinations;
    }
};