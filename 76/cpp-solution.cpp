class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> state;

        for (char i : t){
            if (state.find(i) == state.end()){
                state[i] = 0;
            }
            state[i]++;
        }

        return "";
    }
};