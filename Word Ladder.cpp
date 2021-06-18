class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> todo;
        todo.push(beginWord);
        
        int latter = 1;
        while(!todo.empty())
        {
            int n = todo.size();
            
            for(int i =0 ; i < n; i++)
            {
                string word = todo.front();
                todo.pop();
                if(word==endWord)
                    return latter;
            
            
                dict.erase(word);
                for(int i = 0 ; i < word.size();i++)
                {
                    char c = word[i];
                    for(int j = 0 ;j < 26;j++)
                    {
                        word[i] = (char) 'a'+j;
                        if(dict.find(word)!=dict.end())
                            todo.push(word);
                        
                    }
                    word[i]= c;
                }
            }
            
            latter++;
        }
        return 0;
    }
};