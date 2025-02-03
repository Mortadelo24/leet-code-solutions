class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int currentNum = nums.front();
        int previous = 1;
        for(int i = 0; i < nums.size(); i++){
            previous = nums[i];
            nums.erase(nums.begin() + i);
        }

        for (int a : nums){
            cout << a << endl;
        }
        return 0;
    }
};