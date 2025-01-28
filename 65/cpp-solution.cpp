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
    bool doesInclude(set<char> items, char item) {
        return items.find(item) != items.end();
    }
    bool isNumber(string s) {
        set<char> sings = {'-', '+'};
        set<char> exponents = {'e', 'E'};
        set<char> dots = {'.'};

        State state = start;

        for (int i = 0; i < s.size(); i++) {
            char character = s[i];
            if ((state == digit0 || state == digit1 || state == digit2 ||
                 state == digit3) &&
                isdigit(character)) {
                continue;
            } else if (state == start && doesInclude(sings, character)) {
                state = sing0;
            } else if ((state == start || state == sing0) &&
                       doesInclude(dots, character)) {
                state = dot0;
            } else if ((state == start || state == sing0) &&
                       isdigit(character)) {
                state = digit0;
            } else if (state == dot0 && isdigit(character)) {
                state = digit1;
            } else if (state == digit0 && doesInclude(dots, character)) {
                state = dot1;
            } else if (state == dot1 &&  isdigit(character)) {
                state = digit2;
            } else if ((state == digit0 || state == digit1 || state == digit2 ||
                        state == dot1) &&
                       doesInclude(exponents, character)) {
                state = exponent;
            } else if (state == exponent && doesInclude(sings, character)) {
                state = sing1;
            } else if ((state == sing1 || state == exponent) &&
                       isdigit(character)) {
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