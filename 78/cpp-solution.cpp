class Solution {
public:
    void generateCombination(vector<vector<int>>combinations,vector<int>& nums, vector<int>& base, int start = 0){
        combinations.push_back(base);

    }  
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> combinations;
        vector<int> base;

        generateCombination(combinations,nums, base);

        return combinations;
    }
};