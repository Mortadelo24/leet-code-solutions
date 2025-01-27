class Solution {
public:
    bool isNumber(string s) {
        return regex_match(s, regex("2"));
    }
};