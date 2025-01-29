class Solution {
public:
    int mySqrt(int x) {
        if (x == 1) return 1;
        int low = 0;
        int high = x;
        int result = 0;

        while (high - low > 1){
            int mid = floor((low + high) / 2);
            int pow = mid * mid;
            if (x < pow){
                high = mid;
            }else if(x >= pow){
                result = mid;
                low = mid; 
            } else {
                result = mid;
                break;
            }
        
        }
        return result;
    }
};