class Solution {
public:

    bool possible(vector<int>& bloomDay, int day, int m, int k) {

        int cnt = 0;
        int bouquets = 0;

        for(int i = 0; i < bloomDay.size(); i++) {

            if(bloomDay[i] <= day) {
                cnt++;
            }
            else {
                bouquets += cnt / k;
                cnt = 0;
            }
        }

        bouquets += cnt / k;

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        int n = bloomDay.size();

        long long val = 1LL * m * k;

        if(val > n) return -1;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int x : bloomDay) {
            mini = min(mini, x);
            maxi = max(maxi, x);
        }

        int low = mini;
        int high = maxi;
        int ans = maxi;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(possible(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};