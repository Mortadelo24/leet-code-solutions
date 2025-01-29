class Solution {
public:
    int climbStairs(int n) {
        stack<int> frontier;
        frontier.push(n);
        int variants = 0;

        while (!frontier.empty()){
            int currentState = frontier.top();
            frontier.pop();
            if (currentState <= 0){
                variants++;
            }else if (currentState >= 2){
                frontier.push(currentState - 2);
                frontier.push(currentState - 1);
            } else {
                frontier.push(currentState-1);
            }
        }

        return variants;

    }
};