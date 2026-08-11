class Solution {
public:
    int first(vector<int> &arr,int n,int k){
        int low=0;int high=n-1;int mid;
        int first=-1;
        while(low<=high){
            mid=(low+high)/2;
            if(arr[mid]==k){
                first=mid;
                high=mid-1;
            }
            else if(arr[mid]<k){
                low=mid+1;
            }
            else{high=mid-1;}
        }
        return first;
    }
     int last(vector<int> &arr,int n,int k){
        int low=0;int high=n-1;int mid;
        int last=-1;
        while(low<=high){
            mid=(low+high)/2;
            if(arr[mid]==k){
                last=mid;
                low=mid+1;
            }
            else if(arr[mid]<k){
                low=mid+1;
            }
            else{high=mid-1;}
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int firstocc=first(nums,n,target);
        if(firstocc==-1){
            return {-1,-1};
        }
        else{
            int lastocc= last(nums,n,target);
            return {firstocc,lastocc};
        }
        
    }
};