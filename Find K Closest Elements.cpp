class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0 , right = arr.size()-k;
        while(left<right)
        {
            int mid = (left+right)/2;
            if(x-arr[mid] > arr[mid+k]-x)
            {
                left = mid+1;
            }else
            {
                right =mid;
            }
        }
        return vector<int>(arr.begin()+left, arr.begin()+left+k);
    }
};

// class Solution {
// public:
//     int findClose(vector<int> & arr, int l, int r , int x)
//     {
//         if(l >= r)
//             return l;
        
//         int mid = (l+r)/2;
//         int res;
//         if(arr[mid]==x)
//             return mid; 
//         else if(arr[mid]<x){
//             res= findClose(arr,mid+1, r, x);
//         }else if(arr[mid]>x){
//             res= findClose(arr,l, mid-1, x);
//         }
//         return res;
//     }
//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         int l = 0, r = arr.size()-k;
// vector<int> p = vector<int>(arr.begin(),arr.begin()+r);
//         int close =findClose(p,0,arr.size()-1,x);
//         // cout<<close<<endl;
        
// //         int left= close-1, right = close +1;
//         deque<int> d;
//         d.push_back(arr[close]);
//         k--;
//         int left = close-1;
//         int right = close+1;
//         while(k!=0)
//         {
//             if(left<0)
//             {
//                 d.push_back(arr[right]);
//                 right++;
//                 k--;
//             }else if(right>=arr.size())
//             {
//                 d.push_front(arr[left]);
//                 left -- ;
//                 k--;
//             }
//             else
//             {
//                 //compare condition;
//                 // An integer a is closer to x than an integer b if:
//                 // |a - x| < |b - x|, or
//                 // |a - x| == |b - x| and a < b
//                 int leftP = abs(arr[left]-x);
//                 int rightP = abs(arr[right]-x);
                
//                 if(leftP<=rightP)
//                 {
//                     d.push_front(arr[left]);
//                     left -- ;
//                     k--;
//                 }else if(rightP < leftP)
//                 {
//                     d.push_back(arr[right]);
//                     right++;
//                     k--;
//                 }
//             }
            
    
//         }
        
        
        
        
//         return vector<int>(d.begin(),d.end());
//     }
// };