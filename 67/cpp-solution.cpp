class Solution {
public:
    string addBinary(char a, char b){
        return addBinary(string(1,a), string(1,b));
    }
    string addBinary(string a, string b) {
        if (a.size() == 1 && b.size() == 1){
            if (a[0] == '1' && b[0] == '1'){
                return "10";
            } else if (a[0] == '0' && b[0] == '0'){
                return "0";
            } 
            return "1";
        }
        if (a.size() < b.size()) swap(a,b);
        string carry = "0";

        for (int i = 0; i < b.size(); i++){
            int aIndex = a.size() - 1 - i;
            int bIndex = b.size() - 1 - i;

            string preResult = addBinary(addBinary(a[aIndex], b[bIndex]), carry);
            carry = "0";


            if (preResult.size() == 2){
                carry = preResult.front();
            }
            a[aIndex] = preResult.back();
        }
        // if no carry is left
        if (carry == "0") return a;

        // if there is a carry but both strings have equal size
        if (a.size() == b.size()){
            a.insert(a.begin(), '1');
        
        } else {
        // if there is a carry but both strings have difference size
            string pre = addBinary(string(a.begin(), a.end() - b.size()), carry);
            a.erase(a.begin(), a.end() - b.size());
            a.insert(a.begin(), pre.begin(), pre.end());
        }
        
        

        return a;
    }
};