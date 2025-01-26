class Solution {
public:
    void printState(vector<int>& state) {
        for (int a : state) {
            cout << a << " | ";
        }
        cout << endl;
    }

    int minPathSum(vector<vector<int>>& grid) {
        vector<int> state = vector(grid.front());

        for(int n = 1; n < state.size(); n++){
            state[n] = grid.front()[n] + state[n-1];
        }

        for (int m = 1; m < grid.size(); m++) {
            state[0] = grid[m][0] + state[0];

            for (int n = 1; n < state.size(); n++) {
                state[n] = grid[m][n] +
                           (state[n - 1] < state[n] ? state[n - 1] : state[n]);
            }

            printState(state);
        }

        return state.back();
    }
};