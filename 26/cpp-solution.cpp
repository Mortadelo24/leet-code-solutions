class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 1;
        int lastUnique = 0;
        while(index < nums.size()){
            if (index > 0 && nums[index] == lastUnique){
                lastUnique++;
            }
            index++;
        }

        return nums.size();
    }
};