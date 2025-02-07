class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++){
            nums[i] = pow(nums[i], 2);
            int j = i;
            while(j > 0 && nums[j] < nums[j-1]){
                swap(nums[j], nums[j-1]);
                j--;
            }
        }

        return nums;
    }
};