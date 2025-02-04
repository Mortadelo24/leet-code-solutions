class Solution {
public:
    bool binarySearch(vector<int>& nums, int target, int left, int right){
        if (left > right) return false;
        int mid = floor((left + right) / 2);

        if ((nums[mid] < nums[left] && nums[mid] < nums[right]) || (nums[mid] > nums[left] && nums[mid] > nums[right]) || (nums[mid] == nums[left] && nums[mid] == nums[right])){
            cout << "special case"<< endl;
            return binarySearch(nums, target, mid, right) || binarySearch(nums, target, left, mid);
        }

        if (nums[mid] < target){
            return binarySearch(nums, target, mid + 1, right);
        }else if (nums[mid] > target){
            return binarySearch(nums, target, left, mid-1);
        } 
        return true;
    }
    bool search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size()-1);
    }
};