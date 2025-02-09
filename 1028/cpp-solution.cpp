class Solution {
public:
    bool collides(vector<int>& rangeA, vector<int>& rangeB){
        return (rangeA[0] >= rangeB[0] && rangeA[0] <= rangeB[1]) || (rangeA[1] >= rangeB[0] && rangeA[1] <= rangeB[1]);
    }
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ranges;

        int pointerA = 0;
        int pointerB = 0;

        while( pointerA < firstList.size() && pointerB < secondList.size()){
            vector<int>& rangeA = firstList[pointerA];
            vector<int>& rangeB = secondList[pointerB];
            if (collides(rangeA, rangeB)){
                int subPointerB = pointerB;
                while(subPointerB < secondList.size() && collides(rangeA,  secondList[subPointerB]) ){
                    ranges.push_back({max(rangeA[0], secondList[subPointerB][0]), min(rangeA[1], secondList[subPointerB][1])});
                    subPointerB++;
                }
             
                pointerA++;
            }else {
                pointerB++;
            }
        }

        return ranges;
    }
};