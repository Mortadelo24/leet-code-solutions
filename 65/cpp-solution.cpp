class Solution {
public:
    bool isNumber(string s) {
        string pattern = R"((\+|-)?(\d+|((\d+.)|(\d+.\d+)|(.\d+)))([e|E]\d+)?)";

        return regex_match(s, regex(pattern));
    }
};