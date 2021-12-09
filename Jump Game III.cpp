class Solution {
public:
    
    bool dfs(vector<int> & arr, int cur, vector<bool> & isVisited)
    {
    
        if(cur<0|| cur>= arr.size())
            return false;
        
        if(isVisited[cur])
            return false;

        if(arr[cur] == 0)
            return true;
        
        isVisited[cur] = true;
        return dfs(arr,cur+arr[cur],isVisited) || dfs(arr,cur-arr[cur],isVisited);
        
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> isVisited(arr.size(),false);    
        return dfs(arr,start,isVisited);
    }
};