class Solution {
public:
    void generateCombination(vector<vector<int>>& combinations,vector<int>& nums, vector<int>& base, int index = -1){
        combinations.push_back(base);
        index++;
        for (index; index < nums.size(); index++){
            cout << index << endl;
        }

    }  
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> combinations;
        vector<int> base;

        generateCombination(combinations,nums, base);

        return combinations;
    }
};