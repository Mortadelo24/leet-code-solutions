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

        for (auto it : nums) {
            if (it == 0)
                red++;
            else if (it == 1)
                white++;
            else
                blue++;
        }
        int i = 0;
        int j = red;
        for (i; i < j; i++) nums[i] = 0;
        j + white;
        for (i; i < j; i++) nums[i] = 1;
        j + blue;
        for (i; i < j; i++) nums[i] = 2;

    }
};