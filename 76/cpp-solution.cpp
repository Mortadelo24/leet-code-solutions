class Solution {
public:
    void printState(unordered_map<char, int>& state){
        for (const auto& pair : state) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
    }
    bool doesIncludeKey(unordered_map<char, int>& state, char key){
        return state.find(key) != state.end();
    }
    string minWindow(string s, string t) {
        unordered_map<char, int> state;

        // map each char from t as a negative number (it represents the lack of value)
        for (char i : t){
            if (!doesIncludeKey(state, i)){
                state[i] = 0;
            }
            state[i]--;
        }

        // open windows: move only the right pointer
        int stateSize = state.size();
        int charCounter = 0;
        
        int left = 0;
        int right = 0;

        while (true){

            if (right < s.size() - 1){
                right++;
            } else break;
        }
        cout << right << endl;; 

        printState(state);
        

        return "";
    }
};