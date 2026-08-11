class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        int cnt=0;
        int Psum=0;
        for(int i = 0;i<n;i++){
            Psum+=nums[i];
            int remain=Psum-k;
            cnt+=mp[remain];
            mp[Psum]+=1;
        }
        return cnt;
        
    }
};