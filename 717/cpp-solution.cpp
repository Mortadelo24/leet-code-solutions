class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if (bits.size() < 2) return true;
        return bits[bits.size()-2] == 0;
    }
};