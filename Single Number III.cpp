// https://leetcode.com/problems/single-number-iii/discuss/1561827/C%2B%2BPython-5-Simple-Solutions-w-Explanation-or-Brute-Force-%2B-Sort-%2B-Hashmap-%2B-Hashset-%2B-Xor-O(1)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(const int n : nums) mp[n]++;
        for(auto [n, freq] : mp) 
            if(freq == 1) 
			    ans.push_back(n);
        return ans;
    
    }
};