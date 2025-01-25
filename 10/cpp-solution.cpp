class Solution {
public:
    void printTable(vector<vector<bool>>& table, string& s, string& p) {
        cout << "  |";
        for (char c : p) {
            cout << " " << c;
        }
        cout << endl;
        for (int i = 0; i < table.size(); i++) {
            if (i > 0) {
                cout << s[i - 1] << " ";

            } else {
                cout << "- ";
            }
            for (int j = 0; j < table[i].size(); j++) {
                cout << (table[i][j] ? 'T' : 'F');

                cout << " ";
            }
            cout << endl;
        }
    }
    bool isMatch(string s, string p) {
        int sSize = s.size();
        int pSize = p.size();
        vector<vector<bool>> dp = vector(sSize + 1, vector(pSize + 1, false));
        dp[0][0] = true;


        for (int i = 0; i <= sSize; i++) {
            for (int j = 1; j <= pSize; j++) {
                if (j - 2 >=0 && p[j - 1] == '*') {
                    dp[i][j] =  dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                } else {
                    
                        dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                    
                }
            }

        }

            // printTable(dp, s, p);

            return !!dp[sSize][pSize];
        }
    };