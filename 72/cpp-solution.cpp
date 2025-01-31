class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() < word2.size()) swap(word1, word2);

        vector<vector<int>> state(word2.size(), vector(word1.size(), 0));




        return 0;
    }
};