class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 1;
        int lastUnique = 0;
        while(index < nums.size()){
            if (nums[index] != nums[lastUnique]){
                nums[++lastUnique] = nums[index];
                
            }
            index++;
        }

        return nums.size();
    }
};