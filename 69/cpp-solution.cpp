class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;

        while (high - low > 1){
            double mid = (low + high) / 2;
            double pow = mid * mid;
            cout << mid << endl;
            if (x < pow){
                high = floor(mid);
            }else if(x > pow){
                low = floor(mid); 
            } else {
                break;
            }
        
        }
        return floor((low + high) / 2);
    }
};