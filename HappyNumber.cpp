class Solution {
public:
    set<int> s;
    bool isHappy(int n) {
        
        if(n==1)
            return true;
        
        // cout<<n<<endl;
        s.insert(n);
 
        
        
        // int orginal = n;
        int sum = 0;
        
        while(n > 0)
        {
            sum+= ((n%10) * (n%10));
            n = n /10;
        }
      
        // for(auto i: s)
        //     cout<<i<<" ";
        // cout<<endl;
        if(s.count(sum)!=0){
            return false;
        }else
            return isHappy(sum);
        
    }
//     bool isHappy(int n, int p)
//     {
//         if(n == 1 )
//             return true;
        
//         if(n == p )
//             return false;
//         if(n <=3)
//             return false;
        
//         int orginal = n;
//         int sum = 0;
//         while(n>0)
//         {
//             sum+= ((n%10) * (n%10));
//             n = n /10;
//         }
//         return isHappy(sum,orginal);

//     }
};