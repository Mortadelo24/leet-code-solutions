class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int currentNum = nums.front();
        int uniqueElements = 0;
        for(int i = 1; i < nums.size(); i++){
            if (nums[i] != currentNum){
                currentNum = nums[i];
                continue;
            }
            nums.erase(nums.begin() + i);
        }
        return uniqueElements;
    }
};