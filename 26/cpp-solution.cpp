class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        while(index < nums.size()){
            if (index>0 && nums[index] == nums[index - 1]){
                nums.erase(nums.begin() + index);
                index--;
            }
        }

        for (int i : nums){
            cout << i << endl;
        }

        return nums.size();
    }
};