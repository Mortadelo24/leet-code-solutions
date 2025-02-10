class Solution {
public:
    inline int includesAllChars(unordered_map<char, int>& characters){
        return characters['a'] >= 0 && characters['b'] >= 0  && characters['c'] >= 0; 
    }
    int takeCharacters(string s, int k) {
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
        
        while(right < s.size()){
            right++;
            characters[s[right]]--;
            if (!includesAllChars(characters)){
                characters[s[left]]++;
                left++;
            }
        }

        return s.size() - (right + 1 - left);
    }
};