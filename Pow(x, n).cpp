class Solution {
public:
//     double myPow(double x, int n) {
//         double res = 1;
//         while(n)
//         {
//             if(n%2)
//             {
//                 res = n < 0 ? res/x: res*x;
//             }
//             x = x *x;
//             n/=2;
        
//         }
//         return res;
//     }
    
    
    double myPow(double x, int n) {
        if(n == 0 )
            return 1;
        double half = myPow(x,n/2);
        if(n%2)
            return n < 0 ? 1/x*half*half: x*half*half;
        else 
            return half*half;
    }
};