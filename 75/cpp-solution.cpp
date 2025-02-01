class Solution {
public:
    void printState(vector<int>& nums) {
        for (int i : nums)
            cout << i << " ";
        cout << endl;
    }
    void sortColors(vector<int>& nums) {
        int red = 0;
        int white = 0;
        int blue = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                red++;
            else if (nums[i] == 1)
                white++;
            else
                blue++;
        }
        int i = 0;
        for (i; i < red; i++) nums[i] = 0;
        for (i; i < white; i++) cout << "a";
        for (i; i < blue; i++) nums[i] = 2;

    }
};