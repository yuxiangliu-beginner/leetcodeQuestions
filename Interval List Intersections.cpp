// https://leetcode.com/problems/interval-list-intersections/discuss/1593667/C%2B%2BPython-Simple-Solution-w-Images-and-Explanation-or-2-Pointers-Merge-Approach
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int i = 0;
        int j = 0;
        while(i < firstList.size() && j < secondList.size())
        {
            if(firstList[i][1]>=secondList[j][0] && firstList[i][0]<=secondList[j][1])
                res.push_back({max(firstList[i][0],secondList[j][0]),min(firstList[i][1],secondList[j][1])});
               
            firstList[i][1] < secondList[j][1] ? i++:j++;
        }
        return res;
    }
};