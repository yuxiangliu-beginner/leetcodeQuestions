// MyCalendar 1
class MyCalendar {
public:
    vector<pair<int,int>> map;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto [s,e]: map)
            if(max(s,start)< min(e,end))
                return false;
        map.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

// MyCalendar 2
class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        
        for(const auto& p: doubleBooked)
        {
            if(p.first<end && p.second>start)
                return false;
        }
        
        // By De Morgan's laws, this means the events conflict when s1 < e2 AND s2 < e1.
        for(const auto& p: events)
        {
            if(p.first<end && p.second > start)
            {
                doubleBooked.push_back({max(p.first,start),min(p.second,end)});
            }
        }
        events.push_back({start,end});
        return true;
    }
    vector<pair<int,int>> events;
    vector<pair<int,int>> doubleBooked;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// Intersection of Two Arrays
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        vector<int> res;
        set <int> s;
        set <int> s2;
        for(int i =0 ; i < n;i++)
        {
            s.insert(nums1[i]);
        }
        for(int i: nums2)
        {
            if(s.find(i)!=s.end())
                s2.insert(i);
        }
        for(int s:s2)
            res.push_back(s);
        return res;
    }
};

// Intersection of Two Arrays II
 class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size();
//         int m = nums2.size();
        
//         vector<int> res;
//         unordered_map <int,int> s;
//         unordered_map <int,int> s2;
//         for(int i: nums1)
//         {
//             s[i]++;
//         }
//         for(int i: nums2)
//         {
//             s2[i]++;
//         }
//         for(auto [n,c]:s)
//         {
//             // cout<<"N: "<<n<<" c: " <<c<<endl;
//             if(s2.find(n)!=s2.end()){
//                 cout<<c<<" "<<s2.find(n)->second<<endl;
//                 for(int i = 0 ; i < min(c,s2.find(n)->second);i++)
//                 {
//                     res.push_back(n);
//                 }
                
//             }

            
//         }
//         return res;
        
        
        unordered_map<int,int> mp;
        for(auto & n :nums1)
            mp[n]++;
        nums1.clear();
        for(auto & n : nums2)
            if(mp.find(n)!=mp.end() and mp[n]-- > 0)
                nums1.push_back(n);
        
        return nums1;
    }
};

// 4/10

// valid sudoku
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0 ; i < 9 ; i ++)
        {
            for(int j = 0; j < 9 ; j++)
            {
                if(board[i][j] != '.' && !isValid(board,i,j,board[i][j]))
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>>& board,int row, int col , char num)
    {
        int a = 3*(row/3);
        int b = 3*(col/3);
        
        for(int i = 0 ;i < 9; i ++)
        {
            if(i!=col && board[row][i]==num)
                return false;
            if(i!=row && board[i][col]==num)
                return false;
            if((a + i/3) != row && (b + 1%3) != col && board[a + i/3][b + i%3] == num) 
                return false;
            
        }
        return true;
    }
};
// 5/10
// Search for range
class Solution {
public:
    int getIndex(vector<int>& nums, int target)
    {
        int n = nums.size();
        int ans = n;
        int left = 0, right = n-1;
        
        while(left <=right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid]>=target)
            {
                ans = mid;
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        return ans;
        
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0)
            return {-1,-1};
        int first = getIndex(nums,target);
        int second = getIndex(nums,target+1)-1;
        
        if(first <= second)
            return {first,second};
        else 
            return {-1,-1};
    }
};
// sort color
class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i : nums)
            mp[i]++;
        
        nums.clear();
        for(int i = 0; i < 3; i ++ )
        {
            if(mp.find(i) !=mp.end())
                for(int c= mp.find(i)->second; c > 0;c--)
                {
                    nums.push_back(i);
                }
        }
    }
};
// 8/10
// 3sum
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int len = nums.size();
        if(len < 3)
            return res;
        
        for(int i = 0 ; i < len-2; i++)
        {
          
            if(i == 0 || (i>0 and nums[i] !=nums[i-1]))
            {
               
                int l = i +1, r = len-1;
                while(l<r)
                { 
                    if(nums[l] + nums[r] == (0-nums[i]))
                    {
                        vector<int> vt(3);
                        vt[0] =nums[i];
                        vt[1] =nums[l];
                        vt[2] =nums[r];
                        
                        res.push_back(vt);
                        while(l< r and nums[l]== nums[l+1])
                            l++;
                        while(l<r  and nums[r]== nums[r-1])
                            r--;
                        l++;
                        r--;
                    }else if(nums[l] + nums[r] <(0-nums[i]))
                    {
                        l++;
                    }else{
                        r--;
                    }
                        
                }
            }
        }
        
        return res;
    }
};
// 9/10
// letter combination of phone number
class Solution {
public:
    map<char,string>m;
    vector<string> ans;
    
    void createCombinations(int start,string digits, string current)
    {
        if(start == digits.size())
            ans.push_back(current);
        
        for(int i = 0 ; i < m[digits[start]].length();i++)
        {
            char s = m[digits[start]][i];
            current+= s;
            createCombinations(start+1,digits,current);
            current.pop_back();
        }
        
        
        
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length()<=0) return ans;
        
        m.insert({'2',"abc"});
        m.insert({'3',"def"});
        m.insert({'4',"ghi"});
        m.insert({'5',"jkl"});
        m.insert({'6',"mno"});
        m.insert({'7',"pqrs"});
        m.insert({'8',"tuv"});
        m.insert({'9',"wxyz"});
        
        createCombinations(0,digits,""); //We're starting from indx 0 of digits and currently formed string is ""
        return ans;
    }
};
// 10/10