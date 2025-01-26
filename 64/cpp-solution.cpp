class Solution {
public:
    void printState(vector<int>& state){
        for (int a : state){
            cout << a  << " | ";
        }
        cout << endl;
    }
    void calculateCost(vector<int>& state){
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> state = vector(grid.front());
        calculateCost(state);
        printState(state);

        return state.back();
    }
};