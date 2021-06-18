//math problem
//https://leetcode.com/problems/factorial-trailing-zeroes/discuss/52373/Simple-CC%2B%2B-Solution-(with-detailed-explaination)

//By given number 4617.

// 5^1 : 4617 ÷ 5 = 923.4, so we get 923 factors of 5

// 5^2 : 4617 ÷ 25 = 184.68, so we get 184 additional factors of 5

// 5^3 : 4617 ÷ 125 = 36.936, so we get 36 additional factors of 5

// 5^4 : 4617 ÷ 625 = 7.3872, so we get 7 additional factors of 5

// 5^5 : 4617 ÷ 3125 = 1.47744, so we get 1 more factor of 5

// 5^6 : 4617 ÷ 15625 = 0.295488, which is less than 1, so stop here.

// Then 4617! has 923 + 184 + 36 + 7 + 1 = 1151 trailing zeroes.

class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        for(long long i=5; n/i>0; i*=5){
            result += (n/i);
        }
        return result;
    }
};