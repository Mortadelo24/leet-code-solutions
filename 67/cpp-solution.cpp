class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) swap(a,b);
        string result(a);

        for (int i = 0; i < b.size(); i++ ){
            int aNum = a[a.size()-1-i] == '1' ? 1 : 0;
            int bNum = b[b.size()-1-i] == '1' ? 1 : 0;
            cout << aNum << bNum << endl;
        }

        return result;
    } 
};