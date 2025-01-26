class Solution {
public:
    void printState(vector<int>& state){
        for (int a : state){
            cout << a  << " | ";
        }
        cout << endl;
    }
  
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> state = vector(grid.front());
        int tempIndex = 0;
        state[0] = grid[tempIndex][0] + state[0];
        for (int i = 1; i < state.size(); i++){
            state[i] = grid[tempIndex][i] + (state[i-1] < state[i] ? state[i-1] : state[i]);
        }
        printState(state);

        return state.back();
    }
};