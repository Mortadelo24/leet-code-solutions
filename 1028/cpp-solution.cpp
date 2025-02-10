class Solution {
public:
bool collides(vector<int>& intervalA, vector<int>& intervalB){
    bool collidesWithA = intervalB[1] >= intervalA[0] && intervalB[1] <= intervalA[1];
    bool collidesWithB = intervalA[1] >= intervalB[0] && intervalA[1] <= intervalB[1];
    return collidesWithA || collidesWithB; 
}
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> intervals;
        int indexA = 0;
        int indexB = 0;

        while (indexA < firstList.size() && indexB < secondList.size()){
            vector<int>& intervalA = firstList[indexA];
            vector<int>& intervalB = secondList[indexB];
            if (intervalB[1] < intervalA[0]) indexB++;
            else if(intervalA[1] < intervalB[0]) indexA++;
            
            if (collides(intervalA, intervalB)){
                int tempIndexB = indexB;

                while (tempIndexB < secondList.size() && collides(intervalA, secondList[tempIndexB])){
                    intervals.push_back({max(intervalA[0], secondList[tempIndexB][0]), min(intervalA[1], secondList[tempIndexB][1])});
                    tempIndexB++;
                }
                indexA++;
            } 
        }

        return intervals;
    }
};