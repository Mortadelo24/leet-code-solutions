class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2)return nums.size();
        
        int last = 2;
        for(int i = 2; i < nums.size(); i++){
            if(nums[last-2]!=nums[i])
            {
                nums[last++]=nums[i];
            }
            
        }


        return last + 1;
    }
};