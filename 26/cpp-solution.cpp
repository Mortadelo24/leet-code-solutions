class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int currentNum = nums.front();
        int uniqueElements = 1;
        for(int i = 1; i < nums.size(); i++){
            if (nums[i] != currentNum){
                currentNum = nums[i];
                uniqueElements++;
                continue;
            }
            nums.erase(nums.begin() + i);
        }

        for (int a : nums){
            cout << a << endl;
        }
        return uniqueElements;
    }
};