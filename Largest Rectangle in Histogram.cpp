class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> increasingStack;
        if(n == 0)
            return 0;
        increasingStack.push(-1);
        int maxHeight = -1;
        for(int i = 0 ; i < n;i++)
        {
            while(increasingStack.top()!=-1&&heights[increasingStack.top()] >= heights[i])
            {
                int CurrentHeightIndex = increasingStack.top();
                increasingStack.pop();
                int lastIndex =  increasingStack.top();
                maxHeight = max(maxHeight, heights[CurrentHeightIndex] * (i-lastIndex-1));
            }
            increasingStack.push(i);
        }
        while(increasingStack.top()!=-1)
        {
            int CurrentHeightIndex = increasingStack.top();
            increasingStack.pop();
            int lastIndex = increasingStack.top();
            maxHeight = max(maxHeight, heights[CurrentHeightIndex] * (n-lastIndex-1));
        }
        return maxHeight;
    }
};