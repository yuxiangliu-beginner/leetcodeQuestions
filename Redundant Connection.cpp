class UnionSet{
public:
	UnionSet(int n )
	{
        parents_ = vector<int>(n+1);
        rank_ =vector<int>(n+1);
        for(int i =0 ; i < n;i++)
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
        else if(rank_[pu] < rank_[pv])
            parents_[pu] = pv;
        else{
            parents_[pv] = pu;
            rank_[pu] ++;
        }
        return true;
	}
	int Find(int u)
	{
        while (u!=parents_[u])
        {
            u = parents_[u];
        }
        return parents_[u];
	}
private:
	vector<int> parents_;
	vector<int> rank_;
};



class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionSet uS(n+1);
        for(auto edge: edges)
        {
            if(!uS.Union(edge[0],edge[1]))
                return {edge[0],edge[1]};
        }
        return {};
    }
};