enum State {
    start,
    digit0,
    digit1,
    digit2,
    digit3,
    dot0,
    dot1,
    sing0,
    sing1,
    exponent,
    end
};

class Solution {
public:
    inline bool isDigit(char s){
        return isdigit(s);
    }
    bool isSing(char s){
        return s == '-' || s == '+';
    }
    bool isExponent(char s){
        return s == 'e' || s == 'E';
    }
    bool isNumber(string s) {
        State state = start;

        for (int i = 0; i < s.size(); i++) {
            char character = s[i];
            if ((state == digit0 || state == digit1 || state == digit2 ||
                 state == digit3) &&
                isDigit(character)) {
                continue;
            } else if (state == start && isSing(character)) {
                state = sing0;
            } else if ((state == start || state == sing0) && character == '.') {
                state = dot0;
            } else if ((state == start || state == sing0) &&
                       isDigit(character)) {
                state = digit0;
            } else if (state == dot0 && isDigit(character)) {
                state = digit1;
            } else if (state == digit0 && character == '.') {
                state = dot1;
            } else if (state == dot1 &&  isDigit(character)) {
                state = digit2;
            } else if ((state == digit0 || state == digit1 || state == digit2 ||
                        state == dot1) &&
                       isExponent(character)) {
                state = exponent;
            } else if (state == exponent && isSing(character)) {
                state = sing1;
            } else if ((state == sing1 || state == exponent) &&
                       isDigit(character)) {
                state = digit3;
            }
            else
                return false;
        }

        if (state == digit0 || state == digit1 || state == digit2 || state == digit3 || state == dot1){
                return true;
        }

        return false;
    }
};