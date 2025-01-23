class Solution {
public:
    inline char integerToChar(int n){
        return n + '0';
    }
    int getFactorial(int n){
        if (n == 0) return 1;
        
        return n * getFactorial(n-1);
    }
    string getPermutation(int n, int k) {
        int remainer = k - 1;
        
        vector<int> numbers(n);
        iota(numbers.begin(), numbers.end(), 1);

        string sequence = "";
        
        for(int i = n - 1; i >= 0; i--){
            int factorial = getFactorial(i);
            int index = floor(remainer/factorial);
            remainer -= (factorial * index);
        
            sequence += integerToChar(numbers[index]);
            numbers.erase(numbers.begin() + index);

        }

        return sequence;
    }
};