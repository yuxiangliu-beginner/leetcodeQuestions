class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        // int temp;
        vector<int> t(code.size(),0); 
//         for(int i = 0; i < code.size();i++)
//         {   
//             if(k==0)
//                 return code;
//             else if(k>0)
//             {
//                 for(int j = 1 ; j<=k; j++)
//                 {
//                     if(i+k>=code.size())
//                         t[i] = code[i+j-code.size()];
//                     else
//                         t[i] = code[i+j];
//                 }
                
//             }else{
//                 for(int j  = k ; j <= 0 ; j++)
//                 {
//                     if(i+j<0)
//                     {
//                         t[i] = code[code.size() + i+j];
//                     }
//                     else
//                         t[i] = code[i+j];
//                 }
                
//             }

//         }
        // if(k == 0)
        //     return code;
        
        if(k!=0)
        {
            int st  = k < 0 ? code.size()+k :1;
            int ed = k < 0 ? code.size()-1:k;
            
            //accumalate : find the sum of accumulate(begin ,end)
            t[0]= accumulate(code.begin()+st,code.begin()+ed+1, 0);
            
            for(int i = 1; i < code.size(); i++)
            {
                ed++;
                ed = ed >= code.size() ? 0 : ed;
                
                t[i] = t[i-1] + code[ed]- code[st];
                st++;
                st = st>=code.size()? 0:st;
            }
            
            
        }
        
        
        return t;
        
    }
};