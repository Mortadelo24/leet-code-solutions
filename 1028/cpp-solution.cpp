class Solution {
public:
    bool oneSidedCollide(vector<int>& rangeA, vector<int>& rangeB){
        return (rangeA[0] >= rangeB[0] && rangeA[0] <= rangeB[1]) || (rangeA[1] >= rangeB[0] && rangeA[1] <= rangeB[1]);
    }
    bool collides(vector<int>& rangeA, vector<int>& rangeB){
        return oneSidedCollide(rangeA, rangeB) || oneSidedCollide(rangeB, rangeA);
    }
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        if (firstList.size() < secondList.size()) swap(firstList, secondList);
        vector<vector<int>> ranges;

        int pointerA = 0;
        int pointerB = 0;

        while( pointerA < firstList.size() && pointerB < secondList.size()){
            vector<int>& rangeA = firstList[pointerA];
            vector<int>& rangeB = secondList[pointerB];
            if (collides(rangeA, rangeB)){
                int subPointerA = pointerA;
                while(subPointerA < firstList.size() && collides(rangeB,  firstList[subPointerA])){
                    ranges.push_back({max(firstList[subPointerA][0], rangeB[0]), min(firstList[subPointerA][1], rangeB[1])});
                    subPointerA++;
                }

                pointerB++;
            }

            pointerA++;
        }

        return ranges;
    }
};