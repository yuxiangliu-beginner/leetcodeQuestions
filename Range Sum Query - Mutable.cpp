class NumArray {
public:
    vector<int> segTree;
    int size;
    NumArray(vector<int>& nums) {
        size = nums.size();
        segTree.resize(4*size,0);
        
        buildHelper(nums,0,0,size-1);
    }
    
    void update(int index, int val) {
        if(size==0)
            return;
        // cout<<"update "<<size<<endl;
        updateHelper(0,0,size-1,index,val);
        
    }
    
    int sumRange(int left, int right) {
//         int sum =0;
//         for(int i = left;i<=right;i++)
//             sum+=l[i];
        
//         return sum;
        
        
        // for(int i : segTree)
        // {
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        if(size==0)
            return 0;
        return sumHelper(left,right,0,size-1, 0);
    }
private:
    void buildHelper(vector<int>& nums, int pos,int left, int right)
    {
        if(left == right){
            segTree[pos] = nums[left];
            return;
        }
        int mid = (left+right)/2;
        buildHelper(nums,2*pos+1,left,mid);
        buildHelper(nums,2*pos+2,mid+1,right);
        
        segTree[pos] =segTree[2*pos+1] + segTree[2*pos+2]; 
            
        
    }
    void updateHelper(int pos,int left, int right, int index, int val)
    {
        
        // cout<<left<< " "  <<right<<" "<<index<<endl;
       if(index <left || index >right) return;
        
        // cout<<left<< " "  <<right<<" "<<index<<endl;
        
        
        
        // total overlap
        if(left==right){
            if(left==index){
                
                segTree[pos]=val;
            }
            return;
        }
            
                
        int mid=(left+right)/2;
        updateHelper(2*pos+1,left,mid,index,val); // left child
        updateHelper(2*pos+2,mid+1,right,index,val); // right child
        
        segTree[pos] =segTree[2*pos+1] + segTree[2*pos+2]; 
        
    }
    int sumHelper(int givenLow, int givenHigh, int left, int right, int pos)
    {
        if(givenLow<=left &&  givenHigh >= right)
            return segTree[pos];
        if(givenLow>right ||  givenHigh < left)
            return 0;
        
        int mid = left + (right-left)/2;
        return (sumHelper(givenLow,givenHigh,left,mid,2*pos+1) +sumHelper(givenLow,givenHigh,mid+1,right,2*pos+2));
        
    }
    
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */