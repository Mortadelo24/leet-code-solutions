class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        for (int i : bits){
            if (i == 1) return bits.size() % 2 != 0;
        }
        return true;
    }
};