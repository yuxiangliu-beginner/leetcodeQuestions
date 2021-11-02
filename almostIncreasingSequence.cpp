// http://goldentime111.blogspot.com/2018/02/codefights-almostincreasingsequence.html


#include <pstl/execution_defs.h>
bool almostIncreasingSequence(vector<int> sequence) {
        int leftMax = sequence[0];
        int leftMaxIndex = 0 ;
        int removed = 0;
        
        for(int i = 1; i < sequence.size();i++)
        {
            if(sequence[i] <= leftMax)
            {
                if(removed>=1)
                    return false;
                    
                if(leftMaxIndex > 0)
                {
                    if(sequence[i] > sequence[leftMaxIndex - 1])
                    {
                        leftMax = sequence[i];
                        leftMaxIndex =i;
                    }
                }
                else {
                
                    leftMaxIndex = i ;
                    leftMax = sequence[i];
                }
                removed +=1;
            }else {
                leftMaxIndex = i;
                leftMax = sequence[i];
            }
           
        }
     return true;
}
