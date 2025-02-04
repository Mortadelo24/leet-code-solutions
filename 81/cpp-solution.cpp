class Solution {
public:
    bool binarySearch(vector<int>& nums, int target, int left, int right){
        if (left > right) return false;
        int mid = floor((left + right) / 2);

        if (nums[mid] == target) return true;

        if ((nums[mid] <= nums[left] && nums[mid] <= nums[right]) || (nums[mid] >= nums[left] && nums[mid] >= nums[right])){
            return binarySearch(nums, target, mid + 1, right) || binarySearch(nums, target, left, mid - 1);
        }

        if (nums[mid] < target){
            return binarySearch(nums, target, mid + 1, right);
        }else if (nums[mid] > target){
            return binarySearch(nums, target, left, mid-1);
        } 
        return false;
    }
    bool search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size()-1);
    }
};