class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            nums.erase(nums.begin() + i);
        }

        return nums.size();
    }
};