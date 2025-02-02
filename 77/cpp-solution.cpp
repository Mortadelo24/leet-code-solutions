class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> numbers(n);
        vector<vector<int>> combinations;
        iota(numbers.begin(), numbers.end(), 1);
        
        for (int i = 0; i < n - k; i++){
            cout << i << endl;
        }



        return combinations;
    }
};