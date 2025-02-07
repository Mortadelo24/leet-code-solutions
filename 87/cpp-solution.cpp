class Solution {
public:
    bool areEqueals(string& s1, string& s2){
        if (s1.size() == 1 && s1 == s2) return true;

        for (int i = 1; i < s1.size(); i++){
            string x1 = string(s1.begin(), s1.begin()+i);
            string y1 = string(s1.begin()+i, s1.end());

            string x2 = string(s2.begin(), s2.begin()+i);
            string y2 = string(s2.begin()+i, s2.end());

            string x3 = string(s2.end()-i, s2.end());
            string y3 = string(s2.begin(), s2.end() - i);

            if ((areEqueals(x1,x3) && areEqueals(y1, y3)) || (areEqueals(x1,x2) && areEqueals(y1, y2))) return true;
        }

        return false;
    }
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
    
        return areEqueals(s1, s2);
    }
};