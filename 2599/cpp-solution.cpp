class Solution {
public:
    inline int includesAllChars(unordered_map<char, int>& characters){
        return characters['a'] >= 0 && characters['b'] >= 0  && characters['c'] >= 0; 
    }
    int takeCharacters(string s, int k) {
        if (k <= 0) return 0;
        unordered_map<char, int> characters;
        characters['a'] = -k;
        characters['b'] = -k;
        characters['c'] = -k;

        int right = s.size() - 1;
        int left = 0;
        while (right >= 0 && !includesAllChars(characters)){
            characters[s[right--]]++;
        }


        if (!includesAllChars(characters)) return -1; 


        int maxWindowLength = right - left + 1;
        right++;
        while(right < s.size()){
            characters[s[right++]]--;
            while  (!includesAllChars(characters)){
                characters[s[left++]]++;
            }
            maxWindowLength = max(maxWindowLength, right - left);

        }

        return s.size() - maxWindowLength;
    }
};