class TrieNode
{
public:
    bool isWord;
    vector<TrieNode*> next;
    TrieNode():isWord(false),next(vector<TrieNode*>(26,nullptr)){}
};
class Trie
{
public:
    TrieNode* root;
    Trie()
    {
        root = new TrieNode();
    }
    void insert(string & word)
    {
        TrieNode * cur =root;
        for(int i = word.size()-1;i>= 0 ; i--)
        {
            int pos = word[i]-'a';
            if(cur->next[pos]==nullptr)
                cur->next[pos] = new TrieNode();
            cur= cur->next[pos];
        }
        cur->isWord = true;
    }
    bool find(string & word)
    {
        TrieNode * cur =root;
        for(int i = word.size()-1; i >= 0 ;i--)
        {
            int pos = word[i]-'a';
            cur= cur->next[pos]; 
            if(cur==nullptr)
                return false;
            if(cur->isWord)
                return true;
        }
        return false;
    }
};
class StreamChecker {

public:
    string stream ="";
    Trie trie = Trie();
    size_t maxLen = 0;
    StreamChecker(vector<string>& words) {
        for(auto word:words)
        {
            trie.insert(word);
            maxLen = max(maxLen,words.size());
        }
    }
    
    bool query(char letter) {
        stream+=letter;
        if(stream.size()>maxLen)
        {
            stream.erase(stream.begin());
        }
        return trie.find(stream);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */