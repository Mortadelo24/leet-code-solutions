class Solution {
public:
    inline int includesAllChars(unordered_map<char, int>& characters){
        return characters['a'] >= 0 && characters['b'] >= 0  && characters['c'] >= 0; 
    }
    int takeCharacters(string s, int k) {
        unordered_map<char, int> characters;
        characters['a'] = -2;
        characters['b'] = -2;
        characters['c'] = -2;

        int i = 0;
        while (i < s.size() && !includesAllChars(characters)){
            characters[s[i++]]++;
        }
        cout << characters['a'] << endl;
        cout << characters['a'] << endl;

        cout << includesAllChars(characters) << endl;

        return 0;
    }
};