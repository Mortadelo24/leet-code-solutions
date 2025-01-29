class Solution {
public:
    void printLines(vector<string>& lines){
        for (int i = 0; i < lines.size(); i++){
            cout << lines[i] << endl;
        }
    }
    vector<int> calculateSpaces(int blankSpaces, int spacesToUse){
        vector<int> spaces;
        int baseAmountOfSpaces = floor(spacesToUse/blankSpaces);
        int extraSpaces = spacesToUse % blankSpaces;
        for (int i = 0; i < blankSpaces; i++){
            int spacesForThisLine = baseAmountOfSpaces;
            if (extraSpaces > 0){
                extraSpaces--;
                spacesForThisLine++;
            }
            spaces.push_back(spacesForThisLine);
        }
        return spaces;
    }
    string generateLine(vector<string>& words, int start, int end, int maxWidth){        
        if (start == end){
            string line = words[start];
            return line + string(maxWidth-line.size(), ' ');
        }

        string line;

        vector<string> wordList;
        int lineWidth = 0;
        for (int i = start; i <= end; i++){
            lineWidth += words[i].size();
            wordList.push_back(words[i]);
        }
        vector<int> spaces = calculateSpaces(wordList.size()-1, maxWidth - lineWidth);

        for (int i = 0; i < spaces.size(); i++){
            line += wordList[i] + string(spaces[i], ' ');
        }
        line += wordList.back();


        return line;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> lines;
        int totalWidth = 0;

        int start = -1;
        int end = -1;

        for (int i = 0; i < words.size(); i++){
            if (totalWidth == 0) start = i;
            totalWidth += words[i].size() + 1;
            if (totalWidth - 1 > maxWidth){
                totalWidth = 0;
                i--;
                end = i;
                
                lines.push_back(generateLine(words, start, end, maxWidth));
            }
        }
        // the last line is processed different
        string lastLine;
        int lineWidth = 0;
        for (int i = start; i < words.size(); i++){
            lineWidth += words[i].size();
            lastLine += words[i];
            if (i != words.size()-1){
                lineWidth++;
                lastLine += " ";
            } 
        }
        lastLine += string(maxWidth - lineWidth, ' ');
        lines.push_back(lastLine);

        return lines;
    }
};