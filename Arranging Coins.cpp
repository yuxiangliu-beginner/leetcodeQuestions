class Solution {
public:
    int arrangeCoins(int n) {
        // if(n == 1)
        //     return 1;
        
        int i= 1;
        int rows = 0;
        while(n >=i)
        {
            n-=i;
            i++;
            rows++;
            // cout<<n<<endl;
        }
        return rows;
    }
};