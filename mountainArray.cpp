class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
//         if(arr.size()<3)
//             return false;
//         bool flag = true;
// //         for(int i = 1; i <= arr.size()-2; i++)
// //         {
// //             // // cout<<arr[i-1]<<" "<<arr[i]<<" "<<arr[i+1]<<endl;
// //             // if(arr[i-1]< arr[i] && arr[i]> arr[i+1])
// //             //     return true;
// //             if()
            
// //         }
//         int index= 0;
//         flag= false;
//         while(arr[index] < arr[index+1])
//         {
//             cout<<"1 :" << arr[index]<<endl;
//             index++;
//             flag= true;
//         }
//         int max = arr[index];
//         flag= false;
//         while(index <= arr.size()-2 and arr[index]>arr[index+1]  ){
//            cout<<"2 :" << arr[index]<<endl;
//             index++;
//             flag = true;
//         }
//         return flag;
        
        if(arr.size()<3)
            return false;
        
        int pointer=1;
        while(pointer<arr.size())
        {
            if(arr[pointer-1] < arr[pointer])
                pointer++;
            else break;
        }
        
        if(pointer == arr.size() || pointer == 1)
            return false;
        
        while(pointer<arr.size())
        {
            if(arr[pointer-1] > arr[pointer])
                pointer++;
            else 
                break;
        }
        if(pointer == arr.size()) 
            return true;
        else 
            return false;
    }
};