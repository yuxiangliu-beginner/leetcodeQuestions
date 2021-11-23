class UnionSet{
public:
	UnionSet(int n )
	{
		rank_ = vector<int>(n+1,0);
		parents_ = vector<int>(n+1,0);	
		for(int i =0 ; i <= n;i++)
		{
			parents_[i] = i;
		}
	}
	bool Union(int u,int v){
		int pu = Find(u);
		int pv = Find(v);

		if(pu == pv)
			return false;
		if(rank_[pv] < rank_[pu])
			parents_[pv] = pu;
		else if(rank_[pu]< rank_[pv])
			parents_[pu] = pv;
		else{
			parents_[pv] =pu;
			rank_[pu]++;
		}
		return true;
	}
	int Find(int u)
	{
		if(u!=parents_[u])
			parents_[u] = Find(parents_[u]);
		return parents_[u];
	}
private:
	vector<int> parents_;
	vector<int> rank_;
};


class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = *max_element(nums.begin(),nums.end());
        UnionSet uS(n+1);
        for(auto a :nums)
        {
            for(int k=2 ; k <=sqrt(a);k++)
            {
                if(a%k==0)
                {
                    uS.Union(a,k);
                    uS.Union(a,a/k);
                }
            }
        }
        unordered_map<int,int> mp;
        int ans  = -1;
        for(int i =0 ; i < nums.size(); i++)
        {
            ans = max(ans, ++mp[uS.Find(nums[i])]);
        }
        return ans;
    }
};