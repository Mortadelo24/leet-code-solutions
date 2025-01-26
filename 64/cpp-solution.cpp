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

        // fill the first row ignoring the first one and add the previous cell to the current
        for(int n = 1; n < state.size(); n++){
            state[n] = grid.front()[n] + state[n-1];
        }

        // refill the row using the information already prossesed 
        for (int m = 1; m < grid.size(); m++) {
            // fill the first cell of each row with the current state[m] + the first cell from the grid 
            state[0] = grid[m][0] + state[0];

            for (int n = 1; n < state.size(); n++) {
                state[n] = grid[m][n] +
                           (state[n - 1] < state[n] ? state[n - 1] : state[n]);
            }

        }

        return state.back();
    }
};