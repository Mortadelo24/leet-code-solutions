class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        bool isSecond = false;
        int last = 0;
        for(int i = 1; i < nums.size(); i++){
         
            if (nums[last] != nums[i]){
                nums[++last] = nums[i];
            }
        }


        cout << last << endl;
        return nums.size();
    }
};