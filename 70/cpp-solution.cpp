class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return n;
        int previousResult = 1;
        int result = 2;
        for (int i = 0; i < n - 2; i++){
            int temp = result;
            result += previousResult;
            previousResult = temp;
        }
        return result;    
    }
};