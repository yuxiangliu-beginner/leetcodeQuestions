// https://www.geeksforgeeks.org/check-whether-two-numbers-differ-one-bit-position/
// https://leetcode.com/problems/gray-code/discuss/30028/4-lines-C%2B%2B-code.
class Solution {
    
    
public:
    vector<int> grayCode(int n) {
        // get length
        // int len = pow(2,n)-1;
        //generate number;
        
        int len = (1<<n);
        
//         f(i) ^ f(i+1)
//             =  i^(i>>1)^(i+1)^((i+1)>>1) 
//             =  (i^(i+1)) ^ ((i^(i+1)) >> 1).
//         g(i) = i^(i+1)
//         So f(i) ^ f(i+1)  = g(i) ^ g(i)>>1 = 00001000...000.
        
        vector<int> ans(len);
        // ans[0] = 0;
        for(int i = 0 ;i < len; i ++)
        {
            ans[i] = i^(i>>1);
        }
        
        return ans;
    }
    
    // function to check if x is power of 2
    bool isPowerOfTwo(unsigned int x)
    {
        // First x in the below expression is
        // for the case when x is 0
        return x && (!(x & (x - 1)));
    }

    // function to check whether the two numbers
    // differ at one bit position only
    bool differAtOneBitPos(unsigned int a,
                           unsigned int b)
    {
        return isPowerOfTwo(a ^ b);
    }

};