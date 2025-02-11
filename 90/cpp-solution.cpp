class Solution {
public:
    void generateCombination(set<vector<int>>& combinations,vector<int>& nums, vector<int>& base, int index = -1){
        combinations.insert(base);
        index++;
        for (index; index < nums.size(); index++){
            base.push_back(nums[index]);
            generateCombination(combinations, nums, base, index);
            base.pop_back();
        }

    }  
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> combinations;
        vector<int> base;

        generateCombination(combinations,nums, base);

        return vector(combinations.begin(), combinations.end());
    }
};