class Solution {
public:
    bool isDigit(string s, int& globalIndex){
        enum {
            start, digit
        } state = start;

        int index = globalIndex;

        while(index < s.size()){
            char character = s[index];

            if ((state == start || state == digit) && isdigit(character)){
                state = digit;
                index++;
                
            } else break;
        }

        if (state == digit){
            globalIndex = index;
            return true;
        }

        return false;
    }
    bool isExponent(string s, int& globalIndex){
        enum {
            start, exponent, sing, digit
        } state = start;

        int index = globalIndex; 

        while (index < s.size()){
            if (state == start && (s[index]== 'e' || s[index]== 'E')){
                state = exponent;
                index++;
            } else if (state == exponent && isSing(s, index)){
                state = sing;
            } else if ((state == sing  || state == exponent)&& isDigit(s,index)){
                state = digit;
            } else break;
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
        // NOTE: it is required that each case add the necessary amount to the index, if not, it will not increase.
        while(index < s.size()){
            if (state == start && isDigit(s, index)){
                state = digit0;
            } else if (state == digit0 && s[index] == '.'){
                state = dot1;
                index++;

            } else if (state == dot1 && isDigit(s, index)){
                state = digit2;
            } else if(state == start && s[index] == '.'){
                state = dot0;
                index++;
            }else if (state == dot0 && isDigit(s,index)){
                state = digit1;

            }else break;

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
            } else break;
            index++;
        }

        if (state != sing) return false;

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
            } else if (state == rawNumber && isExponent(s, index)){
                state = exponent;
            } else return false;
        } 


        return (state == rawNumber || state == exponent) && index >= s.size();       
    }
};