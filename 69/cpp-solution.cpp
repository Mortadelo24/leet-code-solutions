class Solution {
public:
    int mySqrt(int x) {
        if (x == 1) return 1;
        int low = 0;
        int high = x;
        int result = 0;
        unsigned long long square; 

        while (high - low > 1){
            unsigned long long mid = floor((low + high) / 2);
            square = mid*mid;
            if (square > x  ){
                high = mid;
            }else if( square <= x ){
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