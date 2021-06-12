//1. Add Digits
class Solution {
public:
    int addDigits(int num) {
        if(num <10)
            return num;
        
        int res = num;
        int cur = 0;
        while(res >0)
        {
            cur += (res%10);
            res = res/10;
        }
        return addDigits(cur);
            
    }
};
//2.stonesGame
class Solution {
public:
    int stoneGameVII(vector<int>& S) {
        int N = S.size();
        vector<int> dpCurr(N), dpLast(N);
        for (int i = N - 2; i>=0; i--) {
            int total = S[i];
            dpLast.swap(dpCurr);
            for (int j = i + 1; j < N; j++) {
                total += S[j];
                dpCurr[j] = max(total - S[i] - dpLast[j], total - S[j] - dpCurr[j-1]);
            }
        }
        return dpCurr[N-1];
    }
};