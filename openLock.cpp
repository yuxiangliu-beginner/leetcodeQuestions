class Solution {
public:
    
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadSet(deadends.begin(), deadends.end());
        if(deadSet.count("0000"))
            return -1;
        
        queue<string> q({"0000"});
        
        for(int steps = 0; !q.empty(); ++steps)
        {
            
            for(int i = q.size(); i>0; --i)
            {
                string cur = q.front();
                q.pop();
                // cout<<cur<<" neighbor: ";
                if(cur == target)
                    return steps;
                
                for(auto nei:neighbors(cur))
                {
                    // cout<<nei<<" ,  ";
                    if(deadSet.count(nei))
                        continue;
                    deadSet.insert(nei);
                    q.push(nei);
                }
                // cout<<endl;
            }
        }
        return -1;
    }
    
    vector<string> neighbors(const string& cur)
    {
        vector<string> result; 
        for(int i= 0; i < 4; i ++)
        {
            for(int diff = -1; diff<= 1; diff+=2)
            {
                string s = cur;
                s[i] = (s[i]-'0' + diff +10) % 10 +'0';
                result.push_back(s);
            }
        }
        return result;
    }
};


class Solution {
public:
  int replaceDigit(int value, int pos, int repl) {
    int digits[] {value %10, (value/10)%10, (value/100)%10, value/1000};
    digits[pos] = repl;
    return digits[0] + digits[1]*10 + digits[2]*100 + digits[3] * 1000;
  }

  int openLock(std::vector<std::string>& deadends_, std::string target_) {
    std::bitset<10000> deadends {};
    for(auto& deadend : deadends_) {
      auto deadendNum = atoi(deadend.c_str());
      if(deadendNum == 0) {
        return -1;
      }
      deadends.set(deadendNum);
    }

    std::bitset<10000> visited {};
    visited.set(0);
    auto target = atoi(target_.c_str());
    std::queue<int> queue;
    queue.emplace(0);
    int turnCount {};
    int permutationCount {};
    while(!queue.empty()) {
      int size = queue.size();
      //std::cout << "------------------------------------------" << std::endl;
      //std::cout << "turn count - " << turnCount << std::endl;
      //std::cout << "------------------------------------------" << std::endl;
      for(int i=0; i<size; ++i) {
        auto perm = queue.front();
        if(perm == target) {
          return turnCount;
        }
        //std::cout << "from " << perm << " | visiting - [";
        for(int j=0, v = perm; j<4; ++j, v/=10) {
          auto digit = (v %10);
          auto prevDigit = (digit == 0 ? 9 : digit-1);
          auto prevPerm = replaceDigit(perm, j, prevDigit);
          if(!visited.test(prevPerm) && !deadends.test(prevPerm)) {
            //std::cout << prevPerm << ", ";
            queue.emplace(prevPerm);
            visited.set(prevPerm);
          }
          auto nextDigit = (digit == 9 ? 0 : digit+1);
          auto nextPerm = replaceDigit(perm, j, nextDigit);
          if(!visited.test(nextPerm) && !deadends.test(nextPerm)) {
            //std::cout << nextPerm << ", ";
            queue.emplace(nextPerm);
            visited.set(nextPerm);
          }
        }
        //std::cout << "]" << std::endl;
        queue.pop();
      }
      ++turnCount;
    }
    return -1;
  }
};