class Solution {
public:
    bool isDigit(string s, int& globalIndex){
        enum {
            start, digit
        } state = start;

        int index = globalIndex;

        while(index < s.size()){
            char character = s[index];
            cout << character << "|";

            if (state == start || state == digit && isdigit(character)){
                state = digit;
            } else return false;
            index++;
        }

        if (state == digit){
            globalIndex = index;
            return true;
        }

        return false;
    }
    bool isRawNumber(string s, int& globalIndex){
        enum {
            start, digit0, dot0, dot1, digit1, digit2
        } state = start;
        
        int index = globalIndex;

        while(index < s.size()){
            char character = s[index];

            cout << character << "|";
    
            if (state == start && isDigit(s, index)){
                state = digit0;
            } else if (state == start && character == '.'){       
                state = dot0;
            }else if (state == dot0 && isDigit(s, index)){
                state = digit1;
            }else return false;
            index++;
        }


        if (state == digit0 || state == digit1 || state == digit2 || state == dot1){
            globalIndex = index;
            return true;
        }

        return false;
    }
    bool isSing(string s, int& globalIndex){
        enum {
            start,
            sing
        } state = start;
        int index = globalIndex;

        while (index < s.size()){
            char character = s[index];

            if (state == start && (character == '+' || character == '-')){
                state = sing;
            } else {
                return false;
            }
            index++;
        }

        if (state !== sing) return false;

        globalIndex = index;
        return true;
    }
    bool isNumber(string s) {
        int index = 0;

        enum {
            start,
            sing, rawNumber, exponent
        } state = start;

        while (index < s.size()){
            if (state == start && isSing(s, index)){
                state = sing;
            } else if((state == sing || state == start) && isRawNumber(s, index)){
                state = rawNumber;

            } else return false;
            index++;
        } 


        return state == rawNumber || state == exponent;       
    }
};