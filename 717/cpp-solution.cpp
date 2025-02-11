class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        return bits[bits.size()-2] == 0;
    }
};