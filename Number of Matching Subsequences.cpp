class Solution {
public:
    bool isSubSequence(string s ,string word)
    {
        // int index = 0;
        // for(char c :word.toCharArray())
        // {
        //     index = s.indexOf(c,index);
        //     if(index ==-1)
        //         return false;
        //     index++;
        // }
        // return true;
     // //using find
        // int index = 0;
        // for(int i = 0 ; i < word.size(); i++)
        // {
        //     index == s.find(word[i],index);
        //     if(index==string::npos)
        //         return false;
        //     index ++;
        // }
        for(auto w:word)
        {
            if(s.find(w)==string::npos)
            {
                return false;
            }else
            {
                s = s.substr(s.find(w)+1);
            }
        }
        return true;
        
        
        // int j = 0;
        // for(int i = 0 ; i < s.size() and j < word.size();i++)
        // {
        //     if(s[i]==word[j])
        //         j++;
        // }
        // return j==word.size();
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        //brute force
        //create a function isSub, then pass in s and every word into the function to check word is a subsequence of s.
        //TLE
        // int count = 0;
        // for(auto word:words)
        // {
        //     if(isSubSequence(s,word))
        //     {
        //         count++;
        //     }
        // }
        // return count;
        
        //index+binary Search
        vector<vector<int>> alpha(26);
        //map every char to its index
        // abcda:
        // a: 0 4
        // b: 1
        // c: 2
        // d: 3
        for(int i = 0 ;i  < s.size(); i++)
        {
            alpha[s[i]-'a'].push_back(i);
        }
        int count = 0;
        
        
        for(const auto & word:words)
        {
            int x = -1;
            bool found = true;
            for(char c:word)
            {
                auto it = upper_bound(alpha[c-'a'].begin(),alpha[c-'a'].end(),x);
                if(it==alpha[c-'a'].end()){
                    found = false;
                    break;
                    
                }
                  
                else
                {
                     x = *it;
                    cout<<x<<endl;
                }
                  
            }
            if(found)
                count++;
            
            cout<<endl;
        }
        
        return count;
    }
};
//         unordered_map<char,int> map;
//         for(auto c:s)
//             map[c]++;
        
//         int count =0;
//         bool checker =true;
//         for(auto word: words)
//         {
//             // if(s.find(word)!=string::npos){
//             //     cout<<word<<endl;
//             //     count++;
//             // }
//             unordered_map<char,int> temp = map;
//             checker =true;
//             for(auto w: word)
//             {
//                 if(temp.find(w)==temp.end() || temp[w]<=0)
//                 {
//                     checker =false;
//                     continue;
//                 }
//                 temp[w]--;
//             }
//             if(checker)
//             {
//                  cout<<word<<endl;
//                 count++;
//             }

//         }
//         return count;
