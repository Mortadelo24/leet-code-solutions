class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        double mid;

        while (low < high){
            mid = (low + high) / 2;
            double pow = mid * mid;
            if (x < pow){
                high = mid - 1;
                cout << "left" << endl;
            }else if(x > pow){
                low = mid + 1; 
            }  
            break;
        }
        cout << mid << endl;
        return 0 ;
    }
};