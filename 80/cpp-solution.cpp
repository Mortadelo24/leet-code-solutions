class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        bool isSecond = false;
        int last = 0;
        for(int i = 1; i < nums.size(); i++){
            if (isSecond && nums[i] == nums[last])continue;
            if (nums[last] == nums[i]) isSecond = true;
            nums[++last] = nums[i];
        }


        cout << last << endl;
        return nums.size();
    }
};