class Solution {
public:
    
    const int MOD = 1e9+7;   
    //we'll use a hashmap as our dp array to save the state
    unordered_map<string, int> dp;

    int solve(int n, int m, int i, int j, int maxMoves){

        string state = to_string(i) + "|" +to_string(j) + "|" + to_string(maxMoves);
        //if we have traversed this state already
        if(dp.find(state) != dp.end()){
            return dp[state];
        }

        //if the ball os out of the boundary then return 1;
        if(i < 0 || j < 0 || i >= n || j >= m){
            return 1;
        }

        //if you are out of moves then return 0;
        if(maxMoves == 0){
            return dp[state] = 0;
        }

        //out direction array
        vector<int> x = {0,0,1,-1};
        vector<int> y = {-1,1,0,0};
        int ans = 0;

        for(int dir=0; dir<4; dir++)   
            //traverse in all 4 directions
            ans = (ans + solve(n,m,i + x[dir],j + y[dir],maxMoves-1)) % MOD;
       

        return dp[state] = ans;

    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
  
        if(maxMove == 0)    return 0;
        
        int ans = solve(m,n,startRow, startColumn, maxMove) % MOD;

        return ans % MOD;
    }
};