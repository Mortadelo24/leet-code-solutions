class Solution {
public:
    bool isNumber(string s) {
        string sing = R"((\+|-)?)";
        string integerNumber = sing + R"(\d+)";
        string decimalNumber = sing + R"((\d+\.)|(\d+\.\d+)|(\.\d+))";
        string number = integerNumber + "|" + integerNumber;
        string exponent = R"((e|E)?)" + number;
        string pattern = number  + exponent;

        return regex_match(s, regex(pattern));
    }
};