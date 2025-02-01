class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;
        int white = 0;
        int blue = 0;

        for (int i = 0; i < nums.size(); i++){
            int total = 0;
            if (nums[i] == 0) total += red;
            if (nums[i] == 1) total += white;
            if (nums[i] == 2) total += blue;

            if (total != i){
                cout << total << endl;
            }

            if (nums[i] == 0) red++;
            else if (nums[i] == 1) white++;
            else blue++;
        }

      
    }
};