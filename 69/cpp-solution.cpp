class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;

        while (low < high){
            int mid = floor((low + high) / 2);
            int pow = mid * mid;
            if (x < pow){
                high = mid - 1;
                continue;
            }else if(x > pow){
                low = mid + 1; 
                continue;
            }  
            return mid;
            
        }
        return (x <= 1)? low : low - 1;
    }
};