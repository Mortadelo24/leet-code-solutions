class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;

        while (low < high){
            int mid = floor((low + high) / 2);
            int pow = mid * mid;
            if(x > pow){
                low = pow + 1; 
            } else if (x < pow){
                high = pow - 1;
            }else {
                cout << mid << endl;
                return mid;
            }
        }
        return 0;
    }
};