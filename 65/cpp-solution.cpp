class Solution {
public:
    bool isNumber(string s) {
        string sing = R"((\+|-)?)";
        string integerNumber =  R"(\d+)";
        string decimalNumber =  R"((\d+\.)|(\d+\.\d+)|(\.\d+))";
        string number = integerNumber + "|" + decimalNumber;
        string exponent = R"([eE][+-]?\d+)"; 
        string pattern = sing + '(' + number + ')' + '(' + exponent + ")?";

        return regex_match(s, regex(pattern));
    }
};