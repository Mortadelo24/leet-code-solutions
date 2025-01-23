class Solution {
public:
    void printState(vector<bool>& state){
        if(state.size() > 20) return;
        for (bool n : state){
            cout << (n ? "T" : "F") << " ";
        }
        cout << endl;
    }
    bool canJump(vector<int>& nums) {
        int numsSize = nums.size();
        vector<bool> state =  vector(numsSize, false); 
        state[0] = true;

        int j = 1;
        int nextIndexToCompute = 0;
        for (int i = 1; i < numsSize && !state.back(); i++) {
            if (!state[i-1]) break;

            int remainingJumps = nums[i-1] - (j-i);
            
            for (j; remainingJumps > 0 && j < numsSize; j++) {
                state[j] = true;
               
               remainingJumps--;
            }
            // printState(state);
        }

        return j == numsSize;
    }
};