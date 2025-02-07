class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans; 

        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            if (abs(nums[left]) > abs(nums[right])){
                ans.insert(ans.begin(), pow(nums[left], 2));
                left++;
            } else {
                ans.insert(ans.begin(), pow(nums[right], 2));
                right--;
            }
        }

        return ans;
    }
};