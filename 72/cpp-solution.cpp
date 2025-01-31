class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() < word2.size()) swap(word1, word2);

        vector<vector<optional<int>>> state = vector(word2.size(), vector(word1.size(), optional()));

        


        return 0;
    }
};