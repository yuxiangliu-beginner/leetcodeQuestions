// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/discuss/294893/JavaC%2B%2BPython-Two-Pointers-and-Stack-Solution
class Solution {
public:
//                     Time         Memory
//     recursion       572ms       739MB
//     Stack           16ms        10.1MB
//     Two pointer     8ms         9.8MB

    
    
    
    
    
    
    
    
    
    
    
    
    
    // recursion
    // int HasDuplicate(string s)
    // {
    //     for(int i =0 ; i < s.size()-1;i++)
    //     {
    //         if(s[i]==s[i+1])
    //             return i;
    //     }
    //     return -1;
    // }
    // string removeDuplicates(string s) {
    //     if(s.size()==0)
    //         return "";
    //     if(HasDuplicate(s)==-1)
    //         return s;
    //     int pos = HasDuplicate(s);
    //     // cout
    //     string temp = s.substr(0,pos)+ s.substr(pos+2);
    //     return removeDuplicates(temp);
    // }
    
    // stack
//     string removeDuplicates(string s) 
//     {
//        string ans = "";
//         for(auto c : s)
//         {
//             if(ans.size()>0 && ans.back()==c)
//             {
//                 ans.pop_back();
//             }
//             else
//             {
//                 ans.push_back(c);
//             }
//         }
//         return ans;
        
//     }
    //two pointer
    string removeDuplicates(string s) {
        int i =0, n= s.size();
        for(int j = 0 ;j < n; j++,i++)
        {
            s[i]=s[j];
            if(i>0 && s[i] == s[i-1])
                i-=2;
        }
        return s.substr(0,i);
    }
};