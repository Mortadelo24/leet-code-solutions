class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size()); 
        int i = nums.size() - 1;

        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            if (abs(nums[left]) > abs(nums[right])){
                ans[i--] = pow(nums[left], 2);
                left++;
            } else {
                ans[i--] = pow(nums[right], 2);
                right--;
            }
        }

        return ans;
    }
};