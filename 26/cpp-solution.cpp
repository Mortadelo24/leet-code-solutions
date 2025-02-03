class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int previous = nums.front();
        int index = 0;
        while(index < nums.size()){
            if (nums[index] == previous){
                nums.erase(nums.begin() + i);
                index--;
            }
            previous = nums[index];
        }
        while ()
        for (int i : nums){
            cout << i << endl;
        }

        return nums.size();
    }
};