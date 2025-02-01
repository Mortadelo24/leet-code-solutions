class Solution {
public:
    void printState(vector<int>& nums, set<int> marks){
        for (int i : nums) cout << i << " "; 
        cout << endl;
        string lineMarked(nums.size(), ' '); 
        for (int mark : marks){
            lineMarked[i] = "^";
        }
        cout << lineMarked << endl;
    }
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
                cout << total << " <-> " << i << endl;  
                printState(nums, {total, i});
                swap(nums[total], nums[i]);
            }

            if (nums[i] == 0) red++;
            else if (nums[i] == 1) white++;
            else blue++;
        }

    }
};