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
            char key = s[right];
            if (doesIncludeKey(state, key)) {
                state[key]++;
                // the value 0 represents that all required chars of that kind were found
                if (state[key] == 0) charCounter++;
            }
           
            // stop if all required chars were found.
            if (charCounter == stateSize) break;
            // increase right
            if (right < s.size() - 1){
                right++;
            } else break;
        }
        // return a clear string if there is no matching substring
        if (charCounter != stateSize) return "";
        
        // reduce and move 

        while(right < s.size()){
            // substract left char if it is one of the targets and increment left by one
            if (doesIncludeKey(state, s[left])){
                state[left]--;
            }
            left++;
            // temporaly left as true because there is way to count the correct char states yet
            if (true){
                // this will only be executed if the state is not valid
                // increment right by one and if right char is in targets increment its value
                right++;
                if (doesIncludeKey(state, s[right])){
                    state[right]++;
                }
            }
            
        }
        printState(state);
        

        return "NOValue";
    }
};