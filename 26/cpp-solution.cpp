class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        while(index < nums.size()){
            if (index > 0 && nums[index] == nums[index - 1]){
                nums.erase(nums.begin() + index);
                index--;
            }
            index++;
        }

        return nums.size();
    }
};