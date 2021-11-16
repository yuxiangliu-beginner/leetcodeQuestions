class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int lo  =0 ;
        int high = m*n;
        while(lo < high)
        {
            int mid =(lo+high)/2; 
            int count = 0;
            for(int i = 1 ; i <= m ; i++ )
            {
                count+= n< (mid/i) ? n : mid/i;
            }
            if(count>=k)
                high = mid;
            else
                lo = mid+1;
        }
        return lo;
    }
};