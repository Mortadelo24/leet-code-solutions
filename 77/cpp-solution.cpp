class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> numbers(n);
        vector<vector<int>> combinations;
        iota(numbers.begin(), numbers.end(), 1);
        combinations.push_back(numbers);



        return combinations;
    }
};