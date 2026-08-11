class Solution {
public:
    long long  time(vector<int>& piles,int k){
        int n= piles.size();
        long long totaltime=0;
        for(int i = 0;i<n;i++){
            totaltime+=ceil(double(piles[i])/k);
        }
        return totaltime;
    }

    int findMax(vector<int>& piles){
        int maxp=INT_MIN;
        int n = piles.size();
        for(int i = 0;i<n;i++){
            maxp=max(maxp,piles[i]);
        }
        return maxp;     

    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low= 1; int high=findMax(piles); int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            long long reqtime=time(piles,mid);
            if(reqtime<=h){
                ans=mid;
                high=mid-1;
            }
            else{low=mid+1;}
        }
        return ans;        
    }
};
//