class Solution {
public:
    bool dfs(vector<int>& length,vector<int>& sticks,int index,int target)
    {
        if(index == sticks.size())
            return length[0]==length[1] and length[1]==length[2] and length[2]==length[3];
        else{
            for(int i = 0 ; i < 4; i++)
            {
                if(length[i] + sticks[index] > target)
                    continue;
                else{
                    int j = i;
                    --j;
                    while(j>=0)
                    {
                        
                        if(length[i] == length[j])
                            break;
                        j--;
                    }
                    if(j!= -1)
                        continue;
                    
                    length[i] += sticks[index];
                    if(dfs(length,sticks,index+1,target))
                        return true;
                    length[i] -= sticks[index];
                }

                
            }
            
        }
        return false;
        
    }
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size() < 4)
            return false;
        vector<int> length(4,0);
        int sum=0;
        for(int a : matchsticks)
            sum+=a;
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        return dfs(length,matchsticks,0,sum/4);
    }
};