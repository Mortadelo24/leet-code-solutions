class Solution {
public:
    void printState(unordered_map<char, int>& state){
        for (const auto& pair : state) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
    }
    string minWindow(string s, string t) {
        unordered_map<char, int> state;

        // map t in hash_map
        for (char i : t){
            if (state.find(i) == state.end()){
                state[i] = 0;
            }
            state[i]++;
        }

        printState(state);
        

        return "";
    }
};